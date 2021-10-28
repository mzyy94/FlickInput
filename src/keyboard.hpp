#pragma once
#include <M5Unified.h>
#include "key_button.hpp"
#include "event.hpp"

enum input_method_t
{
  keyboard_input_method_not_available = 0,
  keyboard_input_method_jis_kana,
  keyboard_input_method_us_kana,
  keyboard_input_method_us_roman,
};

namespace kbd
{
  struct Keyboard
  {
    std::array<struct key_button, 19> key_buttons;
    struct key_button *current_key;

    input_method_t load_input_method_setting();
    void save_input_method_setting(input_method_t input_method);
    void set_input_method();
    void draw_next_layout();
    void init();
    void draw();
    void input_key_button(direction_t dir, bool draw_text);
    esp_timer_handle_t repeat_key_button();

    void touch_begin(m5::touch_detail_t *t);
    void hold_begin(m5::touch_detail_t *t);
    void touch_end(m5::touch_detail_t *t);
    void flick_end(m5::touch_detail_t *t);

  private:
    bool need_refresh = false;
    esp_timer_handle_t hold_input = nullptr;

    void draw_input_text(std::string text);
  };
}

extern kbd::Keyboard Keyboard;
