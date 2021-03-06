// SPDX-License-Identifier: Apache-2.0

#pragma once
#include <nvs.h>
#include <esp_log.h>
#include <algorithm>

#define SETTINGS_TAG "SETTINGS"

enum input_method_t
{
  input_method_kana,
  input_method_roman,
};

enum keyboard_layout_t
{
  keyboard_layout_jis,
  keyboard_layout_us,
};

enum platform_os_t
{
  platform_os_win,
  platform_os_mac,
};

enum device_orientation_t
{
  device_orientation_normal,
  device_orientation_upside_down,
};

enum poweroff_timer_t
{
  poweroff_timer_none,
  poweroff_timer_5min,
  poweroff_timer_10min,
  poweroff_timer_15min,
  poweroff_timer_30min,
  poweroff_timer_60min,
  poweroff_timer_max,
};

namespace settings
{
  struct Settings
  {
  private:
    uint8_t method;
    uint8_t layout;
    uint8_t os;
    uint8_t orientation;
    uint8_t developer;
    uint8_t poweroff;
    uint8_t save(const char *key, uint8_t value)
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

      err = nvs_set_u8(handle, key, value);
      if (err != ESP_OK)
      {
        ESP_LOGE(SETTINGS_TAG, "Set %s nvs value failed: %d", key, err);
        nvs_close(handle);
        return 0;
      }
      ESP_LOGD(SETTINGS_TAG, "Set %s nvs value completed: %d", key, value);

      nvs_commit(handle);
      nvs_close(handle);
      return value;
    }

    void get_value(nvs_handle_t handle, const char *key, int32_t *value)
    {
      esp_err_t err = nvs_get_i32(handle, key, value);
      if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND)
      {
        ESP_LOGE(SETTINGS_TAG, "Get %s nvs value failed: %d", key, err);
      }
    }

    void get_value(nvs_handle_t handle, const char *key, uint8_t *value)
    {
      esp_err_t err = nvs_get_u8(handle, key, value);
      if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND)
      {
        ESP_LOGE(SETTINGS_TAG, "Get %s nvs value failed: %d", key, err);
      }
    }

    void migrate(nvs_handle_t *handle, uint32_t version)
    {
      if (version != 1)
      {
        std::vector<std::string> keys{
            "input_method",
            "keyboard_layout",
            "platform_os",
            "orientation",
        };
        int32_t value;
        esp_err_t err;

        nvs_close(*handle);
        err = nvs_open("settings", NVS_READWRITE, handle);
        if (err != ESP_OK)
        {
          ESP_LOGE(SETTINGS_TAG, "nvs_open failed: %d", err);
          nvs_close(*handle);
          return;
        }
        for (auto &key : keys)
        {
          err = nvs_get_i32(*handle, key.c_str(), &value);
          if (err != ESP_OK)
          {
            ESP_LOGE(SETTINGS_TAG, "Old %s nvs value is not available: %d", key.c_str(), err);
            continue;
          }
          nvs_erase_key(*handle, key.c_str());
          err = nvs_set_u8(*handle, key.c_str(), static_cast<uint8_t>(value - 1));
          if (err != ESP_OK)
          {
            ESP_LOGE(SETTINGS_TAG, "Set new %s nvs value failed: %d", key.c_str(), err);
            nvs_close(*handle);
            return;
          }
        }

        err = nvs_set_i32(*handle, "config_version", 1);
        if (err != ESP_OK)
        {
          ESP_LOGE(SETTINGS_TAG, "Set config_version failed: %d", err);
          nvs_close(*handle);
          return;
        }

        nvs_commit(*handle);
        ESP_LOGI(SETTINGS_TAG, "Migrate settings completed: %d", value);
      }
    }

  public:
    void load()
    {
      esp_err_t err;
      nvs_handle_t handle;
      int32_t version;

      err = nvs_open("settings", NVS_READONLY, &handle);
      if (err != ESP_OK)
      {
        ESP_LOGE(SETTINGS_TAG, "nvs_open failed: %d", err);
        nvs_close(handle);
        return;
      }

      get_value(handle, "config_version", &version);
      migrate(&handle, version);

      get_value(handle, "input_method", &method);
      get_value(handle, "keyboard_layout", &layout);
      get_value(handle, "platform_os", &os);
      get_value(handle, "orientation", &orientation);
      get_value(handle, "developer_mode", &developer);
      get_value(handle, "poweroff_timer", &poweroff);
      ESP_LOGI(SETTINGS_TAG, "Load nvs values finished");

      nvs_close(handle);
    }

    void input_method(input_method_t new_method) { method = save("input_method", new_method); };
    input_method_t input_method() { return static_cast<input_method_t>(method); };
    const char *input_method_label() { return method ? "????????????: ????????????" : "????????????: ??????"; };

    void keyboard_layout(keyboard_layout_t new_layout) { layout = save("keyboard_layout", new_layout); };
    keyboard_layout_t keyboard_layout() { return static_cast<keyboard_layout_t>(layout); };
    const char *keyboard_layout_label() { return layout ? "???????????????: US??????" : "???????????????: ???????????????"; };

    void platform_os(platform_os_t new_os) { os = save("platform_os", new_os); };
    platform_os_t platform_os() { return static_cast<platform_os_t>(os); };
    const char *platform_os_label() { return os ? "OS: Mac" : "OS: Windows"; };

    void device_orientation(device_orientation_t new_orientation) { orientation = save("orientation", new_orientation); };
    device_orientation_t device_orientation() { return static_cast<device_orientation_t>(orientation); };
    const char *device_orientation_label() { return orientation ? "???????????????: ????????????" : "???????????????: ??????"; };

    void developer_mode(bool enable) { developer = save("developer_mode", enable ? 1 : 0); };
    bool developer_mode() { return static_cast<bool>(developer); };

    void poweroff_timer(poweroff_timer_t new_poweroff) { poweroff = save("poweroff_timer", new_poweroff); };
    poweroff_timer_t poweroff_timer() { return static_cast<poweroff_timer_t>(poweroff); };
    const char *poweroff_timer_label()
    {
      switch (poweroff)
      {
      default:
        return "??????????????????: ??????";
      case poweroff_timer_5min:
        return "??????????????????: 5??????";
      case poweroff_timer_10min:
        return "??????????????????: 10??????";
      case poweroff_timer_15min:
        return "??????????????????: 15??????";
      case poweroff_timer_30min:
        return "??????????????????: 30??????";
      case poweroff_timer_60min:
        return "??????????????????: 1?????????";
      }
    };
  };
}
