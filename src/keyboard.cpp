#include <algorithm>

#include "keyboard.hpp"
#include "key_button.hpp"
#include "ble.hpp"
#include "layout.hpp"

std::array<struct key_button, 19> key_buttons;

void draw_next_keyboard()
{
  const auto layout_func = layouts[next_layout]->layout_function;
  next_layout++;
  if (next_layout >= layouts.size())
  {
    next_layout = 0;
  }
  layout_func();
  draw_keyboard();
}

void init_keyboard_layout()
{
  layouts.clear();
  layouts.push_back(new Layout("あいう", layout_hiragana_keybard, KEY_KANA_INPUT));
  layouts.push_back(new Layout("ABC", layout_alphabet_keybard, KEY_EISU_INPUT));
  layouts.push_back(new Layout("123", layout_number_keybard, KEY_EISU_INPUT));
  next_layout = 0;

  const int32_t x = 10, y = 560, w = 96, h = 78, pad = 10;

  for (size_t j = 0; j < 5; j++)
  {
    for (size_t i = 0; i < 4; i++)
    {
      key_buttons[i * 5 + j].init(x + (w + pad) * j, y + (h + pad) * i, w, (i == 2 && j == 4) ? h * 2 + pad : h, (j == 0 || j == 4) ? TFT_WHITE : TFT_BLACK, (j == 0 || j == 4) ? TFT_DARKGRAY : TFT_LIGHTGRAY);
      if (i == 2 && j == 4)
        return;
    }
  }
}

void draw_keyboard()
{
  M5.Display.startWrite();
  M5.Display.setTextSize(1);
  M5.Display.fillRect(0, 460, M5.Display.width(), 500, TFT_WHITE);
  for (auto &btn : key_buttons)
  {
    btn.draw();
  }

  M5.Display.endWrite();
}

void draw_input_text(std::string text, int x, int y)
{
  M5.Display.startWrite();
  M5.Display.setTextColor(TFT_BLACK, TFT_WHITE);
  M5.Display.setTextSize(2);
  M5.Display.fillRect(x - 270, y - 100, M5.Display.width(), 200, TFT_WHITE);
  M5.Display.drawCenterString(text.c_str(), x, y, &fonts::lgfxJapanGothicP_40);
  M5.Display.endWrite();
}

void input_key_button(struct key_button *key, direction_t dir, bool draw_text)
{
  auto input = key->get_key_input(dir);
  if (input == nullptr)
  {
    return;
  }
  if (draw_text)
  {
    draw_input_text(input->text, 270, 150);
  }
  send_key(input->keycode, input->modifier);
  if (input->second_keycode != 0)
  {
    send_key(input->second_keycode, input->modifier);
  }
  if (input->third_keycode != 0)
  {
    send_key(input->third_keycode, input->modifier);
  }
}

void input_key_button(struct key_button *key)
{
  input_key_button(key, center, false);
}