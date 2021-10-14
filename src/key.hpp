#pragma once
#include <M5Unified.h>
#include "hid_dev.h"

typedef struct key_input
{
  std::string text;
  uint8_t keycode;
  uint8_t modifier;
} key_input_t;

static const key_input_t KEY_a = {"a", HID_KEY_A, 0};
static const key_input_t KEY_A = {"A", HID_KEY_A, 2};
static const key_input_t KEY_b = {"b", HID_KEY_B, 0};
static const key_input_t KEY_B = {"B", HID_KEY_B, 2};
static const key_input_t KEY_c = {"c", HID_KEY_C, 0};
static const key_input_t KEY_C = {"C", HID_KEY_C, 2};
static const key_input_t KEY_d = {"d", HID_KEY_D, 0};
static const key_input_t KEY_D = {"D", HID_KEY_D, 2};
static const key_input_t KEY_e = {"e", HID_KEY_E, 0};
static const key_input_t KEY_E = {"E", HID_KEY_E, 2};
static const key_input_t KEY_f = {"f", HID_KEY_F, 0};
static const key_input_t KEY_F = {"F", HID_KEY_F, 2};
static const key_input_t KEY_g = {"g", HID_KEY_G, 0};
static const key_input_t KEY_G = {"G", HID_KEY_G, 2};
static const key_input_t KEY_h = {"h", HID_KEY_H, 0};
static const key_input_t KEY_H = {"H", HID_KEY_H, 2};
static const key_input_t KEY_i = {"i", HID_KEY_I, 0};
static const key_input_t KEY_I = {"I", HID_KEY_I, 2};
static const key_input_t KEY_j = {"j", HID_KEY_J, 0};
static const key_input_t KEY_J = {"J", HID_KEY_J, 2};
static const key_input_t KEY_k = {"k", HID_KEY_K, 0};
static const key_input_t KEY_K = {"K", HID_KEY_K, 2};
static const key_input_t KEY_l = {"l", HID_KEY_L, 0};
static const key_input_t KEY_L = {"L", HID_KEY_L, 2};
static const key_input_t KEY_m = {"m", HID_KEY_M, 0};
static const key_input_t KEY_M = {"M", HID_KEY_M, 2};
static const key_input_t KEY_n = {"n", HID_KEY_N, 0};
static const key_input_t KEY_N = {"N", HID_KEY_N, 2};
static const key_input_t KEY_o = {"o", HID_KEY_O, 0};
static const key_input_t KEY_O = {"O", HID_KEY_O, 2};
static const key_input_t KEY_p = {"p", HID_KEY_P, 0};
static const key_input_t KEY_P = {"p", HID_KEY_P, 2};
static const key_input_t KEY_q = {"q", HID_KEY_Q, 0};
static const key_input_t KEY_Q = {"Q", HID_KEY_Q, 2};
static const key_input_t KEY_r = {"r", HID_KEY_R, 0};
static const key_input_t KEY_R = {"R", HID_KEY_R, 2};
static const key_input_t KEY_s = {"s", HID_KEY_S, 0};
static const key_input_t KEY_S = {"S", HID_KEY_S, 2};
static const key_input_t KEY_t = {"t", HID_KEY_T, 0};
static const key_input_t KEY_T = {"T", HID_KEY_T, 2};
static const key_input_t KEY_u = {"u", HID_KEY_U, 0};
static const key_input_t KEY_U = {"U", HID_KEY_U, 2};
static const key_input_t KEY_v = {"v", HID_KEY_V, 0};
static const key_input_t KEY_V = {"V", HID_KEY_V, 2};
static const key_input_t KEY_w = {"w", HID_KEY_W, 0};
static const key_input_t KEY_W = {"W", HID_KEY_W, 2};
static const key_input_t KEY_x = {"x", HID_KEY_X, 0};
static const key_input_t KEY_X = {"X", HID_KEY_X, 2};
static const key_input_t KEY_y = {"y", HID_KEY_Y, 0};
static const key_input_t KEY_Y = {"Y", HID_KEY_Y, 2};
static const key_input_t KEY_z = {"z", HID_KEY_Z, 0};
static const key_input_t KEY_Z = {"Z", HID_KEY_Z, 2};

