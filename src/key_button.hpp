#pragma once
#include <M5Unified.h>

struct key_button
{
  std::string text;
  uint32_t chars[5];
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

  void set_text(std::string text, uint32_t char0, uint32_t char1, uint32_t char2, uint32_t char3, uint32_t char4)
  {
    this->text = text;
    chars[0] = char0;
    chars[1] = char1;
    chars[2] = char2;
    chars[3] = char3;
    chars[4] = char4;
  }

  void set_text(const char *text, uint32_t char0, uint32_t char1, uint32_t char2, uint32_t char3)
  {
    set_text(text, char0, char1, char2, char3, 0);
  }
  void set_text(const char *text, uint32_t char0, uint32_t char1, uint32_t char2)
  {
    set_text(text, char0, char1, char2, 0, 0);
  }
  void set_text(const char *text, uint32_t char0, uint32_t char1)
  {
    set_text(text, char0, char1, 0, 0, 0);
  }
  void set_text(const char *text, uint32_t char0)
  {
    set_text(text, char0, 0, 0, 0, 0);
  }
  void set_text(const char *text)
  {
    set_text(text, 0, 0, 0, 0, 0);
  }

  void draw(void)
  {
    M5.Display.fillRoundRect(x, y, w, h, 8, key_color);
    M5.Display.setTextColor(text_color, key_color);
    M5.Display.drawCenterString(text.c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
  }
};

extern struct key_button key_buttons[20];

void set_alphabet_keys();
void init_key_button_layout();
void draw_key_buttons();
