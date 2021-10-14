#pragma once
#include <M5Unified.h>
#include "key_button.hpp"

extern std::array<struct key_button, 19> key_buttons;

void draw_hiragana_keybard();
void draw_alphabet_keybard();
void draw_lower_alphabet_keybard();
void draw_number_keybard();
void init_keyboard_layout();
void draw_keyboard();
void input_key_button(struct key_button *key, direction_t dir);
