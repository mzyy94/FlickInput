#include <algorithm>

#include "keyboard.hpp"
#include "key_button.hpp"
#include "ble.hpp"

std::array<struct key_button, 19> key_buttons;

struct Layout
{
  std::string icon;
  std::function<void(void)> draw_function;

  Layout(std::string icon, std::function<void(void)> draw_function)
  {
    this->icon = icon;
    this->draw_function = draw_function;
  }
};

std::vector<Layout *> layouts;
size_t next_layout = 0;

void draw_next_keyboard()
{
  const auto draw_func = layouts[next_layout]->draw_function;
  next_layout++;
  if (next_layout >= layouts.size())
  {
    next_layout = 0;
  }
  draw_func();
}

void draw_hiragana_keybard();
void draw_hiragana_modified_keybard();
void draw_roman_kana_keybard();
void draw_roman_modified_keybard();
void draw_alphabet_keybard();
void draw_lower_alphabet_keybard();
void draw_number_keybard();

void draw_hiragana_keybard()
{
  send_key(HID_KEY_LANG1, 0);

  size_t i = 0;
  key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  key_buttons[i++].set_keys("あ", KEYKANA_A, KEYKANA_I, KEYKANA_U, KEYKANA_E, KEYKANA_O);
  key_buttons[i++].set_keys("か", KEYKANA_KA, KEYKANA_KI, KEYKANA_KU, KEYKANA_KE, KEYKANA_KO);
  key_buttons[i++].set_keys("さ", KEYKANA_SA, KEYKANA_SI, KEYKANA_SU, KEYKANA_SE, KEYKANA_SO);
  key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  key_buttons[i++].set_keys("た", KEYKANA_TA, KEYKANA_TI, KEYKANA_TU, KEYKANA_TE, KEYKANA_TO);
  key_buttons[i++].set_keys("な", KEYKANA_NA, KEYKANA_NI, KEYKANA_NU, KEYKANA_NE, KEYKANA_NO);
  key_buttons[i++].set_keys("は", KEYKANA_HA, KEYKANA_HI, KEYKANA_HU, KEYKANA_HE, KEYKANA_HO);
  key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard);
  key_buttons[i++].set_keys("ま", KEYKANA_MA, KEYKANA_MI, KEYKANA_MU, KEYKANA_ME, KEYKANA_MO);
  key_buttons[i++].set_keys("や", KEYKANA_YA, KEYKANA_KAKKO, KEYKANA_YU, KEYKANA_KAKKO_TOJI, KEYKANA_YO);
  key_buttons[i++].set_keys("ら", KEYKANA_RA, KEYKANA_RI, KEYKANA_RU, KEYKANA_RE, KEYKANA_RO);
  key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  key_buttons[i++].set_keys("⇔", KEY_CHANGE_INPUT_MAC);
  key_buttons[i++].set_action("小゛゜", draw_hiragana_modified_keybard);
  key_buttons[i++].set_keys("わ", KEYKANA_WA, KEYKANA_WO, KEYKANA_NN, KEYKANA_DASH);
  key_buttons[i++].set_keys("、。?!", KEYKANA_TOUTEN, KEYKANA_KUTEN, KEYKANA_QUESTION, KEYKANA_EXCL_MARK);
  draw_keyboard();
}

void draw_hiragana_modified_keybard()
{
  size_t i = 0;
  key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  key_buttons[i++].set_action("ぁ", draw_hiragana_keybard, KEYKANA_XA, KEYKANA_XI, KEYKANA_XU, KEYKANA_XE, KEYKANA_XO);
  key_buttons[i++].set_action("が", draw_hiragana_keybard, KEYKANA_GA, KEYKANA_GI, KEYKANA_GU, KEYKANA_GE, KEYKANA_GO);
  key_buttons[i++].set_action("ざ", draw_hiragana_keybard, KEYKANA_ZA, KEYKANA_ZI, KEYKANA_ZU, KEYKANA_ZE, KEYKANA_ZO);
  key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  key_buttons[i++].set_action("だ", draw_hiragana_keybard, KEYKANA_DA, KEYKANA_DI, KEYKANA_DU, KEYKANA_DE, KEYKANA_DO);
  key_buttons[i++].set_action("っ", draw_hiragana_keybard, KEYKANA_XTU);
  key_buttons[i++].set_action("ば", draw_hiragana_keybard, KEYKANA_BA, KEYKANA_BI, KEYKANA_BU, KEYKANA_BE, KEYKANA_BO);
  key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard);
  key_buttons[i++].set_action("ぱ", draw_hiragana_keybard, KEYKANA_PA, KEYKANA_PI, KEYKANA_PU, KEYKANA_PE, KEYKANA_PO);
  key_buttons[i++].set_action("ゃ", draw_hiragana_keybard, KEYKANA_XYA, KEYKANA_LEFT_PAREN, KEYKANA_XYU, KEYKANA_RIGHT_PAREN, KEYKANA_XYO);
  key_buttons[i++].set_keys("");
  key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  key_buttons[i++].set_keys("⇔", KEY_CHANGE_INPUT_MAC);
  key_buttons[i++].set_action("あいう", draw_hiragana_keybard);
  key_buttons[i++].set_keys("");
  key_buttons[i++].set_keys("@#$%", KEYKANA_ATMARK, KEYKANA_NUM_SIGN, KEYKANA_DOLLAR, KEYKANA_PERCENT);
  draw_keyboard();
}

