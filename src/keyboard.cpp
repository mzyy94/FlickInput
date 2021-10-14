#include <algorithm>

#include "keyboard.hpp"
#include "key_button.hpp"

std::array<struct key_button, 19> key_buttons;

void set_alphabet_keybard()
{
  size_t i = 0;
  key_buttons[i++].set_text("→");
  key_buttons[i++].set_text("@#/&_", "@", "#", "/", "&", "_");
  key_buttons[i++].set_text("ABC", "A", "B", "C");
  key_buttons[i++].set_text("DEF", "D", "E", "F");
  key_buttons[i++].set_text("<x");
  key_buttons[i++].set_text("←");
  key_buttons[i++].set_text("GHI", "G", "H", "I");
  key_buttons[i++].set_text("JKL", "J", "K", "L");
  key_buttons[i++].set_text("MNO", "M", "N", "O");
  key_buttons[i++].set_text("空白", " ");
  key_buttons[i++].set_text("123");
  key_buttons[i++].set_text("PQRS", "P", "Q", "R", "S");
  key_buttons[i++].set_text("TUV", "T", "U", "V");
  key_buttons[i++].set_text("WXYZ", "W", "X", "Y", "Z");
  key_buttons[i++].set_text("改行");
  key_buttons[i++].set_text("(^_^)");
  key_buttons[i++].set_text("a/A");
  key_buttons[i++].set_text("'\"()", "\'", "\"", "(", ")");
  key_buttons[i++].set_text(".,?!", ".", ",", "?", "!");
}

void init_keyboard_layout()
{
  const int32_t x = 10, y = 560, w = 96, h = 78, pad = 10;

  for (size_t j = 0; j < 5; j++)
  {
    for (size_t i = 0; i < 4; i++)
    {
      key_buttons[i * 5 + j].init(x + (w + pad) * j, y + (h + pad) * i, w, (i == 2 && j == 4) ? h * 2 + pad : h, (j == 0 || j == 4) ? TFT_WHITE : TFT_BLACK, (j == 0 || j == 4) ? TFT_DARKGRAY : TFT_LIGHTGRAY);
      if (i == 2 && j == 4)
        break;
    }
  }
}

void draw_keyboard()
{
  M5.Display.startWrite();
  M5.Display.setTextSize(1);
  M5.Display.fillRect(0, 460, 540, 500, TFT_WHITE);
  for (auto &btn : key_buttons)
  {
    btn.draw();
  }

  M5.Display.endWrite();
}