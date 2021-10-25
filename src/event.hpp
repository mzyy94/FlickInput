#pragma once
#include <esp_event.h>
#include <esp_event_base.h>
#include <esp_timer.h>

ESP_EVENT_DECLARE_BASE(STATUS_CHANGE_EVENT);
ESP_EVENT_DECLARE_BASE(BUTTON_PRESS_EVENT);

enum status_event_t
{
  STATUS_EVENT_UPDATE_BLE_STATE,
  STATUS_EVENT_UPDATE_BATTERY_LEVEL,
  STATUS_EVENT_UPDATE_ONLY_REFRESH,
};

enum button_event_t
{
  BUTTON_EVENT_PRESSED_A,
  BUTTON_EVENT_PRESSED_B,
  BUTTON_EVENT_PRESSED_C,
  BUTTON_EVENT_HOLD_A,
  BUTTON_EVENT_HOLD_B,
  BUTTON_EVENT_HOLD_C,
};

extern esp_event_loop_handle_t loop_handle;

void init_event();

template <typename TArg>
esp_timer_handle_t run_timer_task(uint32_t msec, void (*callback)(TArg), TArg arg, bool repeat)
{
  esp_timer_handle_t timer;
  esp_timer_create_args_t timer_config = {
      .callback = reinterpret_cast<esp_timer_cb_t>(callback),
      .arg = reinterpret_cast<void *>(arg),
      .dispatch_method = ESP_TIMER_TASK,
      .name = "run_task",
      .skip_unhandled_events = false,
  };
  esp_timer_create(&timer_config, &timer);
  if (repeat)
    esp_timer_start_periodic(timer, msec * 1000ULL);
  else
    esp_timer_start_once(timer, msec * 1000ULL);
  return timer;
}

template <typename TArg>
esp_timer_handle_t dispatch_after(uint32_t msec, void (*callback)(TArg), TArg arg)
{
  return run_timer_task(msec, callback, arg, false);
}

template <typename TArg>
esp_timer_handle_t dispatch_every(uint32_t msec, void (*callback)(TArg), TArg arg)
{
  return run_timer_task(msec, callback, arg, true);
}

inline void stop_timer(esp_timer_handle_t timer)
{
  esp_timer_stop(timer);
  esp_timer_delete(timer);
}