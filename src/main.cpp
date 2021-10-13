#include <M5Unified.h>
#include "key_button.hpp"

void init_m5paper()
{
  M5.begin();
  M5.Display.setEpdMode(epd_mode_t::epd_fast);
}

extern struct key_button key_buttons[20];

void main_task(void *)
{
  init_m5paper();

  M5.Display.setTextSize(1.0);

  M5.Display.clearDisplay(TFT_WHITE);
  set_alphabet_keys();
  init_key_button_layout();
  draw_key_buttons();

  M5.Touch.setFlickThresh(3);
  M5.Touch.setHoldThresh(300);

  uint64_t count = 0;
  for (;;)
  {
    vTaskDelay(20 / portTICK_RATE_MS);

    M5.update();

    if (count % 30000 == 0)
    {
      char text[20];

      int32_t bat = M5.Power.getBatteryLevel();
      M5.Display.startWrite();
      snprintf(text, 20, "battery: %3d%%", bat);
      M5.Display.setTextColor(TFT_BLACK, TFT_WHITE);
      M5.Display.drawRightString(text, 540, 0, &fonts::lgfxJapanGothicP_24);
      M5.Display.endWrite();
    }
    count++;

    auto touches = M5.Touch.getCount();
    if (!touches)
    {
      continue;
    }

    static m5::touch_state_t prev_state;
    static struct key_button *current_key;
    static int16_t start_x, start_y;
    auto t = M5.Touch.getDetail();
    if (prev_state != t.state)
    {
      prev_state = t.state;

      switch (t.state)
      {
      case m5::touch_begin:
      case m5::flick_begin:
      {
        if (current_key == NULL)
        {
          for (size_t i = 0; i < 19; i++)
          {
            if (key_buttons[i].contains(t.x, t.y))
            {
              current_key = &key_buttons[i];
              start_x = t.x;
              start_y = t.y;
              break;
            }
          }
        }
        break;
      }
      case m5::touch_end:
      case m5::none:
      {
        if (current_key != NULL)
        {
          current_key->draw_input_text(center, 270, 150);
        }
        current_key = NULL;
        break;
      }
      case m5::flick_end:
      case m5::drag_end:
      {
        if (current_key != NULL)
        {
          auto dir = current_key->flick(start_x, start_y, t.x, t.y);
          current_key->draw_input_text(dir, 270, 150);
        }
        current_key = NULL;
      }
      default:
        break;
      }
    }
  }
  vTaskDelete(NULL);
}

extern "C"
{
  void app_main()
  {
    xTaskCreatePinnedToCore(main_task, "main_task", 8192, NULL, 1, NULL, 1);
  }
}