void draw_roman_kana_keybard()
{
  send_key(HID_KEY_LANG1, 0);

  size_t i = 0;
  key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  key_buttons[i++].set_keys("あ", KEYROMAN_A, KEYROMAN_I, KEYROMAN_U, KEYROMAN_E, KEYROMAN_O);
  key_buttons[i++].set_keys("か", KEYROMAN_KA, KEYROMAN_KI, KEYROMAN_KU, KEYROMAN_KE, KEYROMAN_KO);
  key_buttons[i++].set_keys("さ", KEYROMAN_SA, KEYROMAN_SI, KEYROMAN_SU, KEYROMAN_SE, KEYROMAN_SO);
  key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  key_buttons[i++].set_keys("た", KEYROMAN_TA, KEYROMAN_TI, KEYROMAN_TU, KEYROMAN_TE, KEYROMAN_TO);
  key_buttons[i++].set_keys("な", KEYROMAN_NA, KEYROMAN_NI, KEYROMAN_NU, KEYROMAN_NE, KEYROMAN_NO);
  key_buttons[i++].set_keys("は", KEYROMAN_HA, KEYROMAN_HI, KEYROMAN_HU, KEYROMAN_HE, KEYROMAN_HO);
  key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard);
  key_buttons[i++].set_keys("ま", KEYROMAN_MA, KEYROMAN_MI, KEYROMAN_MU, KEYROMAN_ME, KEYROMAN_MO);
  key_buttons[i++].set_keys("や", KEYROMAN_YA, KEYROMAN_KAKKO, KEYROMAN_YU, KEYROMAN_KAKKO_TOJI, KEYROMAN_YO);
  key_buttons[i++].set_keys("ら", KEYROMAN_RA, KEYROMAN_RI, KEYROMAN_RU, KEYROMAN_RE, KEYROMAN_RO);
  key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  key_buttons[i++].set_keys("⇔", KEY_CHANGE_INPUT_MAC);
  key_buttons[i++].set_action("小゛゜", draw_roman_modified_keybard);
  key_buttons[i++].set_keys("わ", KEYROMAN_WA, KEYROMAN_WO, KEYROMAN_NN, KEYROMAN_DASH);
  key_buttons[i++].set_keys("、。?!", KEYROMAN_TOUTEN, KEYROMAN_KUTEN, KEYROMAN_QUESTION, KEYROMAN_EXCL_MARK);
  draw_keyboard();
}

void draw_roman_modified_keybard()
{
  size_t i = 0;
  key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  key_buttons[i++].set_action("ぁ", draw_roman_kana_keybard, KEYROMAN_XA, KEYROMAN_XI, KEYROMAN_XU, KEYROMAN_XE, KEYROMAN_XO);
  key_buttons[i++].set_action("が", draw_roman_kana_keybard, KEYROMAN_GA, KEYROMAN_GI, KEYROMAN_GU, KEYROMAN_GE, KEYROMAN_GO);
  key_buttons[i++].set_action("ざ", draw_roman_kana_keybard, KEYROMAN_ZA, KEYROMAN_ZI, KEYROMAN_ZU, KEYROMAN_ZE, KEYROMAN_ZO);
  key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  key_buttons[i++].set_action("だ", draw_roman_kana_keybard, KEYROMAN_DA, KEYROMAN_DI, KEYROMAN_DU, KEYROMAN_DE, KEYROMAN_DO);
  key_buttons[i++].set_action("っ", draw_roman_kana_keybard, KEYROMAN_XTU);
  key_buttons[i++].set_action("ば", draw_roman_kana_keybard, KEYROMAN_BA, KEYROMAN_BI, KEYROMAN_BU, KEYROMAN_BE, KEYROMAN_BO);
  key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard);
  key_buttons[i++].set_action("ぱ", draw_roman_kana_keybard, KEYROMAN_PA, KEYROMAN_PI, KEYROMAN_PU, KEYROMAN_PE, KEYROMAN_PO);
  key_buttons[i++].set_action("ゃ", draw_roman_kana_keybard, KEYROMAN_XYA, KEYROMAN_LEFT_PAREN, KEYROMAN_XYU, KEYROMAN_RIGHT_PAREN, KEYROMAN_XYO);
  key_buttons[i++].set_keys("");
  key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  key_buttons[i++].set_keys("⇔", KEY_CHANGE_INPUT_MAC);
  key_buttons[i++].set_action("あいう", draw_roman_kana_keybard);
  key_buttons[i++].set_keys("");
  key_buttons[i++].set_keys("@#$%", KEYROMAN_ATMARK, KEYROMAN_NUM_SIGN, KEYROMAN_DOLLAR, KEYROMAN_PERCENT);
  draw_keyboard();
}

