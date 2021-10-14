#include <algorithm>

#include "keyboard.hpp"
#include "key_button.hpp"
#include "ble.hpp"

std::array<struct key_button, 19> key_buttons;

void draw_alphabet_keybard()
{
  size_t i = 0;
  key_buttons[i++].set_keys("→", KEY_RIGHT_ARROW);
  key_buttons[i++].set_keys("@#/&_", KEY_ATMARK, KEY_NUM_SIGN, KEY_FWD_SLASH, KEY_AMPERSAND, KEY_UNDERSCORE);
  key_buttons[i++].set_keys("ABC", KEY_A, KEY_B, KEY_C);
  key_buttons[i++].set_keys("DEF", KEY_D, KEY_E, KEY_F);
  key_buttons[i++].set_keys("<x", KEY_DELETE);
  key_buttons[i++].set_keys("←", KEY_LEFT_ARROW);
  key_buttons[i++].set_keys("GHI", KEY_G, KEY_H, KEY_I);
  key_buttons[i++].set_keys("JKL", KEY_J, KEY_K, KEY_L);
  key_buttons[i++].set_keys("MNO", KEY_M, KEY_N, KEY_O);
  key_buttons[i++].set_keys("空白", KEY_SPACEBAR);
  key_buttons[i++].set_action("123", draw_number_keybard);
  key_buttons[i++].set_keys("PQRS", KEY_P, KEY_Q, KEY_R, KEY_S);
  key_buttons[i++].set_keys("TUV", KEY_T, KEY_U, KEY_V);
  key_buttons[i++].set_keys("WXYZ", KEY_W, KEY_X, KEY_Y, KEY_Z);
  key_buttons[i++].set_keys("改行", KEY_ENTER);
  key_buttons[i++].set_keys("⇔", KEY_CHANGE_INPUT_MAC);
  key_buttons[i++].set_action("a/A", draw_lower_alphabet_keybard);
  key_buttons[i++].set_keys("'\"()", KEY_SGL_QUOTE, KEY_DBL_QUOTE, KEY_LEFT_PAREN, KEY_RIGHT_PAREN);
  key_buttons[i++].set_keys(".,?!", KEY_DOT, KEY_COMMA, KEY_QUESTION, KEY_EXCL_MARK);
  draw_keyboard();
}

void draw_lower_alphabet_keybard()
{
  size_t i = 0;
  key_buttons[i++].set_keys("→", KEY_RIGHT_ARROW);
  key_buttons[i++].set_keys("@#/&_", KEY_ATMARK, KEY_NUM_SIGN, KEY_FWD_SLASH, KEY_AMPERSAND, KEY_UNDERSCORE);
  key_buttons[i++].set_keys("abc", KEY_a, KEY_b, KEY_c);
  key_buttons[i++].set_keys("def", KEY_d, KEY_e, KEY_f);
  key_buttons[i++].set_keys("<x", KEY_DELETE);
  key_buttons[i++].set_keys("←", KEY_LEFT_ARROW);
  key_buttons[i++].set_keys("ghi", KEY_g, KEY_h, KEY_i);
  key_buttons[i++].set_keys("jkl", KEY_j, KEY_k, KEY_l);
  key_buttons[i++].set_keys("mno", KEY_m, KEY_n, KEY_o);
  key_buttons[i++].set_keys("空白", KEY_SPACEBAR);
  key_buttons[i++].set_action("123", draw_number_keybard);
  key_buttons[i++].set_keys("pqrs", KEY_p, KEY_q, KEY_r, KEY_s);
  key_buttons[i++].set_keys("tuv", KEY_t, KEY_u, KEY_v);
  key_buttons[i++].set_keys("wxyz", KEY_w, KEY_x, KEY_y, KEY_z);
  key_buttons[i++].set_keys("改行", KEY_ENTER);
  key_buttons[i++].set_keys("⇔", KEY_CHANGE_INPUT_MAC);
  key_buttons[i++].set_action("a/A", draw_alphabet_keybard);
  key_buttons[i++].set_keys("'\"()", KEY_SGL_QUOTE, KEY_DBL_QUOTE, KEY_LEFT_PAREN, KEY_RIGHT_PAREN);
  key_buttons[i++].set_keys(".,?!", KEY_DOT, KEY_COMMA, KEY_QUESTION, KEY_EXCL_MARK);
  draw_keyboard();
}

void draw_number_keybard()
{
  size_t i = 0;
  key_buttons[i++].set_keys("→", KEY_RIGHT_ARROW);
  key_buttons[i++].set_keys("1", KEYPAD_1);
  key_buttons[i++].set_keys("2", KEYPAD_2);
  key_buttons[i++].set_keys("3", KEYPAD_3);
  key_buttons[i++].set_keys("<x", KEY_DELETE);
  key_buttons[i++].set_keys("←", KEY_LEFT_ARROW);
  key_buttons[i++].set_keys("4", KEYPAD_4);
  key_buttons[i++].set_keys("5", KEYPAD_5);
  key_buttons[i++].set_keys("6", KEYPAD_6);
  key_buttons[i++].set_keys("空白", KEY_SPACEBAR);
  key_buttons[i++].set_action("ABC", draw_alphabet_keybard);
  key_buttons[i++].set_keys("7", KEYPAD_7);
  key_buttons[i++].set_keys("8", KEYPAD_8);
  key_buttons[i++].set_keys("9", KEYPAD_9);
  key_buttons[i++].set_keys("改行", KEY_ENTER);
  key_buttons[i++].set_keys("⇔", KEY_CHANGE_INPUT_MAC);
  key_buttons[i++].set_keys("()[]", KEY_LEFT_PAREN, KEY_RIGHT_PAREN, KEY_LEFT_BRKT, KEY_RIGHT_BRKT);
  key_buttons[i++].set_keys("0", KEYPAD_0);
  key_buttons[i++].set_keys(".,-/", KEY_DOT, KEY_COMMA, KEY_QUESTION, KEY_EXCL_MARK);
  draw_keyboard();
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
  send_key(input->keycode, input->modifier);
}
