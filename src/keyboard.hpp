#pragma once
#include <M5Unified.h>
#include "key_button.hpp"

enum input_method_t
{
  keyboard_input_method_not_available = 0,
  keyboard_input_method_us_kana,
  keyboard_input_method_us_roman,
};

extern std::array<struct key_button, 19> key_buttons;

input_method_t load_input_method_setting();
void save_input_method_setting(input_method_t input_method);
void set_input_method();
void draw_next_keyboard();
void init_keyboard_layout();
void draw_keyboard();
void input_key_button(struct key_button *key, direction_t dir, bool draw_text);
void input_key_button(struct key_button *key);
