// SPDX-License-Identifier: Apache-2.0

#include <algorithm>
#include <esp_log.h>

#include "keyboard.hpp"
#include "key_button.hpp"
#include "ble.hpp"
#include "layout.hpp"

#define KEYBOARD_TAG "KEYBOARD"

namespace kbd
{
  void repeat_input(Keyboard *keyboard)
  {
    keyboard->input_key_button(center, false);
  }

  size_t Keyboard::next_layout_index()
  {
    if (layout_index + 1 >= layouts.size())
    {
      return 0;
    }
    return layout_index + 1;
  }

  void Keyboard::draw_next_layout()
  {
    layout_index = next_layout_index();
    const auto layout_func = layouts[layout_index]->layout_function;
    layout_func();
  }

  void Keyboard::set_input_method(input_method_t method, keyboard_layout_t layout, platform_os_t os)
  {
    this->os = os;
    layouts.clear();

    if (method == input_method_roman)
    {
      layouts.push_back(new Layout("あいう", layout_roman_kana_keybard, KEY_KANA_INPUT));
    }
    else
    {
      layouts.push_back(new Layout("あいう", layout == keyboard_layout_us ? layout_us_kana_keybard : layout_jis_kana_keybard, KEY_KANA_INPUT));
    }

    layouts.push_back(new Layout("ABC", layout == keyboard_layout_us ? layout_us_lower_alphabet_keybard : layout_jis_lower_alphabet_keybard, KEY_EISU_INPUT));
    layouts.push_back(new Layout("123", layout_number_keybard, KEY_EISU_INPUT));
  }

  void Keyboard::init()
  {
    const int32_t x = 10, y = 560, w = 96, h = 78, pad = 10;

    for (size_t j = 0; j < 5; j++)
    {
      for (size_t i = 0; i < 4; i++)
      {
        key_buttons[i * 5 + j].init(x + (w + pad) * j, y + (h + pad) * i, w, (i == 2 && j == 4) ? h * 2 + pad : h, (j == 0 || j == 4) ? TFT_WHITE : TFT_BLACK, (j == 0 || j == 4) ? TFT_DARKGRAY : TFT_LIGHTGRAY);
        if (i == 2 && j == 4)
          return;
      }
    }
  }

  void Keyboard::draw()
  {
    M5.Display.setTextSize(1);
    M5.Display.fillRect(0, 460, M5.Display.width(), 500, TFT_WHITE);
    for (auto &btn : key_buttons)
    {
      btn.draw();
    }
  }

  void Keyboard::draw_input_text(std::string text)
  {
    const auto x = M5.Display.width() / 2, y = 150;
    M5.Display.startWrite();
    M5.Display.setTextColor(TFT_BLACK, TFT_WHITE);
    M5.Display.setTextSize(2);
    M5.Display.fillRect(x - 270, y - 100, M5.Display.width(), 200, TFT_WHITE);
    M5.Display.drawCenterString(text.c_str(), x, y, &fonts::lgfxJapanGothicP_40);
    M5.Display.endWrite();
  }

  void Keyboard::input_key_button(direction_t dir, bool draw_text)
  {
    auto input = current_key->get_key_input(dir);
    if (input == nullptr)
    {
      return;
    }
    if (draw_text)
    {
      draw_input_text(input->text);
    }
    if ((input->modifier & ALT_KEY) && os == platform_os_win)
    {
      send_key(input->keycode, input->modifier ^ ALT_KEY);
      send_key(HID_KEY_F9, 0);
    }
    else
    {
      send_key(input->keycode, input->modifier);
    }
    if (input->second_keycode != 0)
    {
      send_key(input->second_keycode, 0);
    }
    if (input->third_keycode != 0)
    {
      send_key(input->third_keycode, 0);
    }
  }

  esp_timer_handle_t Keyboard::repeat_key_button()
  {
    return dispatch_every(100, repeat_input, this);
  }

  void Keyboard::touch_begin(m5::touch_detail_t *t)
  {
    if (current_key != nullptr)
    {
      return;
    }
    current_key = std::find_if(key_buttons.begin(), key_buttons.end(), [t](struct key_button btn)
                               { return btn.contains(t->x, t->y); });
    if (current_key == key_buttons.end())
    {
      current_key = nullptr;
    }
  }

  void Keyboard::hold_begin(m5::touch_detail_t *t)
  {
    if (current_key == nullptr)
    {
      return;
    }
    if (current_key->repeat)
    {
      input_key_button(center, true);
      ESP_LOGD(KEYBOARD_TAG, "start repeat key input");
      hold_input = repeat_key_button();
    }
    current_key->draw_hold();
    need_refresh = true;
  }

  void Keyboard::touch_end(m5::touch_detail_t *t)
  {
    if (hold_input != nullptr)
    {
      stop_timer(hold_input);
      hold_input = nullptr;
      ESP_LOGD(KEYBOARD_TAG, "stop repeat key input");
    }
    else if (current_key != nullptr)
    {
      input_key_button(center, true);
      if (current_key->action != nullptr)
      {
        current_key->action();
      }
    }
    if (need_refresh)
    {
      xEventGroupSetBits(event_group, EVENT_BIT_DRAW_KEYBOARD);
      need_refresh = false;
    }
    current_key = nullptr;
  }

  void Keyboard::flick_end(m5::touch_detail_t *t)
  {
    if (current_key == nullptr)
    {
      return;
    }
    const auto dir = current_key->flick(t->base.x, t->base.y, t->x, t->y);
    input_key_button(dir, true);
    if (current_key->action != nullptr)
    {
      current_key->action();
    }
    current_key = nullptr;
  }
}

kbd::Keyboard Keyboard;