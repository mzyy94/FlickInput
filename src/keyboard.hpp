#pragma once
#include <M5Unified.h>
#include "key_button.hpp"

extern struct key_button key_buttons[20];

void set_alphabet_keybard();
void init_keyboard_layout();
void draw_keyboard();
