#pragma once
#include <M5Unified.h>
#include "key_button.hpp"

struct Layout
{
  std::string icon;
  std::function<void(void)> layout_function;
  key_input_t key;

  Layout(std::string icon, std::function<void(void)> layout_function, key_input_t key)
  {
    this->icon = icon;
    this->layout_function = layout_function;
    this->key = key;
  }
};

extern std::vector<Layout *> layouts;
extern size_t next_layout;

void draw_next_keyboard();
void layout_hiragana_keybard();
void layout_hiragana_modified_keybard();
void layout_roman_kana_keybard();
void layout_roman_modified_keybard();
void layout_alphabet_keybard();
void layout_lower_alphabet_keybard();
void layout_number_keybard();