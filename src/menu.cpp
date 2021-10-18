#include <M5Unified.h>
#include "menu.hpp"

namespace menu
{
  Menu::Menu()
      : width(360), line_height(48), opened(false)
  {
  }

  void Menu::drawItems()
  {
    const uint32_t padding = line_height / 2;
    uint32_t height = 2 * padding + labels.size() * line_height;
    uint32_t left = (M5.Display.width() - width) / 2;
    uint32_t top = (M5.Display.height() - height) / 2;

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

    uint32_t height = padding + labels.size() * line_height;
    uint32_t left = (M5.Display.width() - width) / 2;
    uint32_t top = (M5.Display.height() - height) / 2;
    uint32_t offset = top + cursor_index * line_height + line_height / 4;

    uint32_t size = (line_height / 4);
    uint32_t x = left + size * 1;
    uint32_t x1 = left + size * 3;
    uint32_t y0 = offset + size * 1;
    uint32_t y1 = offset + size * 3;
    uint32_t y2 = offset + size * 2;

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
    opened = true;
    cursor_index = 0;
    drawItems();
    drawCursor();
  }

  void Menu::closeMenu()
  {
    opened = false;
    cursor_index = -1;
  }

  void Menu::update()
  {
    if (M5.BtnB.wasClicked())
    {
      if (!opened)
      {
        openMenu();
      }
      else
      {
        auto callback = callbacks[cursor_index];
        callback();
      }
    }
    if (M5.BtnA.wasClicked())
    {
      if (opened)
      {
        cursor_index--;
        if (cursor_index < 0)
          cursor_index = labels.size() - 1;
        drawCursor();
      }
    }
    if (M5.BtnC.wasClicked())
    {
      if (opened)
      {
        cursor_index++;
        if (cursor_index >= labels.size())
          cursor_index = 0;
        drawCursor();
      }
    }
  }
}

menu::Menu Menu;
