#pragma once
#include <M5Unified.h>
#include "hid_dev.h"

typedef struct key_input
{
  std::string text;
  uint8_t keycode;
  uint8_t modifier;
  uint8_t second_keycode;
  uint8_t second_modifier;
} key_input_t;

#define SINGLE_KEY(label, keycode, modifier) \
  {                                          \
    label, keycode, modifier, 0, 0           \
  }

#define MULTI_KEY(label, keycode1, modifier1, keycode2, modifier2) \
  {                                                                \
    label, keycode1, modifier1, keycode2, modifier2                \
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

// US MAC Kana Input
static const key_input_t KEYJP_A = SINGLE_KEY("あ", HID_KEY_3, 0);
static const key_input_t KEYJP_I = SINGLE_KEY("い", HID_KEY_E, 0);
static const key_input_t KEYJP_U = SINGLE_KEY("う", HID_KEY_4, 0);
static const key_input_t KEYJP_E = SINGLE_KEY("え", HID_KEY_5, 0);
static const key_input_t KEYJP_O = SINGLE_KEY("お", HID_KEY_6, 0);

static const key_input_t KEYJP_XA = SINGLE_KEY("ぁ", HID_KEY_3, 2);
static const key_input_t KEYJP_XI = SINGLE_KEY("ぃ", HID_KEY_E, 2);
static const key_input_t KEYJP_XU = SINGLE_KEY("ぅ", HID_KEY_4, 2);
static const key_input_t KEYJP_XE = SINGLE_KEY("ぇ", HID_KEY_5, 2);
static const key_input_t KEYJP_XO = SINGLE_KEY("ぉ", HID_KEY_6, 2);

static const key_input_t KEYJP_KA = SINGLE_KEY("か", HID_KEY_T, 0);
static const key_input_t KEYJP_KI = SINGLE_KEY("き", HID_KEY_G, 0);
static const key_input_t KEYJP_KU = SINGLE_KEY("く", HID_KEY_H, 0);
static const key_input_t KEYJP_KE = SINGLE_KEY("け", HID_KEY_SGL_QUOTE, 0);
static const key_input_t KEYJP_KO = SINGLE_KEY("こ", HID_KEY_B, 0);

static const key_input_t KEYJP_GA = MULTI_KEY("が", HID_KEY_T, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_GI = MULTI_KEY("ぎ", HID_KEY_G, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_GU = MULTI_KEY("ぐ", HID_KEY_H, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_GE = MULTI_KEY("げ", HID_KEY_SGL_QUOTE, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_GO = MULTI_KEY("ご", HID_KEY_B, 0, HID_KEY_LEFT_BRKT, 0);

static const key_input_t KEYJP_SA = SINGLE_KEY("さ", HID_KEY_X, 0);
static const key_input_t KEYJP_SI = SINGLE_KEY("し", HID_KEY_D, 0);
static const key_input_t KEYJP_SU = SINGLE_KEY("す", HID_KEY_R, 0);
static const key_input_t KEYJP_SE = SINGLE_KEY("せ", HID_KEY_P, 0);
static const key_input_t KEYJP_SO = SINGLE_KEY("そ", HID_KEY_C, 0);

static const key_input_t KEYJP_ZA = MULTI_KEY("ざ", HID_KEY_X, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_ZI = MULTI_KEY("じ", HID_KEY_D, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_ZU = MULTI_KEY("ず", HID_KEY_R, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_ZE = MULTI_KEY("ぜ", HID_KEY_P, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_ZO = MULTI_KEY("ぞ", HID_KEY_C, 0, HID_KEY_LEFT_BRKT, 0);

static const key_input_t KEYJP_TA = SINGLE_KEY("た", HID_KEY_Q, 0);
static const key_input_t KEYJP_TI = SINGLE_KEY("ち", HID_KEY_A, 0);
static const key_input_t KEYJP_TU = SINGLE_KEY("つ", HID_KEY_Z, 0);
static const key_input_t KEYJP_TE = SINGLE_KEY("て", HID_KEY_W, 0);
static const key_input_t KEYJP_TO = SINGLE_KEY("と", HID_KEY_S, 0);

static const key_input_t KEYJP_DA = MULTI_KEY("だ", HID_KEY_Q, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_DI = MULTI_KEY("ぢ", HID_KEY_A, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_DU = MULTI_KEY("づ", HID_KEY_Z, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_DE = MULTI_KEY("で", HID_KEY_W, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_DO = MULTI_KEY("ど", HID_KEY_S, 0, HID_KEY_LEFT_BRKT, 0);

static const key_input_t KEYJP_XTU = SINGLE_KEY("っ", HID_KEY_Z, 2);

static const key_input_t KEYJP_NA = SINGLE_KEY("な", HID_KEY_U, 0);
static const key_input_t KEYJP_NI = SINGLE_KEY("に", HID_KEY_I, 0);
static const key_input_t KEYJP_NU = SINGLE_KEY("ぬ", HID_KEY_1, 0);
static const key_input_t KEYJP_NE = SINGLE_KEY("ね", HID_KEY_COMMA, 0);
static const key_input_t KEYJP_NO = SINGLE_KEY("の", HID_KEY_K, 0);

static const key_input_t KEYJP_HA = SINGLE_KEY("は", HID_KEY_F, 0);
static const key_input_t KEYJP_HI = SINGLE_KEY("ひ", HID_KEY_V, 0);
static const key_input_t KEYJP_HU = SINGLE_KEY("ふ", HID_KEY_2, 0);
static const key_input_t KEYJP_HE = SINGLE_KEY("へ", HID_KEY_BACK_SLASH, 0);
static const key_input_t KEYJP_HO = SINGLE_KEY("ほ", HID_KEY_MINUS, 0);

static const key_input_t KEYJP_BA = MULTI_KEY("ば", HID_KEY_F, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_BI = MULTI_KEY("び", HID_KEY_V, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_BU = MULTI_KEY("ぶ", HID_KEY_2, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_BE = MULTI_KEY("べ", HID_KEY_BACK_SLASH, 0, HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_BO = MULTI_KEY("ぼ", HID_KEY_MINUS, 0, HID_KEY_LEFT_BRKT, 0);

static const key_input_t KEYJP_PA = MULTI_KEY("ぱ", HID_KEY_F, 0, HID_KEY_EQUAL, 0);
static const key_input_t KEYJP_PI = MULTI_KEY("ぴ", HID_KEY_V, 0, HID_KEY_EQUAL, 0);
static const key_input_t KEYJP_PU = MULTI_KEY("ぷ", HID_KEY_2, 0, HID_KEY_EQUAL, 0);
static const key_input_t KEYJP_PE = MULTI_KEY("ぺ", HID_KEY_BACK_SLASH, 0, HID_KEY_EQUAL, 0);
static const key_input_t KEYJP_PO = MULTI_KEY("ぽ", HID_KEY_MINUS, 0, HID_KEY_EQUAL, 0);

static const key_input_t KEYJP_MA = SINGLE_KEY("ま", HID_KEY_J, 0);
static const key_input_t KEYJP_MI = SINGLE_KEY("み", HID_KEY_N, 0);
static const key_input_t KEYJP_MU = SINGLE_KEY("む", HID_KEY_RIGHT_BRKT, 0);
static const key_input_t KEYJP_ME = SINGLE_KEY("め", HID_KEY_FWD_SLASH, 0);
static const key_input_t KEYJP_MO = SINGLE_KEY("も", HID_KEY_M, 0);

static const key_input_t KEYJP_YA = SINGLE_KEY("や", HID_KEY_7, 0);
static const key_input_t KEYJP_YU = SINGLE_KEY("ゆ", HID_KEY_8, 0);
static const key_input_t KEYJP_YO = SINGLE_KEY("よ", HID_KEY_9, 0);

static const key_input_t KEYJP_XYA = SINGLE_KEY("ゃ", HID_KEY_7, 2);
static const key_input_t KEYJP_XYU = SINGLE_KEY("ゅ", HID_KEY_8, 2);
static const key_input_t KEYJP_XYO = SINGLE_KEY("ょ", HID_KEY_9, 2);

static const key_input_t KEYJP_RA = SINGLE_KEY("ら", HID_KEY_O, 0);
static const key_input_t KEYJP_RI = SINGLE_KEY("り", HID_KEY_L, 0);
static const key_input_t KEYJP_RU = SINGLE_KEY("る", HID_KEY_DOT, 0);
static const key_input_t KEYJP_RE = SINGLE_KEY("れ", HID_KEY_SEMI_COLON, 0);
static const key_input_t KEYJP_RO = SINGLE_KEY("ろ", HID_KEY_SGL_QUOTE, 2);

static const key_input_t KEYJP_WA = SINGLE_KEY("わ", HID_KEY_0, 0);
static const key_input_t KEYJP_WO = SINGLE_KEY("を", HID_KEY_0, 2);
static const key_input_t KEYJP_NN = SINGLE_KEY("ん", HID_KEY_Y, 0);

static const key_input_t KEYJP_DAKUTEN = SINGLE_KEY("゛", HID_KEY_LEFT_BRKT, 0);
static const key_input_t KEYJP_HAN_DAKUTEN = SINGLE_KEY("゜", HID_KEY_EQUAL, 0);
static const key_input_t KEYJP_KAKKO_TOJI = SINGLE_KEY("」", HID_KEY_LEFT_BRKT, 2);
static const key_input_t KEYJP_KAKKO = SINGLE_KEY("「", HID_KEY_EQUAL, 2);
static const key_input_t KEYJP_BACKQUOTE = SINGLE_KEY("｀", HID_KEY_GRV_ACCENT, 0);
static const key_input_t KEYJP_NAMI_DASH = SINGLE_KEY("〜", HID_KEY_GRV_ACCENT, 2);
static const key_input_t KEYJP_DASH = SINGLE_KEY("ー", HID_KEY_RIGHT_BRKT, 2);
static const key_input_t KEYJP_TOUTEN = SINGLE_KEY("、", HID_KEY_COMMA, 2);
static const key_input_t KEYJP_KUTEN = SINGLE_KEY("。", HID_KEY_DOT, 2);
static const key_input_t KEYJP_NAKAGURO = SINGLE_KEY("・", HID_KEY_FWD_SLASH, 2);
static const key_input_t KEYJP_QUESTION = SINGLE_KEY("？", HID_KEY_FWD_SLASH, 6);

static const key_input_t KEYJP_EXCL_MARK = SINGLE_KEY("！", HID_KEY_1, 6);
static const key_input_t KEYJP_ATMARK = SINGLE_KEY("＠", HID_KEY_2, 6);
static const key_input_t KEYJP_NUM_SIGN = SINGLE_KEY("＃", HID_KEY_3, 6);
static const key_input_t KEYJP_DOLLAR = SINGLE_KEY("＄", HID_KEY_4, 6);
static const key_input_t KEYJP_PERCENT = SINGLE_KEY("％", HID_KEY_5, 6);
static const key_input_t KEYJP_CARET = SINGLE_KEY("＾", HID_KEY_6, 6);
static const key_input_t KEYJP_AMPERSAND = SINGLE_KEY("＆", HID_KEY_7, 6);
static const key_input_t KEYJP_ASTERISK = SINGLE_KEY("＊", HID_KEY_8, 6);
static const key_input_t KEYJP_LEFT_PAREN = SINGLE_KEY("（", HID_KEY_9, 6);
static const key_input_t KEYJP_RIGHT_PAREN = SINGLE_KEY("）", HID_KEY_0, 6);

#define HID_KEY_LANG1 0x90 // Kana
#define HID_KEY_LANG2 0x91 // Eisu