static const key_input_t KEY_1 = {"1", HID_KEY_1, 0};
static const key_input_t KEY_EXCL_MARK = {"!", HID_KEY_1, 2};
static const key_input_t KEY_2 = {"2", HID_KEY_2, 0};
static const key_input_t KEY_ATMARK = {"@", HID_KEY_2, 2};
static const key_input_t KEY_3 = {"3", HID_KEY_3, 0};
static const key_input_t KEY_NUM_SIGN = {"#", HID_KEY_3, 2};
static const key_input_t KEY_4 = {"4", HID_KEY_4, 0};
static const key_input_t KEY_DOLLAR = {"$", HID_KEY_4, 2};
static const key_input_t KEY_5 = {"5", HID_KEY_5, 0};
static const key_input_t KEY_PERCENT = {"%", HID_KEY_5, 2};
static const key_input_t KEY_6 = {"6", HID_KEY_6, 0};
static const key_input_t KEY_CARET = {"^", HID_KEY_6, 2};
static const key_input_t KEY_7 = {"7", HID_KEY_7, 0};
static const key_input_t KEY_AMPERSAND = {"&", HID_KEY_7, 2};
static const key_input_t KEY_8 = {"8", HID_KEY_8, 0};
static const key_input_t KEY_ASTERISK = {"*", HID_KEY_8, 2};
static const key_input_t KEY_9 = {"9", HID_KEY_9, 0};
static const key_input_t KEY_LEFT_PAREN = {"(", HID_KEY_9, 2};
static const key_input_t KEY_0 = {"0", HID_KEY_0, 0};
static const key_input_t KEY_RIGHT_PAREN = {")", HID_KEY_0, 2};

static const key_input_t KEY_RETURN = {"Enter", HID_KEY_RETURN, 0};
static const key_input_t KEY_ESCAPE = {"Escape", HID_KEY_ESCAPE, 0};
static const key_input_t KEY_DELETE = {"Backspace", HID_KEY_DELETE, 0};
static const key_input_t KEY_TAB = {"Tab", HID_KEY_TAB, 0};
static const key_input_t KEY_SPACEBAR = {"Spacebar", HID_KEY_SPACEBAR, 0};

static const key_input_t KEY_MINUS = {"-", HID_KEY_MINUS, 0};
static const key_input_t KEY_UNDERSCORE = {"_", HID_KEY_MINUS, 2};
static const key_input_t KEY_EQUAL = {"=", HID_KEY_EQUAL, 0};
static const key_input_t KEY_PLUS = {"+", HID_KEY_EQUAL, 2};
static const key_input_t KEY_LEFT_BRKT = {"[", HID_KEY_LEFT_BRKT, 0};
static const key_input_t KEY_LEFT_BRACE = {"{", HID_KEY_LEFT_BRKT, 2};
static const key_input_t KEY_RIGHT_BRKT = {"]", HID_KEY_RIGHT_BRKT, 0};
static const key_input_t KEY_RIGHT_BRACE = {"}", HID_KEY_RIGHT_BRKT, 2};
static const key_input_t KEY_BACK_SLASH = {"\\", HID_KEY_BACK_SLASH, 0};
static const key_input_t KEY_VERT_BAR = {"|", HID_KEY_BACK_SLASH, 2};
static const key_input_t KEY_SEMI_COLON = {";", HID_KEY_SEMI_COLON, 0};
static const key_input_t KEY_COLON = {":", HID_KEY_SEMI_COLON, 2};
static const key_input_t KEY_SGL_QUOTE = {"'", HID_KEY_SGL_QUOTE, 0};
static const key_input_t KEY_DBL_QUOTE = {"\"", HID_KEY_SGL_QUOTE, 2};
static const key_input_t KEY_GRV_ACCENT = {"`", HID_KEY_GRV_ACCENT, 0};
static const key_input_t KEY_TILDE = {"~", HID_KEY_GRV_ACCENT, 2};
static const key_input_t KEY_COMMA = {",", HID_KEY_COMMA, 0};
static const key_input_t KEY_LESS_THAN = {"<", HID_KEY_COMMA, 2};
static const key_input_t KEY_DOT = {".", HID_KEY_DOT, 0};
static const key_input_t KEY_MORE_THAN = {">", HID_KEY_DOT, 2};
static const key_input_t KEY_FWD_SLASH = {"/", HID_KEY_FWD_SLASH, 0};
static const key_input_t KEY_QUESTION = {"?", HID_KEY_FWD_SLASH, 2};

