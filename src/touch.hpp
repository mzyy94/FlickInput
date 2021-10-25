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

  private:
    void touch_begin(int16_t x, int16_t y);
    void hold_begin(int16_t x, int16_t y);
    void touch_end(int16_t x, int16_t y);
    void flick_end(int16_t x, int16_t y);
  };
}

extern touch::Touch Touch;