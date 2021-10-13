#include "key_button.hpp"

struct key_button key_buttons[20];

void set_alphabet_keys()
{
  int i = 0;
  snprintf(key_buttons[i++].text, 7, "→");
  snprintf(key_buttons[i++].text, 7, "@#/&_");
  snprintf(key_buttons[i++].text, 7, "ABC");
  snprintf(key_buttons[i++].text, 7, "DEF");
  snprintf(key_buttons[i++].text, 7, "<x");
  snprintf(key_buttons[i++].text, 7, "←");
  snprintf(key_buttons[i++].text, 7, "GHI");
  snprintf(key_buttons[i++].text, 7, "JKL");
  snprintf(key_buttons[i++].text, 7, "MNO");
  snprintf(key_buttons[i++].text, 7, "空白");
  snprintf(key_buttons[i++].text, 7, "123");
  snprintf(key_buttons[i++].text, 7, "PQRS");
  snprintf(key_buttons[i++].text, 7, "TUV");
  snprintf(key_buttons[i++].text, 7, "WXYZ");
  snprintf(key_buttons[i++].text, 7, "改行");
  snprintf(key_buttons[i++].text, 7, "(^_^)");
  snprintf(key_buttons[i++].text, 7, "a/A");
  snprintf(key_buttons[i++].text, 7, "'\"()");
  snprintf(key_buttons[i++].text, 7, ".,?!");
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