void draw_alphabet_keybard()
{
  send_key(HID_KEY_LANG2, 0);

  size_t i = 0;
  key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  key_buttons[i++].set_keys("@#/&_", KEY_ATMARK, KEY_NUM_SIGN, KEY_FWD_SLASH, KEY_AMPERSAND, KEY_UNDERSCORE);
  key_buttons[i++].set_keys("ABC", KEY_A, KEY_B, KEY_C);
  key_buttons[i++].set_keys("DEF", KEY_D, KEY_E, KEY_F);
  key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  key_buttons[i++].set_keys("GHI", KEY_G, KEY_H, KEY_I);
  key_buttons[i++].set_keys("JKL", KEY_J, KEY_K, KEY_L);
  key_buttons[i++].set_keys("MNO", KEY_M, KEY_N, KEY_O);
  key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard);
  key_buttons[i++].set_keys("PQRS", KEY_P, KEY_Q, KEY_R, KEY_S);
  key_buttons[i++].set_keys("TUV", KEY_T, KEY_U, KEY_V);
  key_buttons[i++].set_keys("WXYZ", KEY_W, KEY_X, KEY_Y, KEY_Z);
  key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  key_buttons[i++].set_keys("⇔", KEY_CHANGE_INPUT_MAC);
  key_buttons[i++].set_action("a/A", draw_lower_alphabet_keybard);
  key_buttons[i++].set_keys("'\"()", KEY_SGL_QUOTE, KEY_DBL_QUOTE, KEY_LEFT_PAREN, KEY_RIGHT_PAREN);
  key_buttons[i++].set_keys(".,?!", KEY_DOT, KEY_COMMA, KEY_QUESTION, KEY_EXCL_MARK);
  draw_keyboard();
}

void draw_lower_alphabet_keybard()
{
  size_t i = 0;
  key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  key_buttons[i++].set_keys("@#/&_", KEY_ATMARK, KEY_NUM_SIGN, KEY_FWD_SLASH, KEY_AMPERSAND, KEY_UNDERSCORE);
  key_buttons[i++].set_keys("abc", KEY_a, KEY_b, KEY_c);
  key_buttons[i++].set_keys("def", KEY_d, KEY_e, KEY_f);
  key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  key_buttons[i++].set_keys("ghi", KEY_g, KEY_h, KEY_i);
  key_buttons[i++].set_keys("jkl", KEY_j, KEY_k, KEY_l);
  key_buttons[i++].set_keys("mno", KEY_m, KEY_n, KEY_o);
  key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard);
  key_buttons[i++].set_keys("pqrs", KEY_p, KEY_q, KEY_r, KEY_s);
  key_buttons[i++].set_keys("tuv", KEY_t, KEY_u, KEY_v);
  key_buttons[i++].set_keys("wxyz", KEY_w, KEY_x, KEY_y, KEY_z);
  key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  key_buttons[i++].set_keys("⇔", KEY_CHANGE_INPUT_MAC);
  key_buttons[i++].set_action("a/A", draw_alphabet_keybard);
  key_buttons[i++].set_keys("'\"()", KEY_SGL_QUOTE, KEY_DBL_QUOTE, KEY_LEFT_PAREN, KEY_RIGHT_PAREN);
  key_buttons[i++].set_keys(".,?!", KEY_DOT, KEY_COMMA, KEY_QUESTION, KEY_EXCL_MARK);
  draw_keyboard();
}

void draw_number_keybard()
{
  size_t i = 0;
  key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  key_buttons[i++].set_keys("1", KEY_1);
  key_buttons[i++].set_keys("2", KEY_2);
  key_buttons[i++].set_keys("3", KEY_3);
  key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  key_buttons[i++].set_keys("4", KEY_4);
  key_buttons[i++].set_keys("5", KEY_5);
  key_buttons[i++].set_keys("6", KEY_6);
  key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard);
  key_buttons[i++].set_keys("7", KEY_7);
  key_buttons[i++].set_keys("8", KEY_8);
  key_buttons[i++].set_keys("9", KEY_9);
  key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  key_buttons[i++].set_keys("⇔", KEY_CHANGE_INPUT_MAC);
  key_buttons[i++].set_keys("()[]", KEY_LEFT_PAREN, KEY_RIGHT_PAREN, KEY_LEFT_BRKT, KEY_RIGHT_BRKT);
  key_buttons[i++].set_keys("0", KEY_0);
  key_buttons[i++].set_keys(".,-/", KEY_DOT, KEY_COMMA, KEY_MINUS, KEY_FWD_SLASH);
  draw_keyboard();
}

void init_keyboard_layout()
{
  layouts.clear();
  layouts.push_back(new Layout("あいう", draw_hiragana_keybard));
  layouts.push_back(new Layout("ABC", draw_alphabet_keybard));
  layouts.push_back(new Layout("123", draw_number_keybard));
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