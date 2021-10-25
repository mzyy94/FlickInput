#pragma once
#include <M5Unified.h>
#include "hid_dev.h"

typedef struct key_input
{
  std::string text;
  uint8_t modifier;
  uint8_t keycode;
  uint8_t second_keycode;
  uint8_t third_keycode;
} key_input_t;

#define SINGLE_KEY(label, keycode, modifier) \
  {                                          \
    label, modifier, keycode, 0, 0           \
  }

#define MULTI_KEY2(label, keycode1, keycode2, modifier) \
  {                                                     \
    label, modifier, keycode1, keycode2, 0              \
  }

#define MULTI_KEY3(label, keycode1, keycode2, keycode3, modifier) \
  {                                                               \
    label, modifier, keycode1, keycode2, keycode3                 \
  }

static const key_input_t KEY_a = SINGLE_KEY("a", HID_KEY_A, 0);
static const key_input_t KEY_A = SINGLE_KEY("A", HID_KEY_A, 2);
static const key_input_t KEY_b = SINGLE_KEY("b", HID_KEY_B, 0);
static const key_input_t KEY_B = SINGLE_KEY("B", HID_KEY_B, 2);
static const key_input_t KEY_c = SINGLE_KEY("c", HID_KEY_C, 0);
static const key_input_t KEY_C = SINGLE_KEY("C", HID_KEY_C, 2);
static const key_input_t KEY_d = SINGLE_KEY("d", HID_KEY_D, 0);
static const key_input_t KEY_D = SINGLE_KEY("D", HID_KEY_D, 2);
static const key_input_t KEY_e = SINGLE_KEY("e", HID_KEY_E, 0);
static const key_input_t KEY_E = SINGLE_KEY("E", HID_KEY_E, 2);
static const key_input_t KEY_f = SINGLE_KEY("f", HID_KEY_F, 0);
static const key_input_t KEY_F = SINGLE_KEY("F", HID_KEY_F, 2);
static const key_input_t KEY_g = SINGLE_KEY("g", HID_KEY_G, 0);
static const key_input_t KEY_G = SINGLE_KEY("G", HID_KEY_G, 2);
static const key_input_t KEY_h = SINGLE_KEY("h", HID_KEY_H, 0);
static const key_input_t KEY_H = SINGLE_KEY("H", HID_KEY_H, 2);
static const key_input_t KEY_i = SINGLE_KEY("i", HID_KEY_I, 0);
static const key_input_t KEY_I = SINGLE_KEY("I", HID_KEY_I, 2);
static const key_input_t KEY_j = SINGLE_KEY("j", HID_KEY_J, 0);
static const key_input_t KEY_J = SINGLE_KEY("J", HID_KEY_J, 2);
static const key_input_t KEY_k = SINGLE_KEY("k", HID_KEY_K, 0);
static const key_input_t KEY_K = SINGLE_KEY("K", HID_KEY_K, 2);
static const key_input_t KEY_l = SINGLE_KEY("l", HID_KEY_L, 0);
static const key_input_t KEY_L = SINGLE_KEY("L", HID_KEY_L, 2);
static const key_input_t KEY_m = SINGLE_KEY("m", HID_KEY_M, 0);
static const key_input_t KEY_M = SINGLE_KEY("M", HID_KEY_M, 2);
static const key_input_t KEY_n = SINGLE_KEY("n", HID_KEY_N, 0);
static const key_input_t KEY_N = SINGLE_KEY("N", HID_KEY_N, 2);
static const key_input_t KEY_o = SINGLE_KEY("o", HID_KEY_O, 0);
static const key_input_t KEY_O = SINGLE_KEY("O", HID_KEY_O, 2);
static const key_input_t KEY_p = SINGLE_KEY("p", HID_KEY_P, 0);
static const key_input_t KEY_P = SINGLE_KEY("p", HID_KEY_P, 2);
static const key_input_t KEY_q = SINGLE_KEY("q", HID_KEY_Q, 0);
static const key_input_t KEY_Q = SINGLE_KEY("Q", HID_KEY_Q, 2);
static const key_input_t KEY_r = SINGLE_KEY("r", HID_KEY_R, 0);
static const key_input_t KEY_R = SINGLE_KEY("R", HID_KEY_R, 2);
static const key_input_t KEY_s = SINGLE_KEY("s", HID_KEY_S, 0);
static const key_input_t KEY_S = SINGLE_KEY("S", HID_KEY_S, 2);
static const key_input_t KEY_t = SINGLE_KEY("t", HID_KEY_T, 0);
static const key_input_t KEY_T = SINGLE_KEY("T", HID_KEY_T, 2);
static const key_input_t KEY_u = SINGLE_KEY("u", HID_KEY_U, 0);
static const key_input_t KEY_U = SINGLE_KEY("U", HID_KEY_U, 2);
static const key_input_t KEY_v = SINGLE_KEY("v", HID_KEY_V, 0);
static const key_input_t KEY_V = SINGLE_KEY("V", HID_KEY_V, 2);
static const key_input_t KEY_w = SINGLE_KEY("w", HID_KEY_W, 0);
static const key_input_t KEY_W = SINGLE_KEY("W", HID_KEY_W, 2);
static const key_input_t KEY_x = SINGLE_KEY("x", HID_KEY_X, 0);
static const key_input_t KEY_X = SINGLE_KEY("X", HID_KEY_X, 2);
static const key_input_t KEY_y = SINGLE_KEY("y", HID_KEY_Y, 0);
static const key_input_t KEY_Y = SINGLE_KEY("Y", HID_KEY_Y, 2);
static const key_input_t KEY_z = SINGLE_KEY("z", HID_KEY_Z, 0);
static const key_input_t KEY_Z = SINGLE_KEY("Z", HID_KEY_Z, 2);

