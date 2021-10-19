#include <M5Unified.h>
#include "event.hpp"

#define check_button_pressed(BTN)                                                                  \
  if (M5.Btn##BTN.wasClicked())                                                                    \
  {                                                                                                \
    esp_event_post_to(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_PRESSED_##BTN, nullptr, 0, 0); \
  }

#define check_button_hold(BTN)                                                                  \
  if (M5.Btn##BTN.wasHold())                                                                    \
  {                                                                                             \
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
