#include "key_button.hpp"

struct key_button key_buttons[20];

void set_alphabet_keys()
{
  int i = 0;
  key_buttons[i++].set_text("→");
  key_buttons[i++].set_text("@#/&_", '@', '#', '/', '&', '_');
  key_buttons[i++].set_text("ABC", 'A', 'B', 'C');
  key_buttons[i++].set_text("DEF", 'D', 'E', 'F');
  key_buttons[i++].set_text("<x");
  key_buttons[i++].set_text("←");
  key_buttons[i++].set_text("GHI", 'G', 'H', 'I');
  key_buttons[i++].set_text("JKL", 'J', 'K', 'L');
  key_buttons[i++].set_text("MNO", 'M', 'N', 'O');
  key_buttons[i++].set_text("空白", ' ');
  key_buttons[i++].set_text("123");
  key_buttons[i++].set_text("PQRS", 'P', 'Q', 'R', 'S');
  key_buttons[i++].set_text("TUV", 'T', 'U', 'V');
  key_buttons[i++].set_text("WXYZ", 'W', 'X', 'Y', 'Z');
  key_buttons[i++].set_text("改行");
  key_buttons[i++].set_text("(^_^)");
  key_buttons[i++].set_text("a/A");
  key_buttons[i++].set_text("'\"()", '\'', '"', '(', ')');
  key_buttons[i++].set_text(".,?!", '.', ',', '?', '!');
}

void init_key_button_layout()
{
  int32_t x = 10, y = 560, w = 96, h = 78, pad = 10;

  for (int i = 0; i < 4; i++)
    key_buttons[i * 5].init(x, y + (h + pad) * i, w, h, TFT_WHITE, TFT_DARKGRAY);

  for (int j = 1; j < 4; j++)
    for (int i = 0; i < 4; i++)
      key_buttons[i * 5 + j].init(x + (w + pad) * j, y + (h + pad) * i, w, h, TFT_BLACK, TFT_LIGHTGRAY);

  key_buttons[0 * 5 + 4].init(x + 4 * (w + pad), y + (h + pad) * 0, w, h, TFT_WHITE, TFT_DARKGRAY);
  key_buttons[1 * 5 + 4].init(x + 4 * (w + pad), y + (h + pad) * 1, w, h, TFT_WHITE, TFT_DARKGRAY);
  key_buttons[2 * 5 + 4].init(x + 4 * (w + pad), y + (h + pad) * 2, w, h * 2 + pad, TFT_WHITE, TFT_DARKGRAY);
}

void draw_key_buttons()
{
  M5.Display.startWrite();
  for (size_t i = 0; i < 19; i++)
    key_buttons[i].draw();

  M5.Display.endWrite();
}