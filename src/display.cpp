#include <M5Unified.h>
#include "ble.hpp"

void draw_header(void *event_arg, const char *event_base, int event_id, void *event_data)
{
  char text[20];

  int32_t bat = M5.Power.getBatteryLevel();
  M5.Display.startWrite();
  M5.Display.fillRect(0, 0, 540, 48, TFT_WHITE);
  M5.Display.setTextSize(1);
  snprintf(text, 20, "%3d%%", bat);
  M5.Display.setTextColor(TFT_BLACK, TFT_WHITE);

  M5.Display.drawString("FlickInput", 26, 4, &fonts::Font4);
  int color;
  if (sec_conn)
  {
    M5.Display.fillRoundRect(3, 2, 18, 24, 8, TFT_BLACK);
    color = TFT_WHITE;
  }
  else
  {
    M5.Display.drawRoundRect(3, 2, 18, 24, 8, TFT_BLACK);
    color = TFT_BLACK;
  }
  M5.Display.drawLine(8, 18, 16, 10, color);
  M5.Display.drawLine(16, 10, 12, 6, color);
  M5.Display.drawLine(12, 6, 12, 22, color);
  M5.Display.drawLine(12, 22, 16, 18, color);
  M5.Display.drawLine(16, 18, 8, 10, color);

  M5.Display.drawRightString(text, 480, 4, &fonts::Font4);
  M5.Display.drawRoundRect(484, 2, 50, 24, 3, TFT_BLACK);
  M5.Display.fillRoundRect(534, 10, 3, 8, 1, TFT_BLACK);
  M5.Display.fillRect(486, 4, 46 * bat / 100, 20, TFT_BLACK);
  M5.Display.endWrite();
}

void draw_header()
{
  draw_header(NULL, NULL, -1, NULL);
}

void draw_logo(bool inverse)
{
  M5.Display.startWrite();
  M5.Display.setTextColor(inverse ? TFT_WHITE : TFT_BLACK, inverse ? TFT_DARKGRAY : TFT_LIGHTGRAY);
  M5.Display.setTextSize(2);
  M5.Display.fillRect(0, 50, 540, 200, inverse ? TFT_DARKGRAY : TFT_LIGHTGRAY);
  M5.Display.drawCenterString("FlickInput", 270, 150, &fonts::lgfxJapanGothicP_40);
  M5.Display.endWrite();
}

void draw_logo()
{
  draw_logo(false);
}