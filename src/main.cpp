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
  switch (Settings.input_method())
  {
  case input_method_default:
  case input_method_kana:
    Settings.input_method(input_method_roman);
    Menu.editItemLabel(0, "入力方法: ローマ字");
    break;
  case input_method_roman:
    Settings.input_method(input_method_kana);
    Menu.editItemLabel(0, "入力方法: かな");
    break;
  }
  Keyboard.set_input_method(Settings.input_method(), Settings.keyboard_layout(), Settings.platform_os());
}

void change_keyboard_layout()
{
  switch (Settings.keyboard_layout())
  {
  case keyboard_layout_default:
  case keyboard_layout_jis:
    Settings.keyboard_layout(keyboard_layout_us);
    Menu.editItemLabel(1, "レイアウト: US配列");
    break;
  case keyboard_layout_us:
    Settings.keyboard_layout(keyboard_layout_jis);
    Menu.editItemLabel(1, "レイアウト: 日本語配列");
    break;
  }
  Keyboard.set_input_method(Settings.input_method(), Settings.keyboard_layout(), Settings.platform_os());
}

void change_platform_os()
{
  switch (Settings.platform_os())
  {
  case platform_os_default:
  case platform_os_win:
    Settings.platform_os(platform_os_mac);
    Menu.editItemLabel(2, "OS: Mac");
    break;
  case platform_os_mac:
    Settings.platform_os(platform_os_win);
    Menu.editItemLabel(2, "OS: Windows");
    break;
  }
  Keyboard.set_input_method(Settings.input_method(), Settings.keyboard_layout(), Settings.platform_os());
}

void refresh_display()
{
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

#if ENABLE_INPUT_TEST_MODE
#include <algorithm>
#include "layout.hpp"

void input_test()
{
  for (size_t i = 0; i < 19; i++)
  {
    auto btn = Keyboard.key_buttons[i];
    if (btn.repeat || btn.keys.size() == 0)
    {
      continue;
    }
    if (btn.keys[0].keycode == HID_KEY_LANG1 || btn.keys[0].keycode == HID_KEY_LANG2)
    {
      continue;
    }

    for (auto &key : btn.keys)
    {
      if (key.keycode == HID_KEY_ESCAPE)
      {
        continue;
      }
      send_key(key.keycode, key.modifier);
      if (key.second_keycode != 0)
      {
        send_key(key.second_keycode, 0);
      }
      if (key.third_keycode != 0)
      {
        send_key(key.third_keycode, 0);
      }
      vTaskDelay(20 / portTICK_RATE_MS);
    }
  }
}
#endif

void init_menu()
{
  switch (Settings.input_method())
  {
  case input_method_default:
  case input_method_kana:
    Menu.addItem("入力方法: かな", change_input_method);
    break;
  case input_method_roman:
    Menu.addItem("入力方法: ローマ字", change_input_method);
    break;
  }

  switch (Settings.keyboard_layout())
  {
  case keyboard_layout_default:
  case keyboard_layout_jis:
    Menu.addItem("レイアウト: 日本語配列", change_keyboard_layout);
    break;
  case keyboard_layout_us:
    Menu.addItem("レイアウト: US配列", change_keyboard_layout);
    break;
  }

  switch (Settings.platform_os())
  {
  case platform_os_default:
  case platform_os_win:
    Menu.addItem("OS: Windows", change_platform_os);
    break;
  case platform_os_mac:
    Menu.addItem("OS: Mac", change_platform_os);
    break;
  }

#if ENABLE_INPUT_TEST_MODE
  Menu.addItem("START INPUT TEST", input_test);
#endif

  Menu.addItem("シャットダウン", shutdown);
  Menu.addItem("閉じる", refresh_display);
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
  init_m5paper();
  init_nvs();

  // 1. Initialize event loop
  init_event();
  register_events();

  // 2. Load settings and init menu
  Settings.load();
  init_menu();

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
