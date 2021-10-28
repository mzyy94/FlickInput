// SPDX-License-Identifier: Apache-2.0

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

void layout_jis_kana_keybard();
void layout_jis_kana_mod_keybard();
void layout_us_kana_keybard();
void layout_us_kana_mod_keybard();
void layout_roman_kana_keybard();
void layout_roman_modified_keybard();
void layout_us_alphabet_keybard();
void layout_us_lower_alphabet_keybard();
void layout_jis_alphabet_keybard();
void layout_jis_lower_alphabet_keybard();
void layout_number_keybard();