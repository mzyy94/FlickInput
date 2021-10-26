#include <M5Unified.h>
#include <esp_log.h>
#include <nvs_flash.h>

#include "keyboard.hpp"
#include "touch.hpp"
#include "ble.hpp"
#include "display.hpp"
#include "menu.hpp"
#include "event.hpp"

#define MAIN_TAG "MAIN"

void init_m5paper()
{
  M5.begin();
  M5.Display.setEpdMode(epd_mode_t::epd_fast);
}

void init_nvs()
{
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
void draw_status_bar(bool);

void open_menu_handler(void *, esp_event_base_t, int32_t, void *)
{
  unregister_side_button_events();
  Menu.open();
}

void send_cursor_key_handler(void *, esp_event_base_t, int32_t event_id, void *)
{
  switch (event_id)
  {
  case BUTTON_EVENT_PRESSED_A:
    return send_key(HID_KEY_UP_ARROW, 0);
  case BUTTON_EVENT_PRESSED_B:
    return send_key(HID_KEY_RETURN, 0);
  case BUTTON_EVENT_PRESSED_C:
    return send_key(HID_KEY_DOWN_ARROW, 0);
  }
}

void register_side_button_events()
{
  register_button_pressed(A, send_cursor_key_handler, nullptr);
  register_button_pressed(B, send_cursor_key_handler, nullptr);
  register_button_pressed(C, send_cursor_key_handler, nullptr);
  register_button_hold(B, open_menu_handler, nullptr);
  ESP_LOGI(MAIN_TAG, "Side button events registered");
}

void unregister_side_button_events()
{
  unregister_button_pressed(A, send_cursor_key_handler);
  unregister_button_pressed(B, send_cursor_key_handler);
  unregister_button_pressed(C, send_cursor_key_handler);
  unregister_button_hold(B, open_menu_handler);
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
  vTaskDelay(500 / portTICK_RATE_MS);
  M5.Power.powerOff();
}

void change_input_method()
{
  Menu.close();
  input_method_t input_method = Keyboard.load_input_method_setting();

  switch (input_method)
  {
  case keyboard_input_method_not_available:
  case keyboard_input_method_us_kana:
    Keyboard.save_input_method_setting(keyboard_input_method_us_roman);
    Menu.editItemLabel(0, "入力方法: USローマ字");
    break;
  case keyboard_input_method_us_roman:
    Keyboard.save_input_method_setting(keyboard_input_method_us_kana);
    Menu.editItemLabel(0, "入力方法: USかな");
    break;
  }
  Keyboard.set_input_method();
  Menu.open();
}

void refresh_display()
{
  if (Menu.opened)
  {
    Menu.close();
    register_side_button_events();
  }
  M5.Display.clearDisplay(TFT_WHITE);
  Keyboard.draw();
  draw_status_bar(false);
  ESP_LOGI(MAIN_TAG, "Display refreshed");
}

void init_menu()
{
  input_method_t input_method = Keyboard.load_input_method_setting();

  switch (input_method)
  {
  case keyboard_input_method_not_available:
  case keyboard_input_method_us_kana:
    Menu.addItem("入力方法: USかな", change_input_method);
    break;
  case keyboard_input_method_us_roman:
    Menu.addItem("入力方法: USローマ字", change_input_method);
    break;
  }

  Menu.addItem("シャットダウン", shutdown);
  Menu.addItem("閉じる", refresh_display);
}

void register_events()
{
  register_side_button_events();
  register_status_update();
}

void draw_status_bar(bool update_battery)
{
  if (update_battery)
  {
    auto bat = M5.Power.getBatteryLevel();
    esp_event_post_to(loop_handle, STATUS_CHANGE_EVENT, STATUS_EVENT_UPDATE_BATTERY_LEVEL, &bat, sizeof(bat), 0);
    ESP_LOGI(MAIN_TAG, "Battery status updated = %d%%", bat);
  }
  else
  {
    esp_event_post_to(loop_handle, STATUS_CHANGE_EVENT, STATUS_EVENT_UPDATE_ONLY_REFRESH, nullptr, 0, 0);
  }
}

void main_task(void *)
{
  // 0. Initialize device
  init_m5paper();
  init_nvs();

  // 1. Initialize event loop
  init_event();
  register_events();

  // 2. Initialize instances
  Keyboard.init();
  Touch.init();
  init_menu();

  // 3. Draw logo, keyboard and status bar
  draw_logo();
  Keyboard.draw_next_layout();
  draw_status_bar(true);

  // 4. Set battery status update interval loop
  dispatch_every(3 * 60 * 1000, draw_status_bar, true);

  // 5. Start ble connection
  start_ble_hid();

  for (;;)
  {
    vTaskDelay(20 / portTICK_RATE_MS);

    M5.update();
    update_button_event();

    if (!Menu.opened)
    {
      Touch.input();
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