static const key_input_t KEY_1 = SINGLE_KEY("1", HID_KEY_1, 0);
static const key_input_t KEY_EXCL_MARK = SINGLE_KEY("!", HID_KEY_1, 2);
static const key_input_t KEY_2 = SINGLE_KEY("2", HID_KEY_2, 0);
static const key_input_t KEY_ATMARK = SINGLE_KEY("@", HID_KEY_2, 2);
static const key_input_t KEY_3 = SINGLE_KEY("3", HID_KEY_3, 0);
static const key_input_t KEY_NUM_SIGN = SINGLE_KEY("#", HID_KEY_3, 2);
static const key_input_t KEY_4 = SINGLE_KEY("4", HID_KEY_4, 0);
static const key_input_t KEY_DOLLAR = SINGLE_KEY("$", HID_KEY_4, 2);
static const key_input_t KEY_5 = SINGLE_KEY("5", HID_KEY_5, 0);
static const key_input_t KEY_PERCENT = SINGLE_KEY("%", HID_KEY_5, 2);
static const key_input_t KEY_6 = SINGLE_KEY("6", HID_KEY_6, 0);
static const key_input_t KEY_CARET = SINGLE_KEY("^", HID_KEY_6, 2);
static const key_input_t KEY_7 = SINGLE_KEY("7", HID_KEY_7, 0);
static const key_input_t KEY_AMPERSAND = SINGLE_KEY("&", HID_KEY_7, 2);
static const key_input_t KEY_8 = SINGLE_KEY("8", HID_KEY_8, 0);
static const key_input_t KEY_ASTERISK = SINGLE_KEY("*", HID_KEY_8, 2);
static const key_input_t KEY_9 = SINGLE_KEY("9", HID_KEY_9, 0);
static const key_input_t KEY_LEFT_PAREN = SINGLE_KEY("(", HID_KEY_9, 2);
static const key_input_t KEY_0 = SINGLE_KEY("0", HID_KEY_0, 0);
static const key_input_t KEY_RIGHT_PAREN = SINGLE_KEY(")", HID_KEY_0, 2);

static const key_input_t KEY_RETURN = SINGLE_KEY("Enter", HID_KEY_RETURN, 0);
static const key_input_t KEY_ESCAPE = SINGLE_KEY("Escape", HID_KEY_ESCAPE, 0);
static const key_input_t KEY_DELETE = SINGLE_KEY("Backspace", HID_KEY_DELETE, 0);
static const key_input_t KEY_TAB = SINGLE_KEY("Tab", HID_KEY_TAB, 0);
static const key_input_t KEY_SPACEBAR = SINGLE_KEY("Spacebar", HID_KEY_SPACEBAR, 0);

