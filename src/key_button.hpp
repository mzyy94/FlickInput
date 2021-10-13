#pragma once
#include <M5Unified.h>

struct key_button
{
  char text[8];
  int32_t x;
  int32_t y;
  int32_t w;
  int32_t h;
  int text_color;
  int key_color;
  uint8_t keycodes[5];

  void init(int32_t x, int32_t y, int32_t w, int32_t h, int text_color, int key_color)
  {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->text_color = text_color;
    this->key_color = key_color;
  }

  void draw(void)
  {
    M5.Display.fillRoundRect(x, y, w, h, 8, key_color);
    M5.Display.setTextColor(text_color, key_color);
    M5.Display.drawCenterString(text, x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
  }
};

extern struct key_button key_buttons[20];

void set_alphabet_keys();
void init_key_button_layout();
void draw_key_buttons();
