#include <M5Unified.h>
#include "menu.hpp"
#include "event.hpp"
#include "button.hpp"

namespace menu
{

  static void set_active(menu::Menu *m)
  {
    m->active = true;
  }

  static void move_cursor(void *event_handler_arg,
                          esp_event_base_t event_base,
                          int32_t event_id,
                          void *event_data)
  {
    auto *m = (menu::Menu *)event_handler_arg;
    if (!m->active)
      return;
    m->cursor_index += (event_id == BUTTON_EVENT_PRESSED_A ? m->labels.size() - 1 : 1);
    m->cursor_index %= m->labels.size();
    m->drawCursor();
  }

  static void select_item(void *event_handler_arg,
                          esp_event_base_t event_base,
                          int32_t event_id,
                          void *event_data)
  {
    const auto *m = (menu::Menu *)event_handler_arg;
    if (!m->active)
      return;
    auto callback = m->callbacks[m->cursor_index];
    callback();
  }

  Menu::Menu()
      : width(360), line_height(48), opened(false), active(false)
  {
  }

  void Menu::drawItems()
  {
    const uint32_t padding = line_height / 2;
    const uint32_t height = 2 * padding + labels.size() * line_height;
    const uint32_t left = (M5.Display.width() - width) / 2;
    const uint32_t top = (M5.Display.height() - height) / 2;

    portENTER_CRITICAL_ISR(&mutex);
    M5.Display.startWrite();
    M5.Display.setTextColor(TFT_BLACK, TFT_WHITE);
    M5.Display.setTextSize(1);
    M5.Display.fillRect(left, top, width, height, TFT_WHITE);
    M5.Display.drawRect(left, top, width, height, TFT_BLACK);
    for (size_t i = 0; i < labels.size(); i++)
    {
      M5.Display.drawString(
          labels[i].c_str(),
          left + line_height,
          padding + top + i * line_height,
          &fonts::lgfxJapanGothicP_40);
    }
    M5.Display.endWrite();
    portEXIT_CRITICAL_ISR(&mutex);
  }

  void Menu::drawCursor()
  {
    const uint32_t padding = line_height / 2;

    const uint32_t height = padding + labels.size() * line_height;
    const uint32_t left = (M5.Display.width() - width) / 2;
    const uint32_t top = (M5.Display.height() - height) / 2;
    const uint32_t offset = top + cursor_index * line_height + line_height / 4;

    const auto size = line_height / 4,
               x = left + size * 1,
               x1 = left + size * 3,
               y0 = offset + size * 1,
               y1 = offset + size * 3,
               y2 = offset + size * 2;

    portENTER_CRITICAL_ISR(&mutex);
    M5.Display.startWrite();
    M5.Display.fillRect(x, top + size * 1, size * 2, height - size * 2, TFT_WHITE);
    M5.Display.fillTriangle(x, y0, x, y1, x1, y2, TFT_BLACK);
    M5.Display.endWrite();
    portEXIT_CRITICAL_ISR(&mutex);
  }

  void Menu::addItem(const char *text, std::function<void(void)> callback)
  {
    labels.push_back(std::string(text));
    callbacks.push_back(callback);
  }

  void Menu::clearItems()
  {
    labels.clear();
    callbacks.clear();
  }

  void Menu::openMenu()
  {
    registerCursorMove();
    opened = true;
    cursor_index = 0;
    drawItems();
    drawCursor();

    // Wait to set active state until rendering completed
    dispatch_after(100, set_active, this);
  }

  void Menu::closeMenu()
  {
    unregisterCursorMove();
    active = false;
    opened = false;
    cursor_index = -1;
  }

  void Menu::registerCursorMove()
  {
    register_button_pressed(A, move_cursor, this);
    register_button_pressed(B, select_item, this);
    register_button_pressed(C, move_cursor, this);
  }

  void Menu::unregisterCursorMove()
  {
    unregister_button_pressed(A, move_cursor);
    unregister_button_pressed(B, select_item);
    unregister_button_pressed(C, move_cursor);
  }
}

menu::Menu Menu;
