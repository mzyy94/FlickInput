#include <algorithm>

#include "keyboard.hpp"
#include "key_button.hpp"
#include "layout.hpp"

std::vector<Layout *> layouts;
size_t next_layout = 0;

void draw_next_keyboard()
{
  Keyboard.draw_next_layout();
}

void layout_hiragana_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_keys("あ", KEYKANA_A, KEYKANA_I, KEYKANA_U, KEYKANA_E, KEYKANA_O);
  Keyboard.key_buttons[i++].set_keys("か", KEYKANA_KA, KEYKANA_KI, KEYKANA_KU, KEYKANA_KE, KEYKANA_KO);
  Keyboard.key_buttons[i++].set_keys("さ", KEYKANA_SA, KEYKANA_SI, KEYKANA_SU, KEYKANA_SE, KEYKANA_SO);
  Keyboard.key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  Keyboard.key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  Keyboard.key_buttons[i++].set_keys("た", KEYKANA_TA, KEYKANA_TI, KEYKANA_TU, KEYKANA_TE, KEYKANA_TO);
  Keyboard.key_buttons[i++].set_keys("な", KEYKANA_NA, KEYKANA_NI, KEYKANA_NU, KEYKANA_NE, KEYKANA_NO);
  Keyboard.key_buttons[i++].set_keys("は", KEYKANA_HA, KEYKANA_HI, KEYKANA_HU, KEYKANA_HE, KEYKANA_HO);
  Keyboard.key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  Keyboard.key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard, layouts[next_layout]->key);
  Keyboard.key_buttons[i++].set_keys("ま", KEYKANA_MA, KEYKANA_MI, KEYKANA_MU, KEYKANA_ME, KEYKANA_MO);
  Keyboard.key_buttons[i++].set_keys("や", KEYKANA_YA, KEYKANA_KAKKO, KEYKANA_YU, KEYKANA_KAKKO_TOJI, KEYKANA_YO);
  Keyboard.key_buttons[i++].set_keys("ら", KEYKANA_RA, KEYKANA_RI, KEYKANA_RU, KEYKANA_RE, KEYKANA_RO);
  Keyboard.key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  Keyboard.key_buttons[i++].set_keys("Esc", KEY_ESCAPE);
  Keyboard.key_buttons[i++].set_action("小゛゜", layout_hiragana_modified_keybard);
  Keyboard.key_buttons[i++].set_keys("わ", KEYKANA_WA, KEYKANA_WO, KEYKANA_NN, KEYKANA_DASH);
  Keyboard.key_buttons[i++].set_keys("、。?!", KEYKANA_TOUTEN, KEYKANA_KUTEN, KEYKANA_QUESTION, KEYKANA_EXCL_MARK);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}

void layout_hiragana_modified_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_action("ぁ", layout_hiragana_keybard, KEYKANA_XA, KEYKANA_XI, KEYKANA_XU, KEYKANA_XE, KEYKANA_XO);
  Keyboard.key_buttons[i++].set_action("が", layout_hiragana_keybard, KEYKANA_GA, KEYKANA_GI, KEYKANA_GU, KEYKANA_GE, KEYKANA_GO);
  Keyboard.key_buttons[i++].set_action("ざ", layout_hiragana_keybard, KEYKANA_ZA, KEYKANA_ZI, KEYKANA_ZU, KEYKANA_ZE, KEYKANA_ZO);
  Keyboard.key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  Keyboard.key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  Keyboard.key_buttons[i++].set_action("だ", layout_hiragana_keybard, KEYKANA_DA, KEYKANA_DI, KEYKANA_DU, KEYKANA_DE, KEYKANA_DO);
  Keyboard.key_buttons[i++].set_action("っ", layout_hiragana_keybard, KEYKANA_XTU);
  Keyboard.key_buttons[i++].set_action("ば", layout_hiragana_keybard, KEYKANA_BA, KEYKANA_BI, KEYKANA_BU, KEYKANA_BE, KEYKANA_BO);
  Keyboard.key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  Keyboard.key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard, layouts[next_layout]->key);
  Keyboard.key_buttons[i++].set_action("ぱ", layout_hiragana_keybard, KEYKANA_PA, KEYKANA_PI, KEYKANA_PU, KEYKANA_PE, KEYKANA_PO);
  Keyboard.key_buttons[i++].set_action("ゃ", layout_hiragana_keybard, KEYKANA_XYA, KEYKANA_LEFT_PAREN, KEYKANA_XYU, KEYKANA_RIGHT_PAREN, KEYKANA_XYO);
  Keyboard.key_buttons[i++].set_keys("");
  Keyboard.key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  Keyboard.key_buttons[i++].set_keys("Esc", KEY_ESCAPE);
  Keyboard.key_buttons[i++].set_action("あいう", layout_hiragana_keybard);
  Keyboard.key_buttons[i++].set_keys("");
  Keyboard.key_buttons[i++].set_keys("@#$%", KEYKANA_ATMARK, KEYKANA_NUM_SIGN, KEYKANA_DOLLAR, KEYKANA_PERCENT);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}

