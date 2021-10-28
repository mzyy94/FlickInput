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

void layout_jis_hiragana_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_keys("あ", KEYJISKANA_A, KEYJISKANA_I, KEYJISKANA_U, KEYJISKANA_E, KEYJISKANA_O);
  Keyboard.key_buttons[i++].set_keys("か", KEYJISKANA_KA, KEYJISKANA_KI, KEYJISKANA_KU, KEYJISKANA_KE, KEYJISKANA_KO);
  Keyboard.key_buttons[i++].set_keys("さ", KEYJISKANA_SA, KEYJISKANA_SI, KEYJISKANA_SU, KEYJISKANA_SE, KEYJISKANA_SO);
  Keyboard.key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  Keyboard.key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  Keyboard.key_buttons[i++].set_keys("た", KEYJISKANA_TA, KEYJISKANA_TI, KEYJISKANA_TU, KEYJISKANA_TE, KEYJISKANA_TO);
  Keyboard.key_buttons[i++].set_keys("な", KEYJISKANA_NA, KEYJISKANA_NI, KEYJISKANA_NU, KEYJISKANA_NE, KEYJISKANA_NO);
  Keyboard.key_buttons[i++].set_keys("は", KEYJISKANA_HA, KEYJISKANA_HI, KEYJISKANA_HU, KEYJISKANA_HE, KEYJISKANA_HO);
  Keyboard.key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  Keyboard.key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard, layouts[next_layout]->key);
  Keyboard.key_buttons[i++].set_keys("ま", KEYJISKANA_MA, KEYJISKANA_MI, KEYJISKANA_MU, KEYJISKANA_ME, KEYJISKANA_MO);
  Keyboard.key_buttons[i++].set_keys("や", KEYJISKANA_YA, KEYJISKANA_KAKKO, KEYJISKANA_YU, KEYJISKANA_KAKKO_TOJI, KEYJISKANA_YO);
  Keyboard.key_buttons[i++].set_keys("ら", KEYJISKANA_RA, KEYJISKANA_RI, KEYJISKANA_RU, KEYJISKANA_RE, KEYJISKANA_RO);
  Keyboard.key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  Keyboard.key_buttons[i++].set_keys("Esc", KEY_ESCAPE);
  Keyboard.key_buttons[i++].set_action("小゛゜", layout_jis_hiragana_modified_keybard);
  Keyboard.key_buttons[i++].set_keys("わ", KEYJISKANA_WA, KEYJISKANA_WO, KEYJISKANA_NN, KEYJISKANA_DASH);
  Keyboard.key_buttons[i++].set_keys("、。?!", KEYJISKANA_TOUTEN, KEYJISKANA_KUTEN, KEYJISKANA_QUESTION, KEYJISKANA_EXCL_MARK);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}

void layout_jis_hiragana_modified_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_action("ぁ", layout_jis_hiragana_keybard, KEYJISKANA_XA, KEYJISKANA_XI, KEYJISKANA_XU, KEYJISKANA_XE, KEYJISKANA_XO);
  Keyboard.key_buttons[i++].set_action("が", layout_jis_hiragana_keybard, KEYJISKANA_GA, KEYJISKANA_GI, KEYJISKANA_GU, KEYJISKANA_GE, KEYJISKANA_GO);
  Keyboard.key_buttons[i++].set_action("ざ", layout_jis_hiragana_keybard, KEYJISKANA_ZA, KEYJISKANA_ZI, KEYJISKANA_ZU, KEYJISKANA_ZE, KEYJISKANA_ZO);
  Keyboard.key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  Keyboard.key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  Keyboard.key_buttons[i++].set_action("だ", layout_jis_hiragana_keybard, KEYJISKANA_DA, KEYJISKANA_DI, KEYJISKANA_DU, KEYJISKANA_DE, KEYJISKANA_DO);
  Keyboard.key_buttons[i++].set_action("っ", layout_jis_hiragana_keybard, KEYJISKANA_XTU);
  Keyboard.key_buttons[i++].set_action("ば", layout_jis_hiragana_keybard, KEYJISKANA_BA, KEYJISKANA_BI, KEYJISKANA_BU, KEYJISKANA_BE, KEYJISKANA_BO);
  Keyboard.key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  Keyboard.key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard, layouts[next_layout]->key);
  Keyboard.key_buttons[i++].set_action("ぱ", layout_jis_hiragana_keybard, KEYJISKANA_PA, KEYJISKANA_PI, KEYJISKANA_PU, KEYJISKANA_PE, KEYJISKANA_PO);
  Keyboard.key_buttons[i++].set_action("ゃ", layout_jis_hiragana_keybard, KEYJISKANA_XYA, KEYJISKANA_LEFT_PAREN, KEYJISKANA_XYU, KEYJISKANA_RIGHT_PAREN, KEYJISKANA_XYO);
  Keyboard.key_buttons[i++].set_keys("");
  Keyboard.key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  Keyboard.key_buttons[i++].set_keys("Esc", KEY_ESCAPE);
  Keyboard.key_buttons[i++].set_action("あいう", layout_jis_hiragana_keybard);
  Keyboard.key_buttons[i++].set_keys("");
  Keyboard.key_buttons[i++].set_keys("@#$%", KEYJISKANA_ATMARK, KEYJISKANA_NUM_SIGN, KEYJISKANA_DOLLAR, KEYJISKANA_PERCENT);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}

