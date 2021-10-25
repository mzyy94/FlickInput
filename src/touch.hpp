#pragma once
#include <M5Unified.h>
#include "event.hpp"

namespace touch
{
  struct Touch
  {
    m5::touch_state_t prev_state;
    int16_t start_x, start_y;
    bool need_refresh = false;
    esp_timer_handle_t hold_input = nullptr;

    void init();
    void input();
  };
}

extern touch::Touch Touch;