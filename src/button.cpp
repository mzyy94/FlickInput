#include <M5Unified.h>
#include <esp_log.h>
#include "event.hpp"

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

void update_button_event()
{
  check_button_pressed(A);
  check_button_pressed(B);
  check_button_pressed(C);
  check_button_hold(A);
  check_button_hold(B);
  check_button_hold(C);
}
