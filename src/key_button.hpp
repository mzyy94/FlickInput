#pragma once
#include <M5Unified.h>
#include "key.hpp"

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
  std::vector<key_input_t> keys;
  int32_t x;
  int32_t y;
  int32_t w;
  int32_t h;
  const int32_t r = 8;
  int text_color;
  int key_color;
  void (*action)(void);

  void init(int32_t x, int32_t y, int32_t w, int32_t h, int text_color, int key_color)
  {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->text_color = text_color;
    this->key_color = key_color;
  }

  void set_keys(std::string text, key_input_t key0, key_input_t key1, key_input_t key2, key_input_t key3, key_input_t key4)
  {
    set_keys(text, key0, key1, key2, key3);
    keys.push_back(key4);
  }
  void set_keys(std::string text, key_input_t key0, key_input_t key1, key_input_t key2, key_input_t key3)
  {
    set_keys(text, key0, key1, key2);
    keys.push_back(key3);
  }
  void set_keys(std::string text, key_input_t key0, key_input_t key1, key_input_t key2)
  {
    set_keys(text, key0, key1);
    keys.push_back(key2);
  }
  void set_keys(std::string text, key_input_t key0, key_input_t key1)
  {
    set_keys(text, key0);
    keys.push_back(key1);
  }
  void set_keys(std::string text, key_input_t key0)
  {
    set_keys(text);
    keys.push_back(key0);
  }
  void set_keys(std::string text)
  {
    this->text = text;
    action = nullptr;
    keys.clear();
  }
  void set_action(std::string text, void (*p)(void))
  {
    set_keys(text);
    action = p;
  }

  void draw(void)
  {
    M5.Display.fillRoundRect(x, y, w, h, r, key_color);
    M5.Display.setTextColor(text_color, key_color);
    M5.Display.drawCenterString(text.c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
  }

  void draw_hold(void)
  {
    const int32_t w = this->w + r;
    const int32_t h = this->h + r;
    uint32_t x, y;

    if (keys.size() < 2)
    {
      return;
    }

    M5.Display.startWrite();
    M5.Display.setTextColor(text_color, key_color);
    M5.Display.setTextSize(1);

    x = this->x - this->w;
    y = this->y - 4;
    M5.Display.fillRoundRect(x, y, w, h, r, key_color);
    M5.Display.drawCenterString(keys[1].text.c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);

    if (keys.size() > 2)
    {
      x = this->x - 4;
      y = this->y - this->h;
      M5.Display.fillRoundRect(x, y, w, h, r, key_color);
      M5.Display.drawCenterString(keys[2].text.c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
    }
    if (keys.size() > 3)
    {
      x = this->x + this->w - r;
      y = this->y - 4;
      M5.Display.fillRoundRect(x, y, w, h, r, key_color);
      M5.Display.drawCenterString(keys[3].text.c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
    }
    if (keys.size() > 4)
    {
      x = this->x - 4;
      y = this->y + this->h - r;
      M5.Display.fillRoundRect(x, y, w, h, r, key_color);
      M5.Display.drawCenterString(keys[4].text.c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
    }

    x = this->x - 4;
    y = this->y - 4;
    M5.Display.setTextColor(TFT_WHITE, TFT_DARKGRAY);
    M5.Display.fillRect(x, y, w, h, TFT_DARKGRAY);
    M5.Display.drawCenterString(keys[0].text.c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
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

  key_input_t *get_key_input(direction_t dir)
  {
    if (dir < keys.size())
    {
      return &keys[dir];
    }
    return nullptr;
  }
};

void set_alphabet_keys();
void init_key_button_layout();
void draw_key_buttons();
