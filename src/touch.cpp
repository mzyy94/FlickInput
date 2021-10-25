#include <algorithm>

#include <M5Unified.h>
#include <esp_log.h>
#include "keyboard.hpp"
#include "touch.hpp"

#define TOUCH_TAG "TOUCH"

namespace touch
{
  void Touch::init()
  {
    M5.Touch.setFlickThresh(3);
    M5.Touch.setHoldThresh(300);
  }

  void Touch::touch_begin(int16_t x, int16_t y)
  {
    if (Keyboard.current_key != nullptr)
    {
      return;
    }
    Keyboard.current_key = std::find_if(Keyboard.key_buttons.begin(), Keyboard.key_buttons.end(), [x, y](struct key_button btn)
                                        { return btn.contains(x, y); });
    if (Keyboard.current_key == Keyboard.key_buttons.end())
    {
      Keyboard.current_key = nullptr;
      return;
    }
    start_x = x;
    start_y = y;
  }

  void Touch::hold_begin(int16_t x, int16_t y)
  {
    if (Keyboard.current_key == nullptr)
    {
      return;
    }
    if (Keyboard.current_key->repeat)
    {
      Keyboard.input_key_button(center, true);
      ESP_LOGD(TOUCH_TAG, "start repeat key input");
      hold_input = Keyboard.repeat_key_button();
    }
    Keyboard.current_key->draw_hold();
    need_refresh = true;
  }

  void Touch::touch_end(int16_t x, int16_t y)
  {
    if (hold_input != nullptr)
    {
      stop_timer(hold_input);
      hold_input = nullptr;
      ESP_LOGD(TOUCH_TAG, "stop repeat key input");
    }
    else if (Keyboard.current_key != nullptr)
    {
      Keyboard.input_key_button(center, true);
      if (Keyboard.current_key->action != nullptr)
      {
        Keyboard.current_key->action();
      }
    }
    if (need_refresh)
    {
      Keyboard.draw();
      need_refresh = false;
    }
    Keyboard.current_key = nullptr;
  }

  void Touch::flick_end(int16_t x, int16_t y)
  {
    if (Keyboard.current_key == nullptr)
    {
      return;
    }
    const auto dir = Keyboard.current_key->flick(start_x, start_y, x, y);
    Keyboard.input_key_button(dir, true);
    if (Keyboard.current_key->action != nullptr)
    {
      Keyboard.current_key->action();
    }
    Keyboard.current_key = nullptr;
  }

  void Touch::input()
  {
    const auto touches = M5.Touch.getCount();
    if (!touches)
    {
      return;
    }

    const auto t = M5.Touch.getDetail();
    if (prev_state != t.state)
    {
      prev_state = t.state;

      switch (t.state)
      {
      case m5::touch_begin:
      case m5::flick_begin:
      {
        ESP_LOGD(TOUCH_TAG, "event %s: %d (%d,%d)", t.state == m5::touch_begin ? "touch_begin" : "flick_begin", t.state, t.x, t.y);
        touch_begin(t.x, t.y);
        break;
      }
      case m5::hold_begin:
      {
        ESP_LOGD(TOUCH_TAG, "event hold_begin: %d (%d,%d)", t.state, t.x, t.y);
        hold_begin(t.x, t.y);
        break;
      }
      case m5::touch_end:
      case m5::none:
      {
        ESP_LOGD(TOUCH_TAG, "event %s: %d (%d,%d)", t.state == m5::touch_end ? "touch_end" : "none", t.state, t.x, t.y);
        touch_end(t.x, t.y);
        break;
      }
      case m5::flick_end:
      case m5::drag_end:
      {
        ESP_LOGD(TOUCH_TAG, "event %s: %d (%d,%d)", t.state == m5::flick_end ? "flick_end" : "drag_end", t.state, t.x, t.y);
        flick_end(t.x, t.y);
        break;
      }
      default:
        ESP_LOGD(TOUCH_TAG, "event other: %d (%d,%d)", t.state, t.x, t.y);
        break;
      }
    }
  }
}

touch::Touch Touch;
