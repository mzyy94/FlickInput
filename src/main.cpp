#include <M5Unified.h>

void init_m5paper()
{
  M5.begin();
  M5.Power.begin();

  M5.Display.setEpdMode(epd_mode_t::epd_fast);
}

void draw_key(int32_t x, int32_t y, int32_t w, int32_t h, int text_color, int key_color, const char *text)
{
  M5.Display.fillRoundRect(x, y, w, h, 8, key_color);
  M5.Display.setTextColor(text_color, key_color);
  M5.Display.drawCenterString(text, x + (w / 2), y + (h / 2) - 12, &fonts::lgfxJapanGothicP_24);
}

void draw_alphabet_layout()
{
  int32_t x = 10, y = 560, w = 96, h = 78, pad = 10;

  M5.Display.startWrite();

  const char key_labels[20][8] = {
      "→", "@#/&_", "ABC", "DEF", "<x",
      "←", "GHI", "JKL", "MNO", "空白",
      "123", "PQRS", "TUV", "WXYZ", "改行",
      "(^_^)", "a/A", "'\"()", ".,?!"};

  for (int i = 0; i < 4; i++)
    draw_key(x, y + (h + pad) * i, w, h, TFT_WHITE, TFT_DARKGRAY, key_labels[i * 5]);

  for (int j = 1; j < 4; j++)
    for (int i = 0; i < 4; i++)
      draw_key(x + (w + pad) * j, y + (h + pad) * i, w, h, TFT_BLACK, TFT_LIGHTGRAY, key_labels[i * 5 + j]);

  draw_key(x + 4 * (w + pad), y + (h + pad) * 0, w, h, TFT_WHITE, TFT_DARKGRAY, key_labels[0 * 5 + 4]);
  draw_key(x + 4 * (w + pad), y + (h + pad) * 1, w, h, TFT_WHITE, TFT_DARKGRAY, key_labels[1 * 5 + 4]);
  draw_key(x + 4 * (w + pad), y + (h + pad) * 2, w, h * 2 + pad, TFT_WHITE, TFT_DARKGRAY, key_labels[2 * 5 + 4]);
  M5.Display.endWrite();
}

void main_task(void *)
{
  init_m5paper();

  M5.Display.setTextSize(1.0);

  M5.Display.clearDisplay(TFT_WHITE);
  draw_alphabet_layout();

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
