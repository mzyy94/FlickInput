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

  uint64_t count = 0;
  for (;;)
  {
    vTaskDelay(100 / portTICK_RATE_MS);

    M5.update();

    if (count % 100 == 0)
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
