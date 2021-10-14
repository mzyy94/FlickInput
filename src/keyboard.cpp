#include <algorithm>

#include "keyboard.hpp"
#include "key_button.hpp"
#include "ble.hpp"

std::array<struct key_button, 19> key_buttons;

void set_alphabet_keybard()
{
  size_t i = 0;
  key_buttons[i++].set_keys("→", KEY_RightArrow);
  key_buttons[i++].set_keys("@#/&_", KEY_atmark, KEY_number_sign, KEY_slash, KEY_ampersand, KEY_underscore);
  key_buttons[i++].set_keys("ABC", KEY_A, KEY_B, KEY_C);
  key_buttons[i++].set_keys("DEF", KEY_D, KEY_E, KEY_F);
  key_buttons[i++].set_keys("<x", KEY_Backspace);
  key_buttons[i++].set_keys("←", KEY_LeftArrow);
  key_buttons[i++].set_keys("GHI", KEY_G, KEY_H, KEY_I);
  key_buttons[i++].set_keys("JKL", KEY_J, KEY_K, KEY_L);
  key_buttons[i++].set_keys("MNO", KEY_M, KEY_N, KEY_O);
  key_buttons[i++].set_keys("空白", KEY_Spacebar);
  key_buttons[i++].set_keys("123");
  key_buttons[i++].set_keys("PQRS", KEY_P, KEY_Q, KEY_R, KEY_S);
  key_buttons[i++].set_keys("TUV", KEY_T, KEY_U, KEY_V);
  key_buttons[i++].set_keys("WXYZ", KEY_W, KEY_X, KEY_Y, KEY_Z);
  key_buttons[i++].set_keys("改行", KEY_ENTER);
  key_buttons[i++].set_keys("(^_^)");
  key_buttons[i++].set_keys("a/A");
  key_buttons[i++].set_keys("'\"()", KEY_quote, KEY_double_quote, KEY_left_parenthesis, KEY_right_parenthesis);
  key_buttons[i++].set_keys(".,?!", KEY_period, KEY_comma, KEY_question, KEY_exclamation_mark);
}

void init_keyboard_layout()
{
  const int32_t x = 10, y = 560, w = 96, h = 78, pad = 10;

  for (size_t j = 0; j < 5; j++)
  {
    for (size_t i = 0; i < 4; i++)
    {
      key_buttons[i * 5 + j].init(x + (w + pad) * j, y + (h + pad) * i, w, (i == 2 && j == 4) ? h * 2 + pad : h, (j == 0 || j == 4) ? TFT_WHITE : TFT_BLACK, (j == 0 || j == 4) ? TFT_DARKGRAY : TFT_LIGHTGRAY);
      if (i == 2 && j == 4)
        break;
    }
  }
}

void draw_keyboard()
{
  M5.Display.startWrite();
  M5.Display.setTextSize(1);
  M5.Display.fillRect(0, 460, 540, 500, TFT_WHITE);
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
  M5.Display.fillRect(x - 270, y - 100, 540, 200, TFT_WHITE);
  M5.Display.drawCenterString(text.c_str(), x, y, &fonts::lgfxJapanGothicP_40);
  M5.Display.endWrite();
}

void input_key_button(struct key_button *key, direction_t dir)
{
  auto input = key->get_key_input(dir);
  if (input == nullptr)
  {
    return;
  }
  draw_input_text(input->text, 270, 150);
  send_key(input->keycode, input->modifier << 1);
}