void layout_roman_kana_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_keys("あ", KEYROMAN_A, KEYROMAN_I, KEYROMAN_U, KEYROMAN_E, KEYROMAN_O);
  Keyboard.key_buttons[i++].set_keys("か", KEYROMAN_KA, KEYROMAN_KI, KEYROMAN_KU, KEYROMAN_KE, KEYROMAN_KO);
  Keyboard.key_buttons[i++].set_keys("さ", KEYROMAN_SA, KEYROMAN_SI, KEYROMAN_SU, KEYROMAN_SE, KEYROMAN_SO);
  Keyboard.key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  Keyboard.key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  Keyboard.key_buttons[i++].set_keys("た", KEYROMAN_TA, KEYROMAN_TI, KEYROMAN_TU, KEYROMAN_TE, KEYROMAN_TO);
  Keyboard.key_buttons[i++].set_keys("な", KEYROMAN_NA, KEYROMAN_NI, KEYROMAN_NU, KEYROMAN_NE, KEYROMAN_NO);
  Keyboard.key_buttons[i++].set_keys("は", KEYROMAN_HA, KEYROMAN_HI, KEYROMAN_HU, KEYROMAN_HE, KEYROMAN_HO);
  Keyboard.key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  Keyboard.key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard, layouts[next_layout]->key);
  Keyboard.key_buttons[i++].set_keys("ま", KEYROMAN_MA, KEYROMAN_MI, KEYROMAN_MU, KEYROMAN_ME, KEYROMAN_MO);
  Keyboard.key_buttons[i++].set_keys("や", KEYROMAN_YA, KEYROMAN_KAKKO, KEYROMAN_YU, KEYROMAN_KAKKO_TOJI, KEYROMAN_YO);
  Keyboard.key_buttons[i++].set_keys("ら", KEYROMAN_RA, KEYROMAN_RI, KEYROMAN_RU, KEYROMAN_RE, KEYROMAN_RO);
  Keyboard.key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  Keyboard.key_buttons[i++].set_keys("Esc", KEY_ESCAPE);
  Keyboard.key_buttons[i++].set_action("小゛゜", layout_roman_modified_keybard);
  Keyboard.key_buttons[i++].set_keys("わ", KEYROMAN_WA, KEYROMAN_WO, KEYROMAN_NN, KEYROMAN_DASH);
  Keyboard.key_buttons[i++].set_keys("、。?!", KEYROMAN_TOUTEN, KEYROMAN_KUTEN, KEYROMAN_QUESTION, KEYROMAN_EXCL_MARK);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}

void layout_roman_modified_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_action("ぁ", layout_roman_kana_keybard, KEYROMAN_XA, KEYROMAN_XI, KEYROMAN_XU, KEYROMAN_XE, KEYROMAN_XO);
  Keyboard.key_buttons[i++].set_action("が", layout_roman_kana_keybard, KEYROMAN_GA, KEYROMAN_GI, KEYROMAN_GU, KEYROMAN_GE, KEYROMAN_GO);
  Keyboard.key_buttons[i++].set_action("ざ", layout_roman_kana_keybard, KEYROMAN_ZA, KEYROMAN_ZI, KEYROMAN_ZU, KEYROMAN_ZE, KEYROMAN_ZO);
  Keyboard.key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  Keyboard.key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  Keyboard.key_buttons[i++].set_action("だ", layout_roman_kana_keybard, KEYROMAN_DA, KEYROMAN_DI, KEYROMAN_DU, KEYROMAN_DE, KEYROMAN_DO);
  Keyboard.key_buttons[i++].set_action("っ", layout_roman_kana_keybard, KEYROMAN_XTU);
  Keyboard.key_buttons[i++].set_action("ば", layout_roman_kana_keybard, KEYROMAN_BA, KEYROMAN_BI, KEYROMAN_BU, KEYROMAN_BE, KEYROMAN_BO);
  Keyboard.key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  Keyboard.key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard, layouts[next_layout]->key);
  Keyboard.key_buttons[i++].set_action("ぱ", layout_roman_kana_keybard, KEYROMAN_PA, KEYROMAN_PI, KEYROMAN_PU, KEYROMAN_PE, KEYROMAN_PO);
  Keyboard.key_buttons[i++].set_action("ゃ", layout_roman_kana_keybard, KEYROMAN_XYA, KEYROMAN_LEFT_PAREN, KEYROMAN_XYU, KEYROMAN_RIGHT_PAREN, KEYROMAN_XYO);
  Keyboard.key_buttons[i++].set_keys("");
  Keyboard.key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  Keyboard.key_buttons[i++].set_keys("Esc", KEY_ESCAPE);
  Keyboard.key_buttons[i++].set_action("あいう", layout_roman_kana_keybard);
  Keyboard.key_buttons[i++].set_keys("");
  Keyboard.key_buttons[i++].set_keys("@#$%", KEYROMAN_ATMARK, KEYROMAN_NUM_SIGN, KEYROMAN_DOLLAR, KEYROMAN_PERCENT);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}

