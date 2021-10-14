#include <M5Unified.h>
#include "nvs_flash.h"

#include "keyboard.hpp"
#include "touch.hpp"
#include "ble.hpp"
#include "header.hpp"

void init_m5paper()
{
  M5.begin();
  M5.Display.setEpdMode(epd_mode_t::epd_fast);

  esp_err_t ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
  {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);
}

void main_task(void *)
{
  init_m5paper();

  M5.Display.setTextSize(1.0);

  M5.Display.clearDisplay(TFT_WHITE);

  init_keyboard_layout();
  draw_hiragana_keybard();

  init_touch();
  init_ble_hid();

  M5.Display.startWrite();
  M5.Display.setTextColor(TFT_BLACK, TFT_LIGHTGRAY);
  M5.Display.setTextSize(2);
  M5.Display.fillRect(0, 50, 540, 200, TFT_LIGHTGRAY);
  M5.Display.drawCenterString("FlickInput", 270, 150, &fonts::lgfxJapanGothicP_40);
  M5.Display.endWrite();

  uint64_t count = 0;
  for (;;)
  {
    vTaskDelay(20 / portTICK_RATE_MS);

    M5.update();

    if (count % 30000 == 0)
    {
      draw_header();
    }
    count++;

    touch_input();

    if (M5.BtnB.wasHold())
    {
      count = 0;
      M5.Display.clearDisplay(TFT_WHITE);
      draw_keyboard();
    }
    if (M5.BtnA.wasClicked())
    {
      send_key(HID_KEY_UP_ARROW, 0);
    }
    if (M5.BtnC.wasClicked())
    {
      send_key(HID_KEY_DOWN_ARROW, 0);
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