void layout_us_hiragana_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_keys("あ", KEYUSKANA_A, KEYUSKANA_I, KEYUSKANA_U, KEYUSKANA_E, KEYUSKANA_O);
  Keyboard.key_buttons[i++].set_keys("か", KEYUSKANA_KA, KEYUSKANA_KI, KEYUSKANA_KU, KEYUSKANA_KE, KEYUSKANA_KO);
  Keyboard.key_buttons[i++].set_keys("さ", KEYUSKANA_SA, KEYUSKANA_SI, KEYUSKANA_SU, KEYUSKANA_SE, KEYUSKANA_SO);
  Keyboard.key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  Keyboard.key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  Keyboard.key_buttons[i++].set_keys("た", KEYUSKANA_TA, KEYUSKANA_TI, KEYUSKANA_TU, KEYUSKANA_TE, KEYUSKANA_TO);
  Keyboard.key_buttons[i++].set_keys("な", KEYUSKANA_NA, KEYUSKANA_NI, KEYUSKANA_NU, KEYUSKANA_NE, KEYUSKANA_NO);
  Keyboard.key_buttons[i++].set_keys("は", KEYUSKANA_HA, KEYUSKANA_HI, KEYUSKANA_HU, KEYUSKANA_HE, KEYUSKANA_HO);
  Keyboard.key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  Keyboard.key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard, layouts[next_layout]->key);
  Keyboard.key_buttons[i++].set_keys("ま", KEYUSKANA_MA, KEYUSKANA_MI, KEYUSKANA_MU, KEYUSKANA_ME, KEYUSKANA_MO);
  Keyboard.key_buttons[i++].set_keys("や", KEYUSKANA_YA, KEYUSKANA_KAKKO, KEYUSKANA_YU, KEYUSKANA_KAKKO_TOJI, KEYUSKANA_YO);
  Keyboard.key_buttons[i++].set_keys("ら", KEYUSKANA_RA, KEYUSKANA_RI, KEYUSKANA_RU, KEYUSKANA_RE, KEYUSKANA_RO);
  Keyboard.key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  Keyboard.key_buttons[i++].set_keys("Esc", KEY_ESCAPE);
  Keyboard.key_buttons[i++].set_action("小゛゜", layout_us_hiragana_modified_keybard);
  Keyboard.key_buttons[i++].set_keys("わ", KEYUSKANA_WA, KEYUSKANA_WO, KEYUSKANA_NN, KEYUSKANA_DASH);
  Keyboard.key_buttons[i++].set_keys("、。?!", KEYUSKANA_TOUTEN, KEYUSKANA_KUTEN, KEYUSKANA_QUESTION, KEYUSKANA_EXCL_MARK);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}

