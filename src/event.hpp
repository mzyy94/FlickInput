#pragma once
#include <esp_event.h>
#include <esp_event_base.h>
#include <freertos/portmacro.h>

extern portMUX_TYPE mutex;

ESP_EVENT_DECLARE_BASE(STATUS_CHANGE_EVENT);
ESP_EVENT_DECLARE_BASE(BUTTON_PRESS_EVENT);

enum status_event_t
{
  STATUS_EVENT_UPDATE_BLE_STATE,
  STATUS_EVENT_UPDATE_BATTERY_LEVEL,
  STATUS_EVENT_UPDATE_NO_REASON,
};

enum button_event_t
{
  BUTTON_EVENT_PRESSED_A,
  BUTTON_EVENT_PRESSED_B,
  BUTTON_EVENT_PRESSED_C,
};

extern esp_event_loop_handle_t loop_handle;

void init_event();
void dispatch_after(uint32_t msec, void (*callback)(void *), void *arg);