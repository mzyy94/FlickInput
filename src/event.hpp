#pragma once
#include <esp_event.h>
#include <esp_event_base.h>

ESP_EVENT_DECLARE_BASE(STATUS_CHANGE_EVENT);
enum status_event_t
{
  STATUS_EVENT_UPDATE_BLE_STATE,
  STATUS_EVENT_UPDATE_BATTERY_LEVEL,
  STATUS_EVENT_UPDATE_NO_REASON,
};

extern esp_event_loop_handle_t loop_handle;

void init_event();