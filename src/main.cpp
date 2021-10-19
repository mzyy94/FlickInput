#include <M5Unified.h>
#include "nvs_flash.h"

#include "keyboard.hpp"
#include "touch.hpp"
#include "ble.hpp"
#include "display.hpp"
#include "menu.hpp"
#include "event.hpp"
#include "button.hpp"

void init_m5paper()
{
  M5.begin();
  M5.Display.setEpdMode(epd_mode_t::epd_fast);

  auto ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
  {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);
}

void open_menu(void *event_handler_arg,
               esp_event_base_t event_base,
               int32_t event_id,
               void *event_data)
{
  unregister_button_pressed(B, open_menu);
  Menu.openMenu();
}

void register_menu_button_event()
{
  register_button_pressed(B, open_menu, nullptr);
}

void register_status_update()
{
  esp_event_handler_register_with(
      loop_handle, STATUS_CHANGE_EVENT, ESP_EVENT_ANY_ID, draw_header, nullptr);
}

void init_menu()
{
  Menu.addItem("シャットダウン", []
               {
                 portENTER_CRITICAL_ISR(&mutex);
                 M5.Display.clearDisplay(TFT_WHITE);
                 draw_logo(true);
                 portEXIT_CRITICAL_ISR(&mutex);
                 M5.Power.powerOff();
               });
  Menu.addItem("閉じる", []
               {
                 Menu.closeMenu();
                 portENTER_CRITICAL_ISR(&mutex);
                 M5.Display.clearDisplay(TFT_WHITE);
                 draw_hiragana_keybard();
                 portEXIT_CRITICAL_ISR(&mutex);
                 esp_event_post_to(loop_handle, STATUS_CHANGE_EVENT, STATUS_EVENT_UPDATE_NO_REASON, nullptr, 0, 0);
                 register_menu_button_event();
               });
}

void register_events()
{
  register_menu_button_event();
  register_status_update();
}

void main_task(void *)
{
  init_m5paper();
  M5.Display.clearDisplay(TFT_WHITE);

  init_keyboard_layout();
  draw_hiragana_keybard();

  init_event();
  init_touch();
  init_ble_hid();
  init_menu();

  register_events();

  draw_logo();

  uint64_t count = 0;
  for (;;)
  {
    vTaskDelay(20 / portTICK_RATE_MS);

    M5.update();

    if (count % 30000 == 0)
    {
      auto bat = M5.Power.getBatteryLevel();
      esp_event_post_to(loop_handle, STATUS_CHANGE_EVENT, STATUS_EVENT_UPDATE_BATTERY_LEVEL, &bat, sizeof(bat), 0);
      count = 0;
    }
    count++;

    update_button_event();
    if (Menu.opened)
    {
      continue;
    }

    touch_input();

    if (M5.BtnB.wasHold())
    {
      count = 0;
      M5.Display.clearDisplay(TFT_WHITE);
      draw_keyboard();
    }
    if (M5.BtnA.wasClicked())
    {
      send_key(HID_KEY_UP_ARROW, 0);
    }
    if (M5.BtnC.wasClicked())
    {
      send_key(HID_KEY_DOWN_ARROW, 0);
    }
  }
  vTaskDelete(nullptr);
}

extern "C"
{
  void app_main()
  {
    xTaskCreatePinnedToCore(main_task, "main_task", 8192, nullptr, 1, nullptr, 1);
  }
}