static const key_input_t KEY_CAPS_LOCK = {"Caps Lock", HID_KEY_CAPS_LOCK, 0};
static const key_input_t KEY_F1 = {"F1", HID_KEY_F1, 0};
static const key_input_t KEY_F2 = {"F2", HID_KEY_F2, 0};
static const key_input_t KEY_F3 = {"F3", HID_KEY_F3, 0};
static const key_input_t KEY_F4 = {"F4", HID_KEY_F4, 0};
static const key_input_t KEY_F5 = {"F5", HID_KEY_F5, 0};
static const key_input_t KEY_F6 = {"F6", HID_KEY_F6, 0};
static const key_input_t KEY_F7 = {"F7", HID_KEY_F7, 0};
static const key_input_t KEY_F8 = {"F8", HID_KEY_F8, 0};
static const key_input_t KEY_F9 = {"F9", HID_KEY_F9, 0};
static const key_input_t KEY_F10 = {"F10", HID_KEY_F10, 0};
static const key_input_t KEY_F11 = {"F11", HID_KEY_F11, 0};
static const key_input_t KEY_F12 = {"F12", HID_KEY_F12, 0};
static const key_input_t KEY_PRNT_SCREEN = {"Print Screen", HID_KEY_PRNT_SCREEN, 0};
static const key_input_t KEY_SCROLL_LOCK = {"Scroll Lock", HID_KEY_SCROLL_LOCK, 0};
static const key_input_t KEY_PAUSE = {"Pause", HID_KEY_PAUSE, 0};
static const key_input_t KEY_INSERT = {"Insert", HID_KEY_INSERT, 0};
static const key_input_t KEY_HOME = {"Home", HID_KEY_HOME, 0};
static const key_input_t KEY_PAGE_UP = {"PageUp", HID_KEY_PAGE_UP, 0};
static const key_input_t KEY_DELETE_FWD = {"Delete Forward", HID_KEY_DELETE_FWD, 0};
static const key_input_t KEY_END = {"End", HID_KEY_END, 0};
static const key_input_t KEY_PAGE_DOWN = {"PageDown", HID_KEY_PAGE_DOWN, 0};
static const key_input_t KEY_RIGHT_ARROW = {"RightArrow", HID_KEY_RIGHT_ARROW, 0};
static const key_input_t KEY_LEFT_ARROW = {"LeftArrow", HID_KEY_LEFT_ARROW, 0};
static const key_input_t KEY_DOWN_ARROW = {"DownArrow", HID_KEY_DOWN_ARROW, 0};
static const key_input_t KEY_UP_ARROW = {"UpArrow", HID_KEY_UP_ARROW, 0};

// Keypad
static const key_input_t KEY_NUM_LOCK = {"Num Lock", HID_KEY_NUM_LOCK, 0};
static const key_input_t KEY_DIVIDE = {"/", HID_KEY_DIVIDE, 0};
static const key_input_t KEY_MULTIPLY = {"*", HID_KEY_MULTIPLY, 0};
static const key_input_t KEY_SUBTRACT = {"-", HID_KEY_SUBTRACT, 0};
static const key_input_t KEY_ADD = {"+", HID_KEY_ADD, 0};
static const key_input_t KEY_ENTER = {"ENTER", HID_KEY_ENTER, 0};
static const key_input_t KEYPAD_1 = {"1", HID_KEYPAD_1, 0};
static const key_input_t KEYPAD_2 = {"2", HID_KEYPAD_2, 0};
static const key_input_t KEYPAD_3 = {"3", HID_KEYPAD_3, 0};
static const key_input_t KEYPAD_4 = {"4", HID_KEYPAD_4, 0};
static const key_input_t KEYPAD_5 = {"5", HID_KEYPAD_5, 0};
static const key_input_t KEYPAD_6 = {"6", HID_KEYPAD_6, 0};
static const key_input_t KEYPAD_7 = {"7", HID_KEYPAD_7, 0};
static const key_input_t KEYPAD_8 = {"8", HID_KEYPAD_8, 0};
static const key_input_t KEYPAD_9 = {"9", HID_KEYPAD_9, 0};
static const key_input_t KEYPAD_0 = {"0", HID_KEYPAD_0, 0};
static const key_input_t KEYPAD_DOT = {".", HID_KEYPAD_DOT, 0};

static const key_input_t KEY_CHANGE_INPUT_MAC = {"⇔", HID_KEY_SPACEBAR, 1};

// Kana Input
static const key_input_t KEYJP_A = {"あ", HID_KEY_3, 0};
static const key_input_t KEYJP_I = {"い", HID_KEY_E, 0};
static const key_input_t KEYJP_U = {"う", HID_KEY_4, 0};
static const key_input_t KEYJP_E = {"え", HID_KEY_5, 0};
static const key_input_t KEYJP_O = {"お", HID_KEY_6, 0};

static const key_input_t KEYJP_XA = {"ぁ", HID_KEY_3, 2};
static const key_input_t KEYJP_XI = {"ぃ", HID_KEY_E, 2};
static const key_input_t KEYJP_XU = {"ぅ", HID_KEY_4, 2};
static const key_input_t KEYJP_XE = {"ぇ", HID_KEY_5, 2};
static const key_input_t KEYJP_XO = {"ぉ", HID_KEY_6, 2};

static const key_input_t KEYJP_KA = {"か", HID_KEY_T, 0};
static const key_input_t KEYJP_KI = {"き", HID_KEY_G, 0};
static const key_input_t KEYJP_KU = {"く", HID_KEY_H, 0};
static const key_input_t KEYJP_KE = {"け", HID_KEY_SGL_QUOTE, 0};
static const key_input_t KEYJP_KO = {"こ", HID_KEY_B, 0};

