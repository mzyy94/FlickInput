#pragma once
#include <M5Unified.h>
#include "event.hpp"

namespace touch
{
  struct Touch
  {
    m5::touch_state_t prev_state;
    bool need_refresh = false;
    esp_timer_handle_t hold_input = nullptr;

    void init();
    void input();

  private:
    void touch_begin(m5::touch_detail_t t);
    void hold_begin(m5::touch_detail_t t);
    void touch_end(m5::touch_detail_t t);
    void flick_end(m5::touch_detail_t t);
  };
}

extern touch::Touch Touch;