// SPDX-License-Identifier: Apache-2.0

#include <M5Unified.h>
#include <esp_log.h>
#include <nvs_flash.h>

#include "keyboard.hpp"
#include "ble.hpp"
#include "display.hpp"
#include "menu.hpp"
#include "event.hpp"
#include "settings.hpp"

#define MAIN_TAG "MAIN"

settings::Settings Settings;
bool needs_restart = false;

void init_display()
{
  M5.Display.setEpdMode(epd_mode_t::epd_fast);
  if (Settings.device_orientation() == device_orientation_upside_down)
  {
    M5.Display.setRotation(2);
  }
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

void register_side_button_events();
void unregister_side_button_events();
void register_touch_void_events();
void unregister_touch_events();

void open_menu_handler(void *, esp_event_base_t, int32_t, void *)
{
  unregister_side_button_events();
  unregister_touch_events();
  register_touch_void_events();
  Menu.open();
}

void send_cursor_key_handler(void *, esp_event_base_t, int32_t event_id, void *)
{
  ESP_LOGD(MAIN_TAG, "send_cursor_key_handler called: %d", event_id);
  const auto upside_down = (M5.Display.getRotation() == 2);
  switch (event_id)
  {
  case BUTTON_EVENT_PRESSED_A:
    return send_key(upside_down ? HID_KEY_DOWN_ARROW : HID_KEY_UP_ARROW, 0);
  case BUTTON_EVENT_PRESSED_B:
    return send_key(HID_KEY_RETURN, 0);
  case BUTTON_EVENT_PRESSED_C:
    return send_key(upside_down ? HID_KEY_UP_ARROW : HID_KEY_DOWN_ARROW, 0);
  }
}

void touch_event_handler(void *, esp_event_base_t, int32_t event_id, void *event_data)
{
  ESP_LOGD(MAIN_TAG, "touch_event_handler called: %d", event_id);
  auto t = reinterpret_cast<m5::touch_detail_t *>(event_data);
  switch (event_id)
  {
  case TOUCH_EVENT_TOUCH_BEGIN:
    return Keyboard.touch_begin(t);
  case TOUCH_EVENT_TOUCH_END:
    return Keyboard.touch_end(t);
  case TOUCH_EVENT_HOLD_BEGIN:
    return Keyboard.hold_begin(t);
  case TOUCH_EVENT_FLICK_END:
    return Keyboard.flick_end(t);
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

void register_touch_events()
{
  register_touch_begin(touch_event_handler, nullptr);
  register_touch_end(touch_event_handler, nullptr);
  register_hold_begin(touch_event_handler, nullptr);
  register_flick_end(touch_event_handler, nullptr);
  ESP_LOGI(MAIN_TAG, "Touch events registered");
}

void unregister_touch_events()
{
  unregister_touch_begin(touch_event_handler);
  unregister_touch_end(touch_event_handler);
  unregister_hold_begin(touch_event_handler);
  unregister_flick_end(touch_event_handler);
  ESP_LOGI(MAIN_TAG, "Touch events unregistered");
}

void void_event_callback(void *, esp_event_base_t, int32_t, void *) {}

void register_touch_void_events()
{
  register_touch_all(void_event_callback, nullptr);
  ESP_LOGI(MAIN_TAG, "Touch void events registered");
}

void unregister_touch_void_events()
{
  unregister_touch_all(void_event_callback);
  ESP_LOGI(MAIN_TAG, "Touch void events unregistered");
}

void register_status_update()
{
  esp_event_handler_register_with(
      loop_handle, STATUS_CHANGE_EVENT, ESP_EVENT_ANY_ID, draw_statusbar, nullptr);
}

void shutdown()
{
  M5.Display.startWrite();
  M5.Display.clearDisplay(TFT_WHITE);
  draw_statusbar();
  draw_logo(true);
  Keyboard.draw();
  M5.Display.endWrite();
  ESP_LOGI(MAIN_TAG, "Shutting down...");
  M5.Power.powerOff();
}

void change_input_method()
{
  Settings.input_method(Settings.input_method() == input_method_kana ? input_method_roman : input_method_kana);
  Menu.editItemLabel(0, Settings.input_method_label());
  Keyboard.set_input_method(Settings.input_method(), Settings.keyboard_layout(), Settings.platform_os());
}

void change_keyboard_layout()
{
  Settings.keyboard_layout(Settings.keyboard_layout() == keyboard_layout_jis ? keyboard_layout_us : keyboard_layout_jis);
  Menu.editItemLabel(1, Settings.keyboard_layout_label());
  Keyboard.set_input_method(Settings.input_method(), Settings.keyboard_layout(), Settings.platform_os());
}

void change_platform_os()
{
  Settings.platform_os(Settings.platform_os() == platform_os_win ? platform_os_mac : platform_os_win);
  Menu.editItemLabel(2, Settings.platform_os_label());
  Keyboard.set_input_method(Settings.input_method(), Settings.keyboard_layout(), Settings.platform_os());
}

void change_device_orientation()
{
  Settings.device_orientation(Settings.device_orientation() == device_orientation_normal ? device_orientation_upside_down : device_orientation_normal);
  Menu.editItemLabel(3, Settings.device_orientation_label());
  needs_restart = !needs_restart;
}

#if ENABLE_INPUT_TEST_MODE
void input_test()
{
  Keyboard.input_test();
}
#endif

void close_menu()
{
  if (needs_restart)
  {
    esp_restart();
    return;
  }
  if (Menu.opened)
  {
    Menu.close();
    register_side_button_events();
    unregister_touch_void_events();
    register_touch_events();
  }
  Keyboard.draw_layout();
  xEventGroupSetBits(event_group, EVENT_BIT_CLEAR_DISPLAY | EVENT_BIT_DRAW_STATUSBAR | EVENT_BIT_DRAW_KEYBOARD);
  ESP_LOGI(MAIN_TAG, "Display refresh");
}

void init_menu()
{
  Menu.addItem(Settings.input_method_label(), change_input_method);
  Menu.addItem(Settings.keyboard_layout_label(), change_keyboard_layout);
  Menu.addItem(Settings.platform_os_label(), change_platform_os);
  Menu.addItem(Settings.device_orientation_label(), change_device_orientation);

#if ENABLE_INPUT_TEST_MODE
  Menu.addItem("START INPUT TEST", input_test);
#endif

  Menu.addItem("シャットダウン", shutdown);
  Menu.addItem("閉じる", close_menu);
}

void register_events()
{
  register_side_button_events();
  register_status_update();
  register_touch_events();
}

void update_battery_status(void * = nullptr)
{
  auto bat = M5.Power.getBatteryLevel();
  esp_event_post_to(loop_handle, STATUS_CHANGE_EVENT, STATUS_EVENT_UPDATE_BATTERY_LEVEL, &bat, sizeof(bat), 0);
  ESP_LOGI(MAIN_TAG, "Battery status updated = %d%%", bat);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_STATUSBAR);
}

void main_task(void *)
{
  // 0. Initialize device
  M5.begin();
  init_nvs();

  // 1. Initialize event loop
  init_event();
  register_events();

  // 2. Load settings and init menu & display
  Settings.load();
  init_menu();
  init_display();

  // 3. Init keyboard and apply settings
  Keyboard.init();
  Keyboard.set_input_method(Settings.input_method(), Settings.keyboard_layout(), Settings.platform_os());

  // 4. Draw logo, keyboard and status bar
  xEventGroupSetBits(event_group, EVENT_BIT_CLEAR_DISPLAY | EVENT_BIT_DRAW_LOGO | EVENT_BIT_DRAW_STATUSBAR);
  Keyboard.draw_layout();

  // 5. Set battery status update interval loop
  update_battery_status();
  dispatch_every(3 * 60 * 1000, update_battery_status, (void *)nullptr);

  // 6. Start ble connection
  start_ble_hid();

  for (;;)
  {
    vTaskDelay(20 / portTICK_RATE_MS);

    M5.update();
    update_device_event();
    update_display();
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
