// SPDX-License-Identifier: Apache-2.0

#pragma once
#include <M5Unified.h>
#include "event.hpp"

namespace menu
{
  struct Menu
  {
  protected:
    void registerCursorMove();
    void unregisterCursorMove();

    void drawItems();
    void drawCursor();

    uint32_t width;
    uint32_t line_height;

    size_t cursor_index = 0;
    std::vector<std::string> labels;
    std::vector<std::function<void(void)>> callbacks;

  public:
    Menu();

    bool opened;
    bool active;

    void open();
    void close();
    void updateCursor(int32_t diff);
    void execute() const;

    void addItem(const char *text, std::function<void(void)> callback);
    void clearItems();
    void editItemLabel(uint32_t index, const char *text);
    size_t size() const { return labels.size(); };
  };
}

extern menu::Menu Menu;
