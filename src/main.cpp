#include <M5Unified.h>
#include <esp_log.h>
#include <nvs_flash.h>

#include "keyboard.hpp"
#include "touch.hpp"
#include "ble.hpp"
#include "display.hpp"
#include "menu.hpp"
#include "event.hpp"
#include "button.hpp"

#define MAIN_TAG "MAIN"

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

void refresh_display();
void register_side_button_events();
void unregister_side_button_events();
void update_battery_status(void *);

void open_menu_handler(void *, esp_event_base_t, int32_t, void *)
{
  unregister_side_button_events();
  Menu.openMenu();
}

void send_cursor_key_handler(void *, esp_event_base_t, int32_t event_id, void *)
{
  send_key(event_id == BUTTON_EVENT_PRESSED_A ? HID_KEY_UP_ARROW : HID_KEY_DOWN_ARROW, 0);
}

void display_refresh_handler(void *, esp_event_base_t, int32_t, void *)
{
  refresh_display();
}

void register_side_button_events()
{
  register_button_pressed(B, open_menu_handler, nullptr);
  register_button_pressed(A, send_cursor_key_handler, nullptr);
  register_button_pressed(C, send_cursor_key_handler, nullptr);
  register_button_hold(B, display_refresh_handler, nullptr);
  ESP_LOGI(MAIN_TAG, "Side button events registered");
}

void unregister_side_button_events()
{
  unregister_button_pressed(B, open_menu_handler);
  unregister_button_pressed(A, send_cursor_key_handler);
  unregister_button_pressed(C, send_cursor_key_handler);
  unregister_button_hold(B, display_refresh_handler);
  ESP_LOGI(MAIN_TAG, "Side button events unregistered");
}

void register_status_update()
{
  esp_event_handler_register_with(
      loop_handle, STATUS_CHANGE_EVENT, ESP_EVENT_ANY_ID, draw_header, nullptr);
}

void shutdown()
{
  draw_logo(true);
  ESP_LOGI(MAIN_TAG, "Shutting down...");
  M5.Power.powerOff();
}

void refresh_display()
{
  if (Menu.opened)
  {
    Menu.closeMenu();
    register_side_button_events();
  }
  M5.Display.clearDisplay(TFT_WHITE);
  draw_keyboard();
  update_battery_status(nullptr);
  ESP_LOGI(MAIN_TAG, "Display refreshed");
}

void init_menu()
{
  Menu.addItem("シャットダウン", shutdown);
  Menu.addItem("閉じる", refresh_display);
}

void register_events()
{
  register_side_button_events();
  register_status_update();
}

void update_battery_status(void *)
{
  auto bat = M5.Power.getBatteryLevel();
  esp_event_post_to(loop_handle, STATUS_CHANGE_EVENT, STATUS_EVENT_UPDATE_BATTERY_LEVEL, &bat, sizeof(bat), 0);
  ESP_LOGI(MAIN_TAG, "Battery status updated = %d%%", bat);
}

void main_task(void *)
{
  init_m5paper();
  init_keyboard_layout();
  init_event();
  init_touch();
  init_ble_hid();
  init_menu();

  register_events();

  draw_logo();
  draw_hiragana_keybard();
  update_battery_status(nullptr);

  dispatch_every<void *>(10 * 60 * 1000, update_battery_status, nullptr);

  for (;;)
  {
    vTaskDelay(20 / portTICK_RATE_MS);

    M5.update();

    update_button_event();
    if (Menu.opened)
    {
      continue;
    }

    touch_input();
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
