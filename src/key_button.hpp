// SPDX-License-Identifier: Apache-2.0

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
  bool repeat = false;
  std::function<void(void)> action;

  void init(int32_t x, int32_t y, int32_t w, int32_t h, int text_color, int key_color)
  {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->text_color = text_color;
    this->key_color = key_color;
  }

  void append_keys()
  {
  }

  template <class Key, class... Keys>
  void append_keys(Key &&key, Keys &&...keys)
  {
    this->keys.push_back(key);
    append_keys(std::forward<Keys>(keys)...);
  }

  template <class... Keys>
  void set_keys(std::string text, Keys &&...keys)
  {
    this->text = text;
    action = nullptr;
    repeat = false;
    this->keys.clear();
    append_keys(std::forward<Keys>(keys)...);
  }

  template <class... Keys>
  void set_repeatable_keys(std::string text, Keys &&...keys)
  {
    set_keys(text, std::forward<Keys>(keys)...);
    repeat = true;
  }

  template <class... Keys>
  void set_action(std::string text, std::function<void(void)> p, Keys &&...keys)
  {
    set_keys(text);
    action = p;
    append_keys(std::forward<Keys>(keys)...);
  }

  void drawBackspaceIcon()
  {
    int32_t c = y + h / 2;
    M5.Display.drawBezier(x + 26, c + 3, x + 21, c, x + 26, c - 3, text_color);
    M5.Display.drawLine(x + 26, c - 3, x + 31, c - 8, text_color);
    M5.Display.drawLine(x + 26, c + 3, x + 31, c + 8, text_color);
    M5.Display.drawBezier(x + 31, c - 8, x + 33, c - 11, x + 38, c - 14, text_color);
    M5.Display.drawBezier(x + 31, c + 8, x + 33, c + 11, x + 38, c + 14, text_color);
    M5.Display.drawLine(x + 38, c - 14, x + 66, c - 14, text_color);
    M5.Display.drawLine(x + 38, c + 14, x + 66, c + 14, text_color);
    M5.Display.drawLine(x + 70, c - 10, x + 70, c + 10, text_color);
    M5.Display.drawBezier(x + 66, c - 14, x + 70, c - 14, x + 70, c - 10, text_color);
    M5.Display.drawBezier(x + 66, c + 14, x + 70, c + 14, x + 70, c + 10, text_color);
    M5.Display.drawLine(x + 46, c - 5, x + 56, c + 5, text_color);
    M5.Display.drawLine(x + 46, c + 5, x + 56, c - 5, text_color);
  }

  void draw(void)
  {
    M5.Display.fillRoundRect(x, y, w, h, r, key_color);
    if (text == "<x")
    {
      drawBackspaceIcon();
    }
    else
    {
      M5.Display.setTextColor(text_color, key_color);
      M5.Display.drawCenterString(text.c_str(), x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
    }
  }

  void draw_hold(void)
  {
    const auto w = this->w + r;
    const auto h = this->h + r;
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
