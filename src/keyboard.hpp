// SPDX-License-Identifier: Apache-2.0

#pragma once
#include <M5Unified.h>
#include "key_button.hpp"
#include "event.hpp"
#include "settings.hpp"

namespace kbd
{
  struct Keyboard
  {
    std::array<struct key_button, 19> key_buttons;
    struct key_button *current_key;

    void set_input_method(input_method_t, keyboard_layout_t, platform_os_t);
    void draw_layout();
    void draw_next_layout();
    void init();
    void draw();
    void input_key_button(direction_t dir, bool draw_text);
    esp_timer_handle_t repeat_key_button();

    void touch_begin(m5::touch_detail_t *t);
    void hold_begin(m5::touch_detail_t *t);
    void touch_end(m5::touch_detail_t *t);
    void flick_end(m5::touch_detail_t *t);

    size_t next_layout_index();

    void input_test();

  private:
    bool need_refresh = false;
    esp_timer_handle_t hold_input = nullptr;
    platform_os_t os;
    size_t layout_index = 0;

    void draw_input_text(std::string text);
  };
}

extern kbd::Keyboard Keyboard;
