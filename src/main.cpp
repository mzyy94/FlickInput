#include <M5Unified.h>
#include "nvs_flash.h"

#include "keyboard.hpp"
#include "touch.hpp"
#include "ble.hpp"

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

  set_alphabet_keybard();
  init_keyboard_layout();
  draw_keyboard();

  init_touch();
  init_ble_hid();

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

    touch_input();

    if (M5.BtnB.wasHold())
    {
      count = 0;
      M5.Display.clearDisplay(TFT_WHITE);
      draw_keyboard();
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