void layout_alphabet_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_keys("@#/&_", KEY_ATMARK, KEY_NUM_SIGN, KEY_FWD_SLASH, KEY_AMPERSAND, KEY_UNDERSCORE);
  Keyboard.key_buttons[i++].set_keys("ABC", KEY_A, KEY_B, KEY_C);
  Keyboard.key_buttons[i++].set_keys("DEF", KEY_D, KEY_E, KEY_F);
  Keyboard.key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  Keyboard.key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  Keyboard.key_buttons[i++].set_keys("GHI", KEY_G, KEY_H, KEY_I);
  Keyboard.key_buttons[i++].set_keys("JKL", KEY_J, KEY_K, KEY_L);
  Keyboard.key_buttons[i++].set_keys("MNO", KEY_M, KEY_N, KEY_O);
  Keyboard.key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  Keyboard.key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard, layouts[next_layout]->key);
  Keyboard.key_buttons[i++].set_keys("PQRS", KEY_P, KEY_Q, KEY_R, KEY_S);
  Keyboard.key_buttons[i++].set_keys("TUV", KEY_T, KEY_U, KEY_V);
  Keyboard.key_buttons[i++].set_keys("WXYZ", KEY_W, KEY_X, KEY_Y, KEY_Z);
  Keyboard.key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  Keyboard.key_buttons[i++].set_keys("Esc", KEY_ESCAPE);
  Keyboard.key_buttons[i++].set_action("a/A", layout_lower_alphabet_keybard);
  Keyboard.key_buttons[i++].set_keys("'\"()", KEY_SGL_QUOTE, KEY_DBL_QUOTE, KEY_LEFT_PAREN, KEY_RIGHT_PAREN);
  Keyboard.key_buttons[i++].set_keys(".,?!", KEY_DOT, KEY_COMMA, KEY_QUESTION, KEY_EXCL_MARK);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}

void layout_lower_alphabet_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_keys("@#/&_", KEY_ATMARK, KEY_NUM_SIGN, KEY_FWD_SLASH, KEY_AMPERSAND, KEY_UNDERSCORE);
  Keyboard.key_buttons[i++].set_keys("abc", KEY_a, KEY_b, KEY_c);
  Keyboard.key_buttons[i++].set_keys("def", KEY_d, KEY_e, KEY_f);
  Keyboard.key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  Keyboard.key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  Keyboard.key_buttons[i++].set_keys("ghi", KEY_g, KEY_h, KEY_i);
  Keyboard.key_buttons[i++].set_keys("jkl", KEY_j, KEY_k, KEY_l);
  Keyboard.key_buttons[i++].set_keys("mno", KEY_m, KEY_n, KEY_o);
  Keyboard.key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  Keyboard.key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard, layouts[next_layout]->key);
  Keyboard.key_buttons[i++].set_keys("pqrs", KEY_p, KEY_q, KEY_r, KEY_s);
  Keyboard.key_buttons[i++].set_keys("tuv", KEY_t, KEY_u, KEY_v);
  Keyboard.key_buttons[i++].set_keys("wxyz", KEY_w, KEY_x, KEY_y, KEY_z);
  Keyboard.key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  Keyboard.key_buttons[i++].set_keys("Esc", KEY_ESCAPE);
  Keyboard.key_buttons[i++].set_action("a/A", layout_alphabet_keybard);
  Keyboard.key_buttons[i++].set_keys("'\"()", KEY_SGL_QUOTE, KEY_DBL_QUOTE, KEY_LEFT_PAREN, KEY_RIGHT_PAREN);
  Keyboard.key_buttons[i++].set_keys(".,?!", KEY_DOT, KEY_COMMA, KEY_QUESTION, KEY_EXCL_MARK);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}

void layout_number_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_keys("1", KEY_1);
  Keyboard.key_buttons[i++].set_keys("2", KEY_2);
  Keyboard.key_buttons[i++].set_keys("3", KEY_3);
  Keyboard.key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  Keyboard.key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  Keyboard.key_buttons[i++].set_keys("4", KEY_4);
  Keyboard.key_buttons[i++].set_keys("5", KEY_5);
  Keyboard.key_buttons[i++].set_keys("6", KEY_6);
  Keyboard.key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  Keyboard.key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard, layouts[next_layout]->key);
  Keyboard.key_buttons[i++].set_keys("7", KEY_7);
  Keyboard.key_buttons[i++].set_keys("8", KEY_8);
  Keyboard.key_buttons[i++].set_keys("9", KEY_9);
  Keyboard.key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  Keyboard.key_buttons[i++].set_keys("Esc", KEY_ESCAPE);
  Keyboard.key_buttons[i++].set_keys("()[]", KEY_LEFT_PAREN, KEY_RIGHT_PAREN, KEY_LEFT_BRKT, KEY_RIGHT_BRKT);
  Keyboard.key_buttons[i++].set_keys("0", KEY_0);
  Keyboard.key_buttons[i++].set_keys(".,-/", KEY_DOT, KEY_COMMA, KEY_MINUS, KEY_FWD_SLASH);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}
