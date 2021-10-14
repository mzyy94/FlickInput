#include <algorithm>

#include <M5Unified.h>
#include "keyboard.hpp"

void init_touch()
{
  M5.Touch.setFlickThresh(3);
  M5.Touch.setHoldThresh(300);
}

void touch_input()
{
  auto touches = M5.Touch.getCount();
  if (!touches)
  {
    return;
  }

  static m5::touch_state_t prev_state;
  static struct key_button *current_key;
  static int16_t start_x, start_y;
  static bool need_refresh = false;
  auto t = M5.Touch.getDetail();
  if (prev_state != t.state)
  {
    prev_state = t.state;

    switch (t.state)
    {
    case m5::touch_begin:
    case m5::flick_begin:
    {
      if (current_key == nullptr)
      {
        current_key = std::find_if(key_buttons.begin(), key_buttons.end(), [t](struct key_button btn)
                                   { return btn.contains(t.x, t.y); });
        if (current_key == key_buttons.end())
        {
          current_key = nullptr;
        }
        else
        {
          start_x = t.x;
          start_y = t.y;
        }
      }
      break;
    }
    case m5::hold_begin:
    {
      if (current_key != nullptr)
      {
        current_key->draw_hold();
        need_refresh = true;
      }
      break;
    }
    case m5::touch_end:
    case m5::none:
    {
      if (current_key != nullptr)
      {
        input_key_button(current_key, center);
      }
      if (need_refresh)
      {
        draw_keyboard();
        need_refresh = false;
      }
      current_key = nullptr;
      break;
    }
    case m5::flick_end:
    case m5::drag_end:
    {
      if (current_key != nullptr)
      {
        auto dir = current_key->flick(start_x, start_y, t.x, t.y);
        input_key_button(current_key, dir);
      }
      current_key = nullptr;
    }
    default:
      break;
    }
  }
}