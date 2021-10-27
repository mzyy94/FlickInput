#include <M5Unified.h>
#include <esp_log.h>
#include "event.hpp"
#include "keyboard.hpp"

#define DISPLAY_TAG "DISPLAY"

void draw_ble_icon(bool connected)
{
  ESP_LOGD(DISPLAY_TAG, "Drawing BLE icon connected=%d", connected);
  int color;
  if (connected)
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
}

void draw_statusbar(void * = nullptr, const char * = nullptr, int event_id = STATUS_EVENT_UPDATE_ONLY_REFRESH, void *event_data = nullptr)
{
  ESP_LOGD(DISPLAY_TAG, "Drawing statusbar event_id=%d", event_id);
  char text[20];
  static bool ble_connected = false;
  static int32_t bat = 0;

  if (event_id == STATUS_EVENT_UPDATE_BLE_STATE)
  {
    memcpy(&ble_connected, event_data, sizeof(bool));
    return;
  }
  if (event_id == STATUS_EVENT_UPDATE_BATTERY_LEVEL)
  {
    memcpy(&bat, event_data, sizeof(int32_t));
    return;
  }

  M5.Display.fillRect(0, 0, M5.Display.width(), 48, TFT_WHITE);
  M5.Display.setTextSize(1);
  snprintf(text, 20, "%3d%%", bat);
  M5.Display.setTextColor(TFT_BLACK, TFT_WHITE);

  draw_ble_icon(ble_connected);
  M5.Display.drawString("FlickInput", 26, 4, &fonts::Font4);
  M5.Display.drawRightString(text, 480, 4, &fonts::Font4);
  M5.Display.drawRoundRect(484, 2, 50, 24, 3, TFT_BLACK);
  M5.Display.fillRoundRect(534, 10, 3, 8, 1, TFT_BLACK);
  M5.Display.fillRect(486, 4, 46 * bat / 100, 20, TFT_BLACK);
}

void draw_logo(bool inverse = false)
{
  ESP_LOGD(DISPLAY_TAG, "Drawing logo inverse=%d", inverse);
  M5.Display.setTextColor(inverse ? TFT_WHITE : TFT_BLACK, inverse ? TFT_DARKGRAY : TFT_LIGHTGRAY);
  M5.Display.setTextSize(2);
  M5.Display.fillRect(0, 50, M5.Display.width(), 200, inverse ? TFT_DARKGRAY : TFT_LIGHTGRAY);
  M5.Display.drawCenterString("FlickInput", 270, 150, &fonts::lgfxJapanGothicP_40);
}

void update_display()
{
  uint32_t bits = xEventGroupWaitBits(event_group, 0b11111, true, false, 0);

  if (bits == 0)
  {
    return;
  }

  M5.Display.startWrite();

  if (bits & EVENT_BIT_CLEAR_DISPLAY)
  {
    ESP_LOGD(DISPLAY_TAG, "Clear display");
    M5.Display.clearDisplay(TFT_WHITE);
  }
  if (bits & EVENT_BIT_DRAW_STATUSBAR)
  {
    ESP_LOGD(DISPLAY_TAG, "Draw statusbar");
    draw_statusbar();
  }
  if (bits & EVENT_BIT_DRAW_LOGO)
  {
    ESP_LOGD(DISPLAY_TAG, "Draw logo");
    draw_logo();
  }
  if (bits & EVENT_BIT_DRAW_KEYBOARD)
  {
    ESP_LOGD(DISPLAY_TAG, "Draw keyboard");
    Keyboard.draw();
  }

  M5.Display.endWrite();
}