static const key_input_t KEYJP_SA = {"さ", HID_KEY_X, 0};
static const key_input_t KEYJP_SI = {"し", HID_KEY_D, 0};
static const key_input_t KEYJP_SU = {"す", HID_KEY_R, 0};
static const key_input_t KEYJP_SE = {"せ", HID_KEY_P, 0};
static const key_input_t KEYJP_SO = {"そ", HID_KEY_C, 0};

static const key_input_t KEYJP_TA = {"た", HID_KEY_Q, 0};
static const key_input_t KEYJP_TI = {"ち", HID_KEY_A, 0};
static const key_input_t KEYJP_TU = {"つ", HID_KEY_Z, 0};
static const key_input_t KEYJP_TE = {"て", HID_KEY_W, 0};
static const key_input_t KEYJP_TO = {"と", HID_KEY_S, 0};

static const key_input_t KEYJP_XTU = {"っ", HID_KEY_Z, 2};

static const key_input_t KEYJP_NA = {"な", HID_KEY_U, 0};
static const key_input_t KEYJP_NI = {"に", HID_KEY_I, 0};
static const key_input_t KEYJP_NU = {"ぬ", HID_KEY_1, 0};
static const key_input_t KEYJP_NE = {"ね", HID_KEY_COMMA, 0};
static const key_input_t KEYJP_NO = {"の", HID_KEY_K, 0};

static const key_input_t KEYJP_HA = {"は", HID_KEY_F, 0};
static const key_input_t KEYJP_HI = {"ひ", HID_KEY_V, 0};
static const key_input_t KEYJP_HU = {"ふ", HID_KEY_2, 0};
static const key_input_t KEYJP_HE = {"へ", HID_KEY_BACK_SLASH, 0};
static const key_input_t KEYJP_HO = {"ほ", HID_KEY_MINUS, 0};

static const key_input_t KEYJP_MA = {"ま", HID_KEY_J, 0};
static const key_input_t KEYJP_MI = {"み", HID_KEY_N, 0};
static const key_input_t KEYJP_MU = {"む", HID_KEY_RIGHT_BRKT, 0};
static const key_input_t KEYJP_ME = {"め", HID_KEY_FWD_SLASH, 0};
static const key_input_t KEYJP_MO = {"も", HID_KEY_M, 0};

static const key_input_t KEYJP_YA = {"や", HID_KEY_7, 0};
static const key_input_t KEYJP_YU = {"ゆ", HID_KEY_8, 0};
static const key_input_t KEYJP_YO = {"よ", HID_KEY_9, 0};

static const key_input_t KEYJP_XYA = {"ゃ", HID_KEY_7, 2};
static const key_input_t KEYJP_XYU = {"ゅ", HID_KEY_8, 2};
static const key_input_t KEYJP_XYO = {"ょ", HID_KEY_9, 2};

static const key_input_t KEYJP_RA = {"ら", HID_KEY_O, 0};
static const key_input_t KEYJP_RI = {"り", HID_KEY_L, 0};
static const key_input_t KEYJP_RU = {"る", HID_KEY_DOT, 0};
static const key_input_t KEYJP_RE = {"れ", HID_KEY_SEMI_COLON, 0};
static const key_input_t KEYJP_RO = {"ろ", HID_KEY_SGL_QUOTE, 2};

static const key_input_t KEYJP_WA = {"わ", HID_KEY_0, 0};
static const key_input_t KEYJP_WO = {"を", HID_KEY_0, 2};
static const key_input_t KEYJP_NN = {"ん", HID_KEY_Y, 0};

static const key_input_t KEYJP_DAKUTEN = {"゛", HID_KEY_LEFT_BRKT, 0};
static const key_input_t KEYJP_HAN_DAKUTEN = {"゜", HID_KEY_EQUAL, 0};
static const key_input_t KEYJP_KAKKO_TOJI = {"」", HID_KEY_LEFT_BRKT, 2};
static const key_input_t KEYJP_KAKKO = {"「", HID_KEY_EQUAL, 2};
static const key_input_t KEYJP_BACKQUOTE = {"｀", HID_KEY_GRV_ACCENT, 0};
static const key_input_t KEYJP_NAMI_DASH = {"〜", HID_KEY_GRV_ACCENT, 2};
static const key_input_t KEYJP_DASH = {"ー", HID_KEY_RIGHT_BRKT, 2};
static const key_input_t KEYJP_TOUTEN = {"、", HID_KEY_COMMA, 2};
static const key_input_t KEYJP_KUTEN = {"。", HID_KEY_DOT, 2};
static const key_input_t KEYJP_NAKAGURO = {"・", HID_KEY_FWD_SLASH, 2};
static const key_input_t KEYJP_QUESTION = {"！", HID_KEY_1, 6};
static const key_input_t KEYJP_EXCL_MARK = {"？", HID_KEY_FWD_SLASH, 6};