void layout_us_hiragana_modified_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_action("ぁ", layout_us_hiragana_keybard, KEYUSKANA_XA, KEYUSKANA_XI, KEYUSKANA_XU, KEYUSKANA_XE, KEYUSKANA_XO);
  Keyboard.key_buttons[i++].set_action("が", layout_us_hiragana_keybard, KEYUSKANA_GA, KEYUSKANA_GI, KEYUSKANA_GU, KEYUSKANA_GE, KEYUSKANA_GO);
  Keyboard.key_buttons[i++].set_action("ざ", layout_us_hiragana_keybard, KEYUSKANA_ZA, KEYUSKANA_ZI, KEYUSKANA_ZU, KEYUSKANA_ZE, KEYUSKANA_ZO);
  Keyboard.key_buttons[i++].set_repeatable_keys("<x", KEY_DELETE);
  Keyboard.key_buttons[i++].set_repeatable_keys("←", KEY_LEFT_ARROW);
  Keyboard.key_buttons[i++].set_action("だ", layout_us_hiragana_keybard, KEYUSKANA_DA, KEYUSKANA_DI, KEYUSKANA_DU, KEYUSKANA_DE, KEYUSKANA_DO);
  Keyboard.key_buttons[i++].set_action("っ", layout_us_hiragana_keybard, KEYUSKANA_XTU);
  Keyboard.key_buttons[i++].set_action("ば", layout_us_hiragana_keybard, KEYUSKANA_BA, KEYUSKANA_BI, KEYUSKANA_BU, KEYUSKANA_BE, KEYUSKANA_BO);
  Keyboard.key_buttons[i++].set_repeatable_keys("空白", KEY_SPACEBAR);
  Keyboard.key_buttons[i++].set_action(layouts[next_layout]->icon, draw_next_keyboard, layouts[next_layout]->key);
  Keyboard.key_buttons[i++].set_action("ぱ", layout_us_hiragana_keybard, KEYUSKANA_PA, KEYUSKANA_PI, KEYUSKANA_PU, KEYUSKANA_PE, KEYUSKANA_PO);
  Keyboard.key_buttons[i++].set_action("ゃ", layout_us_hiragana_keybard, KEYUSKANA_XYA, KEYUSKANA_LEFT_PAREN, KEYUSKANA_XYU, KEYUSKANA_RIGHT_PAREN, KEYUSKANA_XYO);
  Keyboard.key_buttons[i++].set_keys("");
  Keyboard.key_buttons[i++].set_repeatable_keys("改行", KEY_ENTER);
  Keyboard.key_buttons[i++].set_keys("Esc", KEY_ESCAPE);
  Keyboard.key_buttons[i++].set_action("あいう", layout_us_hiragana_keybard);
  Keyboard.key_buttons[i++].set_keys("");
  Keyboard.key_buttons[i++].set_keys("@#$%", KEYUSKANA_ATMARK, KEYUSKANA_NUM_SIGN, KEYUSKANA_DOLLAR, KEYUSKANA_PERCENT);

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
  Keyboard.key_buttons[i++].set_keys("@#/&_", KEY_US_ATMARK, KEY_US_NUM_SIGN, KEY_US_FWD_SLASH, KEY_US_AMPERSAND, KEY_US_UNDERSCORE);
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
  Keyboard.key_buttons[i++].set_keys("'\"()", KEY_US_SGL_QUOTE, KEY_US_DBL_QUOTE, KEY_US_LEFT_PAREN, KEY_US_RIGHT_PAREN);
  Keyboard.key_buttons[i++].set_keys(".,?!", KEY_US_DOT, KEY_US_COMMA, KEY_US_QUESTION, KEY_US_EXCL_MARK);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}

void layout_lower_alphabet_keybard()
{
  size_t i = 0;
  Keyboard.key_buttons[i++].set_repeatable_keys("→", KEY_RIGHT_ARROW);
  Keyboard.key_buttons[i++].set_keys("@#/&_", KEY_US_ATMARK, KEY_US_NUM_SIGN, KEY_US_FWD_SLASH, KEY_US_AMPERSAND, KEY_US_UNDERSCORE);
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
  Keyboard.key_buttons[i++].set_keys("'\"()", KEY_US_SGL_QUOTE, KEY_US_DBL_QUOTE, KEY_US_LEFT_PAREN, KEY_US_RIGHT_PAREN);
  Keyboard.key_buttons[i++].set_keys(".,?!", KEY_US_DOT, KEY_US_COMMA, KEY_US_QUESTION, KEY_US_EXCL_MARK);

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
  Keyboard.key_buttons[i++].set_keys("()[]", KEY_US_LEFT_PAREN, KEY_US_RIGHT_PAREN, KEY_US_LEFT_BRKT, KEY_US_RIGHT_BRKT);
  Keyboard.key_buttons[i++].set_keys("0", KEY_0);
  Keyboard.key_buttons[i++].set_keys(".,-/", KEY_US_DOT, KEY_US_COMMA, KEY_US_MINUS, KEY_US_FWD_SLASH);

  xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
}
