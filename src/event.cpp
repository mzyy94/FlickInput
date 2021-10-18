#include <esp_event.h>
#include <esp_event_base.h>
#include <freertos/portmacro.h>
#include "event.hpp"

portMUX_TYPE mutex = portMUX_INITIALIZER_UNLOCKED;

ESP_EVENT_DEFINE_BASE(STATUS_CHANGE_EVENT);

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