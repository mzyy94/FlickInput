#pragma once
#include <M5Unified.h>
#include "event.hpp"

namespace menu
{
  class Menu
  {
  protected:
    int cursor_index = -1;
    std::vector<std::string> labels;
    std::vector<std::function<void(void)>> callbacks;

    void drawItems();
    void drawCursor();

  public:
    Menu();

    uint32_t width;
    uint32_t line_height;
    bool opened;

    void update();
    void openMenu();
    void closeMenu();

    void addItem(const char *text, std::function<void(void)> callback);
    void clearItems();
  };
}

extern menu::Menu Menu;
void setupMenu();
