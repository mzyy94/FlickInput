#include <algorithm>

#include <M5Unified.h>
#include <esp_log.h>
#include "keyboard.hpp"
#include "touch.hpp"

#define TOUCH_TAG "TOUCH"

namespace touch
{
  void Touch::touch_begin(m5::touch_detail_t t)
  {
    if (Keyboard.current_key != nullptr)
    {
      return;
    }
    Keyboard.current_key = std::find_if(Keyboard.key_buttons.begin(), Keyboard.key_buttons.end(), [t](struct key_button btn)
                                        { return btn.contains(t.x, t.y); });
    if (Keyboard.current_key == Keyboard.key_buttons.end())
    {
      Keyboard.current_key = nullptr;
      return;
    }
  }

  void Touch::hold_begin(m5::touch_detail_t t)
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

  void Touch::touch_end(m5::touch_detail_t t)
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

  void Touch::flick_end(m5::touch_detail_t t)
  {
    if (Keyboard.current_key == nullptr)
    {
      return;
    }
    const auto dir = Keyboard.current_key->flick(t.base.x, t.base.y, t.x, t.y);
    Keyboard.input_key_button(dir, true);
    if (Keyboard.current_key->action != nullptr)
    {
      Keyboard.current_key->action();
    }
    Keyboard.current_key = nullptr;
  }
}

touch::Touch Touch;
