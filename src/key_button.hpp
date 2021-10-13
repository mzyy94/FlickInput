#pragma once
#include <M5Unified.h>

enum direction_t
{
  center = 0,
  left = 1,
  top = 2,
  right = 3,
  bottom = 4,
};

struct key_button
{
  std::string text;
  std::string chars[5];
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

  void set_text(std::string text, std::string char0, std::string char1, std::string char2, std::string char3, std::string char4)
  {
    this->text = text;
    for (size_t i = 0; i < 5; i++)
    {
      chars[i].clear();
    }
    chars[0] = char0;
    chars[1] = char1;
    chars[2] = char2;
    chars[3] = char3;
    chars[4] = char4;
  }

  void set_text(const char *text, std::string char0, std::string char1, std::string char2, std::string char3)
  {
    set_text(text, char0, char1, char2, char3, "");
  }
  void set_text(const char *text, std::string char0, std::string char1, std::string char2)
  {
    set_text(text, char0, char1, char2, "", "");
  }
  void set_text(const char *text, std::string char0, std::string char1)
  {
    set_text(text, char0, char1, "", "", "");
  }
  void set_text(const char *text, std::string char0)
  {
    set_text(text, char0, "", "", "", "");
  }
  void set_text(const char *text)
  {
    set_text(text, "", "", "", "", "");
  }

  void draw(void)
  {
    M5.Display.fillRoundRect(x, y, w, h, 8, key_color);
    M5.Display.setTextColor(text_color, key_color);
    M5.Display.drawCenterString(text.c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
  }

  void draw_hold(void)
  {
    const int32_t w = this->w + 8;
    const int32_t h = this->h + 8;
    uint32_t x, y;

    if (chars[1].empty())
    {
      return;
    }

    M5.Display.startWrite();
    M5.Display.setTextColor(text_color, key_color);
    M5.Display.setTextSize(1);

    x = this->x - this->w;
    y = this->y - 4;
    M5.Display.fillRoundRect(x, y, w, h, 8, key_color);
    M5.Display.drawCenterString(chars[1].c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);

    if (!chars[2].empty())
    {
      x = this->x - 4;
      y = this->y - this->h;
      M5.Display.fillRoundRect(x, y, w, h, 8, key_color);
      M5.Display.drawCenterString(chars[2].c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
    }
    if (!chars[3].empty())
    {
      x = this->x + this->w - 8;
      y = this->y - 4;
      M5.Display.fillRoundRect(x, y, w, h, 8, key_color);
      M5.Display.drawCenterString(chars[3].c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
    }
    if (!chars[4].empty())
    {
      x = this->x - 4;
      y = this->y + this->h - 8;
      M5.Display.fillRoundRect(x, y, w, h, 8, key_color);
      M5.Display.drawCenterString(chars[4].c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
    }

    x = this->x - 4;
    y = this->y - 4;
    M5.Display.setTextColor(TFT_WHITE, TFT_BLACK);
    M5.Display.fillRect(x, y, w, h, TFT_BLACK);
    M5.Display.drawCenterString(chars[0].c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
    M5.Display.endWrite();
  }

  bool contains(int x, int y)
  {
    return this->x <= x && x < (this->x + this->w) && this->y <= y && y < (this->y + this->h);
  }

  direction_t flick(int sx, int sy, int ex, int ey)
  {
    auto x = ex - sx;
    auto y = ey - sy;

    if (abs(x) == abs(y))
      return center;
    if (abs(x) > abs(y))
      return (x < 0) ? left : right;
    return (y < 0) ? top : bottom;
  }

  void draw_input_text(direction_t dir, int x, int y)
  {
    M5.Display.startWrite();
    M5.Display.setTextColor(TFT_BLACK, TFT_LIGHTGRAY);
    M5.Display.setTextSize(2);
    M5.Display.fillRect(x - 100, y - 200, 200, 400, TFT_LIGHTGRAY);
    M5.Display.drawCenterString(this->chars[dir].c_str(), x, y, &fonts::lgfxJapanGothicP_40);
    M5.Display.endWrite();
  }
};

extern struct key_button key_buttons[20];

void set_alphabet_keys();
void init_key_button_layout();
void draw_key_buttons();
