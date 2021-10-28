#pragma once
#include <nvs.h>
#include <esp_log.h>

#define SETTINGS_TAG "SETTINGS"

enum input_method_t
{
  input_method_default = 0,
  input_method_kana,
  input_method_roman,
};

enum keyboard_layout_t
{
  keyboard_layout_default = 0,
  keyboard_layout_jis,
  keyboard_layout_us,
};

enum platform_os_t
{
  platform_os_default = 0,
  platform_os_win,
  platform_os_mac,
};

namespace settings
{
  struct Settings
  {
  private:
    int32_t method;
    int32_t layout;
    int32_t os;
    int32_t save(const char *key, int32_t value)
    {
      nvs_handle_t handle;
      esp_err_t err;

      err = nvs_open("settings", NVS_READWRITE, &handle);
      if (err != ESP_OK)
      {
        ESP_LOGE(SETTINGS_TAG, "nvs_open failed: %d", err);
        nvs_close(handle);
        return 0;
      }

      err = nvs_set_i32(handle, key, value);
      if (err != ESP_OK)
      {
        ESP_LOGE(SETTINGS_TAG, "Set %s nvs value failed: %d", key, err);
        nvs_close(handle);
        return 0;
      }
      ESP_LOGD(SETTINGS_TAG, "Set %s nvs value completed: %d", key, value);

      nvs_close(handle);
      return value;
    }

  public:
    void load()
    {
      esp_err_t err;
      nvs_handle_t handle;

      method = input_method_default;
      layout = keyboard_layout_default;
      os = platform_os_default;

      err = nvs_open("settings", NVS_READONLY, &handle);
      if (err != ESP_OK)
      {
        ESP_LOGE(SETTINGS_TAG, "nvs_open failed: %d", err);
        nvs_close(handle);
        return;
      }

      err = nvs_get_i32(handle, "input_method", &method);
      if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND)
      {
        ESP_LOGE(SETTINGS_TAG, "Get input_method nvs value failed: %d", err);
      }

      err = nvs_get_i32(handle, "keyboard_layout", &layout);
      if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND)
      {
        ESP_LOGE(SETTINGS_TAG, "Get keyboard_layout nvs value failed: %d", err);
      }

      err = nvs_get_i32(handle, "platform_os", &os);
      if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND)
      {
        ESP_LOGE(SETTINGS_TAG, "Get platform_os nvs value failed: %d", err);
      }
      ESP_LOGI(SETTINGS_TAG, "Load nvs values finished");

      nvs_close(handle);
    }

    void input_method(input_method_t new_method) { method = save("input_method", new_method); };
    input_method_t input_method() { return static_cast<input_method_t>(method); };

    void keyboard_layout(keyboard_layout_t new_layout) { layout = save("keyboard_layout", new_layout); };
    keyboard_layout_t keyboard_layout() { return static_cast<keyboard_layout_t>(layout); };

    void platform_os(platform_os_t new_os) { os = save("platform_os", new_os); };
    platform_os_t platform_os() { return static_cast<platform_os_t>(os); };
  };
}
