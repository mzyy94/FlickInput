#include <esp_event.h>
#include <esp_event_base.h>
#include <esp_timer.h>
#include <freertos/portmacro.h>
#include "event.hpp"

portMUX_TYPE mutex = portMUX_INITIALIZER_UNLOCKED;

ESP_EVENT_DEFINE_BASE(STATUS_CHANGE_EVENT);
ESP_EVENT_DEFINE_BASE(BUTTON_PRESS_EVENT);

esp_event_loop_handle_t loop_handle;

void init_event()
{
  esp_event_loop_args_t loop_args = {
      .queue_size = 16,
      .task_name = "event_task",
      .task_priority = 1,
      .task_stack_size = 4096,
      .task_core_id = 0,
  };
  esp_event_loop_create(&loop_args, &loop_handle);
}

void dispatch_after(uint32_t msec, void (*callback)(void *), void *arg)
{
  esp_timer_handle_t timer;
  esp_timer_create_args_t timer_config = {
      .callback = callback,
      .arg = arg,
      .dispatch_method = ESP_TIMER_TASK,
      .name = "run_task",
      .skip_unhandled_events = false,
  };
  esp_timer_create(&timer_config, &timer);
  esp_timer_start_once(timer, msec * 1000ULL);
}