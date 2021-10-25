#pragma once
#include <M5Unified.h>
#include "key_button.hpp"

extern std::array<struct key_button, 19> key_buttons;

void draw_next_keyboard();
void init_keyboard_layout();
void draw_keyboard();
void input_key_button(struct key_button *key, direction_t dir, bool draw_text);
void input_key_button(struct key_button *key);
