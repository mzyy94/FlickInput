#include <M5Unified.h>
#include "event.hpp"

void update_button_event()
{
  if (M5.BtnA.wasClicked())
  {
    esp_event_post_to(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_PRESSED_A, NULL, 0, portTICK_RATE_MS);
  }
  if (M5.BtnB.wasClicked())
  {
    esp_event_post_to(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_PRESSED_B, NULL, 0, portTICK_RATE_MS);
  }
  if (M5.BtnC.wasClicked())
  {
    esp_event_post_to(loop_handle, BUTTON_PRESS_EVENT, BUTTON_EVENT_PRESSED_C, NULL, 0, portTICK_RATE_MS);
  }
}