static const key_input_t KEY_MINUS = SINGLE_KEY("-", HID_KEY_MINUS, 0);
static const key_input_t KEY_UNDERSCORE = SINGLE_KEY("_", HID_KEY_MINUS, 2);
static const key_input_t KEY_EQUAL = SINGLE_KEY("=", HID_KEY_EQUAL, 0);
static const key_input_t KEY_PLUS = SINGLE_KEY("+", HID_KEY_EQUAL, 2);
static const key_input_t KEY_LEFT_BRKT = SINGLE_KEY("[", HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEY_LEFT_BRACE = SINGLE_KEY("{", HID_KEY_LEFT_BRKT, 2);
static const key_input_t KEY_RIGHT_BRKT = SINGLE_KEY("]", HID_KEY_RIGHT_BRKT, 0);
static const key_input_t KEY_RIGHT_BRACE = SINGLE_KEY("}", HID_KEY_RIGHT_BRKT, 2);
static const key_input_t KEY_BACK_SLASH = SINGLE_KEY("\\", HID_KEY_BACK_SLASH, 0);
static const key_input_t KEY_VERT_BAR = SINGLE_KEY("|", HID_KEY_BACK_SLASH, 2);
static const key_input_t KEY_SEMI_COLON = SINGLE_KEY(";", HID_KEY_SEMI_COLON, 0);
static const key_input_t KEY_COLON = SINGLE_KEY(":", HID_KEY_SEMI_COLON, 2);
static const key_input_t KEY_SGL_QUOTE = SINGLE_KEY("'", HID_KEY_SGL_QUOTE, 0);
static const key_input_t KEY_DBL_QUOTE = SINGLE_KEY("\"", HID_KEY_SGL_QUOTE, 2);
static const key_input_t KEY_GRV_ACCENT = SINGLE_KEY("`", HID_KEY_GRV_ACCENT, 0);
static const key_input_t KEY_TILDE = SINGLE_KEY("~", HID_KEY_GRV_ACCENT, 2);
static const key_input_t KEY_COMMA = SINGLE_KEY(",", HID_KEY_COMMA, 0);
static const key_input_t KEY_LESS_THAN = SINGLE_KEY("<", HID_KEY_COMMA, 2);
static const key_input_t KEY_DOT = SINGLE_KEY(".", HID_KEY_DOT, 0);
static const key_input_t KEY_MORE_THAN = SINGLE_KEY(">", HID_KEY_DOT, 2);
static const key_input_t KEY_FWD_SLASH = SINGLE_KEY("/", HID_KEY_FWD_SLASH, 0);
static const key_input_t KEY_QUESTION = SINGLE_KEY("?", HID_KEY_FWD_SLASH, 2);

static const key_input_t KEY_CAPS_LOCK = SINGLE_KEY("Caps Lock", HID_KEY_CAPS_LOCK, 0);
static const key_input_t KEY_F1 = SINGLE_KEY("F1", HID_KEY_F1, 0);
static const key_input_t KEY_F2 = SINGLE_KEY("F2", HID_KEY_F2, 0);
static const key_input_t KEY_F3 = SINGLE_KEY("F3", HID_KEY_F3, 0);
static const key_input_t KEY_F4 = SINGLE_KEY("F4", HID_KEY_F4, 0);
static const key_input_t KEY_F5 = SINGLE_KEY("F5", HID_KEY_F5, 0);
static const key_input_t KEY_F6 = SINGLE_KEY("F6", HID_KEY_F6, 0);
static const key_input_t KEY_F7 = SINGLE_KEY("F7", HID_KEY_F7, 0);
static const key_input_t KEY_F8 = SINGLE_KEY("F8", HID_KEY_F8, 0);
static const key_input_t KEY_F9 = SINGLE_KEY("F9", HID_KEY_F9, 0);
static const key_input_t KEY_F10 = SINGLE_KEY("F10", HID_KEY_F10, 0);
static const key_input_t KEY_F11 = SINGLE_KEY("F11", HID_KEY_F11, 0);
static const key_input_t KEY_F12 = SINGLE_KEY("F12", HID_KEY_F12, 0);
static const key_input_t KEY_PRNT_SCREEN = SINGLE_KEY("Print Screen", HID_KEY_PRNT_SCREEN, 0);
static const key_input_t KEY_SCROLL_LOCK = SINGLE_KEY("Scroll Lock", HID_KEY_SCROLL_LOCK, 0);
static const key_input_t KEY_PAUSE = SINGLE_KEY("Pause", HID_KEY_PAUSE, 0);
static const key_input_t KEY_INSERT = SINGLE_KEY("Insert", HID_KEY_INSERT, 0);
static const key_input_t KEY_HOME = SINGLE_KEY("Home", HID_KEY_HOME, 0);
static const key_input_t KEY_PAGE_UP = SINGLE_KEY("PageUp", HID_KEY_PAGE_UP, 0);
static const key_input_t KEY_DELETE_FWD = SINGLE_KEY("Delete Forward", HID_KEY_DELETE_FWD, 0);
static const key_input_t KEY_END = SINGLE_KEY("End", HID_KEY_END, 0);
static const key_input_t KEY_PAGE_DOWN = SINGLE_KEY("PageDown", HID_KEY_PAGE_DOWN, 0);
static const key_input_t KEY_RIGHT_ARROW = SINGLE_KEY("RightArrow", HID_KEY_RIGHT_ARROW, 0);
static const key_input_t KEY_LEFT_ARROW = SINGLE_KEY("LeftArrow", HID_KEY_LEFT_ARROW, 0);
static const key_input_t KEY_DOWN_ARROW = SINGLE_KEY("DownArrow", HID_KEY_DOWN_ARROW, 0);
static const key_input_t KEY_UP_ARROW = SINGLE_KEY("UpArrow", HID_KEY_UP_ARROW, 0);

// Keypad
static const key_input_t KEY_NUM_LOCK = SINGLE_KEY("Num Lock", HID_KEY_NUM_LOCK, 0);
static const key_input_t KEY_DIVIDE = SINGLE_KEY("/", HID_KEY_DIVIDE, 0);
static const key_input_t KEY_MULTIPLY = SINGLE_KEY("*", HID_KEY_MULTIPLY, 0);
static const key_input_t KEY_SUBTRACT = SINGLE_KEY("-", HID_KEY_SUBTRACT, 0);
static const key_input_t KEY_ADD = SINGLE_KEY("+", HID_KEY_ADD, 0);
static const key_input_t KEY_ENTER = SINGLE_KEY("ENTER", HID_KEY_ENTER, 0);
static const key_input_t KEYPAD_1 = SINGLE_KEY("1", HID_KEYPAD_1, 0);
static const key_input_t KEYPAD_2 = SINGLE_KEY("2", HID_KEYPAD_2, 0);
static const key_input_t KEYPAD_3 = SINGLE_KEY("3", HID_KEYPAD_3, 0);
static const key_input_t KEYPAD_4 = SINGLE_KEY("4", HID_KEYPAD_4, 0);
static const key_input_t KEYPAD_5 = SINGLE_KEY("5", HID_KEYPAD_5, 0);
static const key_input_t KEYPAD_6 = SINGLE_KEY("6", HID_KEYPAD_6, 0);
static const key_input_t KEYPAD_7 = SINGLE_KEY("7", HID_KEYPAD_7, 0);
static const key_input_t KEYPAD_8 = SINGLE_KEY("8", HID_KEYPAD_8, 0);
static const key_input_t KEYPAD_9 = SINGLE_KEY("9", HID_KEYPAD_9, 0);
static const key_input_t KEYPAD_0 = SINGLE_KEY("0", HID_KEYPAD_0, 0);
static const key_input_t KEYPAD_DOT = SINGLE_KEY(".", HID_KEYPAD_DOT, 0);

static const key_input_t KEY_CHANGE_INPUT_MAC = SINGLE_KEY("⇔", HID_KEY_SPACEBAR, 1);

// US Kana Input
static const key_input_t KEYKANA_A = SINGLE_KEY("あ", HID_KEY_3, 0);
static const key_input_t KEYKANA_I = SINGLE_KEY("い", HID_KEY_E, 0);
static const key_input_t KEYKANA_U = SINGLE_KEY("う", HID_KEY_4, 0);
static const key_input_t KEYKANA_E = SINGLE_KEY("え", HID_KEY_5, 0);
static const key_input_t KEYKANA_O = SINGLE_KEY("お", HID_KEY_6, 0);

static const key_input_t KEYKANA_XA = SINGLE_KEY("ぁ", HID_KEY_3, 2);
static const key_input_t KEYKANA_XI = SINGLE_KEY("ぃ", HID_KEY_E, 2);
static const key_input_t KEYKANA_XU = SINGLE_KEY("ぅ", HID_KEY_4, 2);
static const key_input_t KEYKANA_XE = SINGLE_KEY("ぇ", HID_KEY_5, 2);
static const key_input_t KEYKANA_XO = SINGLE_KEY("ぉ", HID_KEY_6, 2);

static const key_input_t KEYKANA_KA = SINGLE_KEY("か", HID_KEY_T, 0);
static const key_input_t KEYKANA_KI = SINGLE_KEY("き", HID_KEY_G, 0);
static const key_input_t KEYKANA_KU = SINGLE_KEY("く", HID_KEY_H, 0);
static const key_input_t KEYKANA_KE = SINGLE_KEY("け", HID_KEY_SGL_QUOTE, 0);
static const key_input_t KEYKANA_KO = SINGLE_KEY("こ", HID_KEY_B, 0);

static const key_input_t KEYKANA_GA = MULTI_KEY2("が", HID_KEY_T, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_GI = MULTI_KEY2("ぎ", HID_KEY_G, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_GU = MULTI_KEY2("ぐ", HID_KEY_H, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_GE = MULTI_KEY2("げ", HID_KEY_SGL_QUOTE, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_GO = MULTI_KEY2("ご", HID_KEY_B, HID_KEY_LEFT_BRKT, 0);

static const key_input_t KEYKANA_SA = SINGLE_KEY("さ", HID_KEY_X, 0);
static const key_input_t KEYKANA_SI = SINGLE_KEY("し", HID_KEY_D, 0);
static const key_input_t KEYKANA_SU = SINGLE_KEY("す", HID_KEY_R, 0);
static const key_input_t KEYKANA_SE = SINGLE_KEY("せ", HID_KEY_P, 0);
static const key_input_t KEYKANA_SO = SINGLE_KEY("そ", HID_KEY_C, 0);

static const key_input_t KEYKANA_ZA = MULTI_KEY2("ざ", HID_KEY_X, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_ZI = MULTI_KEY2("じ", HID_KEY_D, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_ZU = MULTI_KEY2("ず", HID_KEY_R, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_ZE = MULTI_KEY2("ぜ", HID_KEY_P, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_ZO = MULTI_KEY2("ぞ", HID_KEY_C, HID_KEY_LEFT_BRKT, 0);

static const key_input_t KEYKANA_TA = SINGLE_KEY("た", HID_KEY_Q, 0);
static const key_input_t KEYKANA_TI = SINGLE_KEY("ち", HID_KEY_A, 0);
static const key_input_t KEYKANA_TU = SINGLE_KEY("つ", HID_KEY_Z, 0);
static const key_input_t KEYKANA_TE = SINGLE_KEY("て", HID_KEY_W, 0);
static const key_input_t KEYKANA_TO = SINGLE_KEY("と", HID_KEY_S, 0);

static const key_input_t KEYKANA_DA = MULTI_KEY2("だ", HID_KEY_Q, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_DI = MULTI_KEY2("ぢ", HID_KEY_A, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_DU = MULTI_KEY2("づ", HID_KEY_Z, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_DE = MULTI_KEY2("で", HID_KEY_W, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_DO = MULTI_KEY2("ど", HID_KEY_S, HID_KEY_LEFT_BRKT, 0);

static const key_input_t KEYKANA_XTU = SINGLE_KEY("っ", HID_KEY_Z, 2);

static const key_input_t KEYKANA_NA = SINGLE_KEY("な", HID_KEY_U, 0);
static const key_input_t KEYKANA_NI = SINGLE_KEY("に", HID_KEY_I, 0);
static const key_input_t KEYKANA_NU = SINGLE_KEY("ぬ", HID_KEY_1, 0);
static const key_input_t KEYKANA_NE = SINGLE_KEY("ね", HID_KEY_COMMA, 0);
static const key_input_t KEYKANA_NO = SINGLE_KEY("の", HID_KEY_K, 0);

static const key_input_t KEYKANA_HA = SINGLE_KEY("は", HID_KEY_F, 0);
static const key_input_t KEYKANA_HI = SINGLE_KEY("ひ", HID_KEY_V, 0);
static const key_input_t KEYKANA_HU = SINGLE_KEY("ふ", HID_KEY_2, 0);
static const key_input_t KEYKANA_HE = SINGLE_KEY("へ", HID_KEY_BACK_SLASH, 0);
static const key_input_t KEYKANA_HO = SINGLE_KEY("ほ", HID_KEY_MINUS, 0);

static const key_input_t KEYKANA_BA = MULTI_KEY2("ば", HID_KEY_F, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_BI = MULTI_KEY2("び", HID_KEY_V, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_BU = MULTI_KEY2("ぶ", HID_KEY_2, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_BE = MULTI_KEY2("べ", HID_KEY_BACK_SLASH, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_BO = MULTI_KEY2("ぼ", HID_KEY_MINUS, HID_KEY_LEFT_BRKT, 0);

static const key_input_t KEYKANA_PA = MULTI_KEY2("ぱ", HID_KEY_F, HID_KEY_EQUAL, 0);
static const key_input_t KEYKANA_PI = MULTI_KEY2("ぴ", HID_KEY_V, HID_KEY_EQUAL, 0);
static const key_input_t KEYKANA_PU = MULTI_KEY2("ぷ", HID_KEY_2, HID_KEY_EQUAL, 0);
static const key_input_t KEYKANA_PE = MULTI_KEY2("ぺ", HID_KEY_BACK_SLASH, HID_KEY_EQUAL, 0);
static const key_input_t KEYKANA_PO = MULTI_KEY2("ぽ", HID_KEY_MINUS, HID_KEY_EQUAL, 0);

static const key_input_t KEYKANA_MA = SINGLE_KEY("ま", HID_KEY_J, 0);
static const key_input_t KEYKANA_MI = SINGLE_KEY("み", HID_KEY_N, 0);
static const key_input_t KEYKANA_MU = SINGLE_KEY("む", HID_KEY_RIGHT_BRKT, 0);
static const key_input_t KEYKANA_ME = SINGLE_KEY("め", HID_KEY_FWD_SLASH, 0);
static const key_input_t KEYKANA_MO = SINGLE_KEY("も", HID_KEY_M, 0);

static const key_input_t KEYKANA_YA = SINGLE_KEY("や", HID_KEY_7, 0);
static const key_input_t KEYKANA_YU = SINGLE_KEY("ゆ", HID_KEY_8, 0);
static const key_input_t KEYKANA_YO = SINGLE_KEY("よ", HID_KEY_9, 0);

static const key_input_t KEYKANA_XYA = SINGLE_KEY("ゃ", HID_KEY_7, 2);
static const key_input_t KEYKANA_XYU = SINGLE_KEY("ゅ", HID_KEY_8, 2);
static const key_input_t KEYKANA_XYO = SINGLE_KEY("ょ", HID_KEY_9, 2);

static const key_input_t KEYKANA_RA = SINGLE_KEY("ら", HID_KEY_O, 0);
static const key_input_t KEYKANA_RI = SINGLE_KEY("り", HID_KEY_L, 0);
static const key_input_t KEYKANA_RU = SINGLE_KEY("る", HID_KEY_DOT, 0);
static const key_input_t KEYKANA_RE = SINGLE_KEY("れ", HID_KEY_SEMI_COLON, 0);
static const key_input_t KEYKANA_RO = SINGLE_KEY("ろ", HID_KEY_SGL_QUOTE, 2);

static const key_input_t KEYKANA_WA = SINGLE_KEY("わ", HID_KEY_0, 0);
static const key_input_t KEYKANA_WO = SINGLE_KEY("を", HID_KEY_0, 2);
static const key_input_t KEYKANA_NN = SINGLE_KEY("ん", HID_KEY_Y, 0);

static const key_input_t KEYKANA_DAKUTEN = SINGLE_KEY("゛", HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYKANA_HAN_DAKUTEN = SINGLE_KEY("゜", HID_KEY_EQUAL, 0);
static const key_input_t KEYKANA_KAKKO_TOJI = SINGLE_KEY("」", HID_KEY_LEFT_BRKT, 2);
static const key_input_t KEYKANA_KAKKO = SINGLE_KEY("「", HID_KEY_EQUAL, 2);
static const key_input_t KEYKANA_BACKQUOTE = SINGLE_KEY("｀", HID_KEY_GRV_ACCENT, 0);
static const key_input_t KEYKANA_NAMI_DASH = SINGLE_KEY("〜", HID_KEY_GRV_ACCENT, 2);
static const key_input_t KEYKANA_DASH = SINGLE_KEY("ー", HID_KEY_RIGHT_BRKT, 2);
static const key_input_t KEYKANA_TOUTEN = SINGLE_KEY("、", HID_KEY_COMMA, 2);
static const key_input_t KEYKANA_KUTEN = SINGLE_KEY("。", HID_KEY_DOT, 2);
static const key_input_t KEYKANA_NAKAGURO = SINGLE_KEY("・", HID_KEY_FWD_SLASH, 2);
static const key_input_t KEYKANA_QUESTION = SINGLE_KEY("？", HID_KEY_FWD_SLASH, 6);

static const key_input_t KEYKANA_EXCL_MARK = SINGLE_KEY("！", HID_KEY_1, 6);
static const key_input_t KEYKANA_ATMARK = SINGLE_KEY("＠", HID_KEY_2, 6);
static const key_input_t KEYKANA_NUM_SIGN = SINGLE_KEY("＃", HID_KEY_3, 6);
static const key_input_t KEYKANA_DOLLAR = SINGLE_KEY("＄", HID_KEY_4, 6);
static const key_input_t KEYKANA_PERCENT = SINGLE_KEY("％", HID_KEY_5, 6);
static const key_input_t KEYKANA_CARET = SINGLE_KEY("＾", HID_KEY_6, 6);
static const key_input_t KEYKANA_AMPERSAND = SINGLE_KEY("＆", HID_KEY_7, 6);
static const key_input_t KEYKANA_ASTERISK = SINGLE_KEY("＊", HID_KEY_8, 6);
static const key_input_t KEYKANA_LEFT_PAREN = SINGLE_KEY("（", HID_KEY_9, 6);
static const key_input_t KEYKANA_RIGHT_PAREN = SINGLE_KEY("）", HID_KEY_0, 6);

// Input method keys
#define HID_KEY_LANG1 0x90 // Kana
#define HID_KEY_LANG2 0x91 // Eisu
static const key_input_t KEY_KANA_INPUT = SINGLE_KEY("かな", HID_KEY_LANG1, 0);
static const key_input_t KEY_EISU_INPUT = SINGLE_KEY("英数", HID_KEY_LANG2, 0);

// US Roma-ji input
static const key_input_t KEYROMAN_A = SINGLE_KEY("あ", HID_KEY_A, 0);
static const key_input_t KEYROMAN_I = SINGLE_KEY("い", HID_KEY_I, 0);
static const key_input_t KEYROMAN_U = SINGLE_KEY("う", HID_KEY_U, 0);
static const key_input_t KEYROMAN_E = SINGLE_KEY("え", HID_KEY_E, 0);
static const key_input_t KEYROMAN_O = SINGLE_KEY("お", HID_KEY_O, 0);

static const key_input_t KEYROMAN_XA = MULTI_KEY2("ぁ", HID_KEY_X, HID_KEY_A, 0);
static const key_input_t KEYROMAN_XI = MULTI_KEY2("ぃ", HID_KEY_X, HID_KEY_I, 0);
static const key_input_t KEYROMAN_XU = MULTI_KEY2("ぅ", HID_KEY_X, HID_KEY_U, 0);
static const key_input_t KEYROMAN_XE = MULTI_KEY2("ぇ", HID_KEY_X, HID_KEY_E, 0);
static const key_input_t KEYROMAN_XO = MULTI_KEY2("ぉ", HID_KEY_X, HID_KEY_O, 0);

static const key_input_t KEYROMAN_KA = MULTI_KEY2("か", HID_KEY_K, HID_KEY_A, 0);
static const key_input_t KEYROMAN_KI = MULTI_KEY2("き", HID_KEY_K, HID_KEY_I, 0);
static const key_input_t KEYROMAN_KU = MULTI_KEY2("く", HID_KEY_K, HID_KEY_U, 0);
static const key_input_t KEYROMAN_KE = MULTI_KEY2("け", HID_KEY_K, HID_KEY_E, 0);
static const key_input_t KEYROMAN_KO = MULTI_KEY2("こ", HID_KEY_K, HID_KEY_O, 0);

static const key_input_t KEYROMAN_GA = MULTI_KEY2("が", HID_KEY_G, HID_KEY_A, 0);
static const key_input_t KEYROMAN_GI = MULTI_KEY2("ぎ", HID_KEY_G, HID_KEY_I, 0);
static const key_input_t KEYROMAN_GU = MULTI_KEY2("ぐ", HID_KEY_G, HID_KEY_U, 0);
static const key_input_t KEYROMAN_GE = MULTI_KEY2("げ", HID_KEY_G, HID_KEY_E, 0);
static const key_input_t KEYROMAN_GO = MULTI_KEY2("ご", HID_KEY_G, HID_KEY_O, 0);

static const key_input_t KEYROMAN_SA = MULTI_KEY2("さ", HID_KEY_S, HID_KEY_A, 0);
static const key_input_t KEYROMAN_SI = MULTI_KEY2("し", HID_KEY_S, HID_KEY_I, 0);
static const key_input_t KEYROMAN_SU = MULTI_KEY2("す", HID_KEY_S, HID_KEY_U, 0);
static const key_input_t KEYROMAN_SE = MULTI_KEY2("せ", HID_KEY_S, HID_KEY_E, 0);
static const key_input_t KEYROMAN_SO = MULTI_KEY2("そ", HID_KEY_S, HID_KEY_O, 0);

static const key_input_t KEYROMAN_ZA = MULTI_KEY2("ざ", HID_KEY_Z, HID_KEY_A, 0);
static const key_input_t KEYROMAN_ZI = MULTI_KEY2("じ", HID_KEY_Z, HID_KEY_I, 0);
static const key_input_t KEYROMAN_ZU = MULTI_KEY2("ず", HID_KEY_Z, HID_KEY_U, 0);
static const key_input_t KEYROMAN_ZE = MULTI_KEY2("ぜ", HID_KEY_Z, HID_KEY_E, 0);
static const key_input_t KEYROMAN_ZO = MULTI_KEY2("ぞ", HID_KEY_Z, HID_KEY_O, 0);

static const key_input_t KEYROMAN_TA = MULTI_KEY2("た", HID_KEY_T, HID_KEY_A, 0);
static const key_input_t KEYROMAN_TI = MULTI_KEY2("ち", HID_KEY_T, HID_KEY_I, 0);
static const key_input_t KEYROMAN_TU = MULTI_KEY2("つ", HID_KEY_T, HID_KEY_U, 0);
static const key_input_t KEYROMAN_TE = MULTI_KEY2("て", HID_KEY_T, HID_KEY_E, 0);
static const key_input_t KEYROMAN_TO = MULTI_KEY2("と", HID_KEY_T, HID_KEY_O, 0);

static const key_input_t KEYROMAN_DA = MULTI_KEY2("だ", HID_KEY_D, HID_KEY_A, 0);
static const key_input_t KEYROMAN_DI = MULTI_KEY2("ぢ", HID_KEY_D, HID_KEY_I, 0);
static const key_input_t KEYROMAN_DU = MULTI_KEY2("づ", HID_KEY_D, HID_KEY_U, 0);
static const key_input_t KEYROMAN_DE = MULTI_KEY2("で", HID_KEY_D, HID_KEY_E, 0);
static const key_input_t KEYROMAN_DO = MULTI_KEY2("ど", HID_KEY_D, HID_KEY_O, 0);

static const key_input_t KEYROMAN_XTU = MULTI_KEY3("っ", HID_KEY_X, HID_KEY_T, HID_KEY_U, 0);

static const key_input_t KEYROMAN_NA = MULTI_KEY2("な", HID_KEY_N, HID_KEY_A, 0);
static const key_input_t KEYROMAN_NI = MULTI_KEY2("に", HID_KEY_N, HID_KEY_I, 0);
static const key_input_t KEYROMAN_NU = MULTI_KEY2("ぬ", HID_KEY_N, HID_KEY_U, 0);
static const key_input_t KEYROMAN_NE = MULTI_KEY2("ね", HID_KEY_N, HID_KEY_E, 0);
static const key_input_t KEYROMAN_NO = MULTI_KEY2("の", HID_KEY_N, HID_KEY_O, 0);

static const key_input_t KEYROMAN_HA = MULTI_KEY2("は", HID_KEY_H, HID_KEY_A, 0);
static const key_input_t KEYROMAN_HI = MULTI_KEY2("ひ", HID_KEY_H, HID_KEY_I, 0);
static const key_input_t KEYROMAN_HU = MULTI_KEY2("ふ", HID_KEY_H, HID_KEY_U, 0);
static const key_input_t KEYROMAN_HE = MULTI_KEY2("へ", HID_KEY_H, HID_KEY_E, 0);
static const key_input_t KEYROMAN_HO = MULTI_KEY2("ほ", HID_KEY_H, HID_KEY_O, 0);

static const key_input_t KEYROMAN_BA = MULTI_KEY2("ば", HID_KEY_B, HID_KEY_A, 0);
static const key_input_t KEYROMAN_BI = MULTI_KEY2("び", HID_KEY_B, HID_KEY_I, 0);
static const key_input_t KEYROMAN_BU = MULTI_KEY2("ぶ", HID_KEY_B, HID_KEY_U, 0);
static const key_input_t KEYROMAN_BE = MULTI_KEY2("べ", HID_KEY_B, HID_KEY_E, 0);
static const key_input_t KEYROMAN_BO = MULTI_KEY2("ぼ", HID_KEY_B, HID_KEY_O, 0);

static const key_input_t KEYROMAN_PA = MULTI_KEY2("ぱ", HID_KEY_P, HID_KEY_A, 0);
static const key_input_t KEYROMAN_PI = MULTI_KEY2("ぴ", HID_KEY_P, HID_KEY_I, 0);
static const key_input_t KEYROMAN_PU = MULTI_KEY2("ぷ", HID_KEY_P, HID_KEY_U, 0);
static const key_input_t KEYROMAN_PE = MULTI_KEY2("ぺ", HID_KEY_P, HID_KEY_E, 0);
static const key_input_t KEYROMAN_PO = MULTI_KEY2("ぽ", HID_KEY_P, HID_KEY_O, 0);

static const key_input_t KEYROMAN_MA = MULTI_KEY2("ま", HID_KEY_M, HID_KEY_A, 0);
static const key_input_t KEYROMAN_MI = MULTI_KEY2("み", HID_KEY_M, HID_KEY_I, 0);
static const key_input_t KEYROMAN_MU = MULTI_KEY2("む", HID_KEY_M, HID_KEY_U, 0);
static const key_input_t KEYROMAN_ME = MULTI_KEY2("め", HID_KEY_M, HID_KEY_E, 0);
static const key_input_t KEYROMAN_MO = MULTI_KEY2("も", HID_KEY_M, HID_KEY_O, 0);

static const key_input_t KEYROMAN_YA = MULTI_KEY2("や", HID_KEY_Y, HID_KEY_A, 0);
static const key_input_t KEYROMAN_YU = MULTI_KEY2("ゆ", HID_KEY_Y, HID_KEY_U, 0);
static const key_input_t KEYROMAN_YO = MULTI_KEY2("よ", HID_KEY_Y, HID_KEY_O, 0);

static const key_input_t KEYROMAN_XYA = MULTI_KEY3("ゃ", HID_KEY_X, HID_KEY_Y, HID_KEY_A, 0);
static const key_input_t KEYROMAN_XYU = MULTI_KEY3("ゅ", HID_KEY_X, HID_KEY_Y, HID_KEY_U, 0);
static const key_input_t KEYROMAN_XYO = MULTI_KEY3("ょ", HID_KEY_X, HID_KEY_Y, HID_KEY_O, 0);

static const key_input_t KEYROMAN_RA = MULTI_KEY2("ら", HID_KEY_R, HID_KEY_A, 0);
static const key_input_t KEYROMAN_RI = MULTI_KEY2("り", HID_KEY_R, HID_KEY_I, 0);
static const key_input_t KEYROMAN_RU = MULTI_KEY2("る", HID_KEY_R, HID_KEY_U, 0);
static const key_input_t KEYROMAN_RE = MULTI_KEY2("れ", HID_KEY_R, HID_KEY_E, 0);
static const key_input_t KEYROMAN_RO = MULTI_KEY2("ろ", HID_KEY_R, HID_KEY_O, 0);

static const key_input_t KEYROMAN_WA = MULTI_KEY2("わ", HID_KEY_W, HID_KEY_A, 0);
static const key_input_t KEYROMAN_WO = MULTI_KEY2("を", HID_KEY_W, HID_KEY_O, 0);
static const key_input_t KEYROMAN_NN = MULTI_KEY2("ん", HID_KEY_N, HID_KEY_N, 0);

static const key_input_t KEYROMAN_KAKKO_TOJI = SINGLE_KEY("」", HID_KEY_RIGHT_BRKT, 0);
static const key_input_t KEYROMAN_KAKKO = SINGLE_KEY("「", HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYROMAN_BACKQUOTE = SINGLE_KEY("｀", HID_KEY_GRV_ACCENT, 0);
static const key_input_t KEYROMAN_NAMI_DASH = SINGLE_KEY("〜", HID_KEY_GRV_ACCENT, 2);
static const key_input_t KEYROMAN_DASH = SINGLE_KEY("ー", HID_KEY_MINUS, 0);
static const key_input_t KEYROMAN_TOUTEN = SINGLE_KEY("、", HID_KEY_COMMA, 0);
static const key_input_t KEYROMAN_KUTEN = SINGLE_KEY("。", HID_KEY_DOT, 0);
static const key_input_t KEYROMAN_NAKAGURO = SINGLE_KEY("・", HID_KEY_FWD_SLASH, 0);
static const key_input_t KEYROMAN_QUESTION = SINGLE_KEY("？", HID_KEY_FWD_SLASH, 2);

static const key_input_t KEYROMAN_EXCL_MARK = SINGLE_KEY("！", HID_KEY_1, 2);
static const key_input_t KEYROMAN_ATMARK = SINGLE_KEY("＠", HID_KEY_2, 2);
static const key_input_t KEYROMAN_NUM_SIGN = SINGLE_KEY("＃", HID_KEY_3, 2);
static const key_input_t KEYROMAN_DOLLAR = SINGLE_KEY("＄", HID_KEY_4, 2);
static const key_input_t KEYROMAN_PERCENT = SINGLE_KEY("％", HID_KEY_5, 2);
static const key_input_t KEYROMAN_CARET = SINGLE_KEY("＾", HID_KEY_6, 2);
static const key_input_t KEYROMAN_AMPERSAND = SINGLE_KEY("＆", HID_KEY_7, 2);
static const key_input_t KEYROMAN_ASTERISK = SINGLE_KEY("＊", HID_KEY_8, 2);
static const key_input_t KEYROMAN_LEFT_PAREN = SINGLE_KEY("（", HID_KEY_9, 2);
static const key_input_t KEYROMAN_RIGHT_PAREN = SINGLE_KEY("）", HID_KEY_0, 2);