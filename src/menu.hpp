#pragma once
#include <M5Unified.h>
#include "event.hpp"

namespace menu
{
  class Menu
  {
  protected:
    void registerCursorMove();
    void unregisterCursorMove();

  public:
    Menu();

    int cursor_index = -1;
    std::vector<std::string> labels;
    std::vector<std::function<void(void)>> callbacks;

    void drawItems();
    void drawCursor();

    uint32_t width;
    uint32_t line_height;
    bool opened;
    bool active;

    void openMenu();
    void closeMenu();

    void addItem(const char *text, std::function<void(void)> callback);
    void clearItems();
  };
}

extern menu::Menu Menu;
void setupMenu();
