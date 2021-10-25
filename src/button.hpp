#pragma once
#include <esp_event.h>
#include <esp_log.h>
#include "event.hpp"

#define register_button_pressed(BTN, callback, arg) esp_event_handler_register_with(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_PRESSED_##BTN, callback, arg)
#define unregister_button_pressed(BTN, callback) esp_event_handler_unregister_with(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_PRESSED_##BTN, callback)
#define register_button_hold(BTN, callback, arg) esp_event_handler_register_with(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_HOLD_##BTN, callback, arg)
#define unregister_button_hold(BTN, callback) esp_event_handler_unregister_with(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_HOLD_##BTN, callback)

#define BUTTON_TAG "BUTTON"

#define check_button_pressed(BTN)                                                                  \
  if (M5.Btn##BTN.wasClicked())                                                                    \
  {                                                                                                \
    ESP_LOGI(BUTTON_TAG, "Button " #BTN " pressed");                                               \
    esp_event_post_to(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_PRESSED_##BTN, nullptr, 0, 0); \
  }

#define check_button_hold(BTN)                                                                  \
  if (M5.Btn##BTN.wasHold())                                                                    \
  {                                                                                             \
    ESP_LOGI(BUTTON_TAG, "Button " #BTN " hold");                                               \
    esp_event_post_to(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_HOLD_##BTN, nullptr, 0, 0); \
  }

inline void update_button_event()
{
  check_button_pressed(A);
  check_button_pressed(B);
  check_button_pressed(C);
  check_button_hold(A);
  check_button_hold(B);
  check_button_hold(C);
}
