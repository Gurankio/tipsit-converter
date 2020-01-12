#ifndef TUI_BUTTON_BOX
#define TUI_BUTTON_BOX

#include <functional>

#include "interactionBox.cpp"
#include "../constants.cpp"

class ButtonBox : public InteractionBox {
private:
function<void(void)> action;

public:
ButtonBox(int x, int y, int w, char i, function<void(void)> action) : InteractionBox(x, y, w, 3, i) {
  this->action = action;
}

function<void(void)> getAction() {
  return action;
}

bool onInteraction(char index) {
  getAction()();
  return true;
}

void printExtra() {
  TextBox::printExtra();

  int x = getX(), y = getY();
  int width = getWidth(), height = getHeight();

  vts_lineDrawingSet();

  vts_xy(x, y);
  cout << "/";

  for (int i = 1; i < width; i++) {
    vts_xy(x + i, y - 1);
    cout << "_";
  }

  vts_xy(x + width - 1, y);
  cout << "/";

  for (int i = 0; i < height - 1; i++) {
    vts_xy(x + width, y + i);
    cout << TUI_VERTICAL;
  }

  vts_xy(x + width - 1, y + height - 1);
  cout << "/";

  /*
     vts_xy(x, y + height - 1);
     cout << TUI_INTER_TR;

     vts_xy(x + 1, y + height);
     cout << "\\";

     for (int i = 0; i < width - 1; i++)
     cout << TUI_HORIZONTAL;

     cout << TUI_CORNER_BR;

     vts_xy(x + width + 1, y + 1);
     cout << "\\";

     for (int i = 2; i < height; i++) {
     vts_xy(x + width + 1, y + i);
     cout << TUI_VERTICAL;
     }
   */

  vts_asciiSet();
}
};

#endif // ifndef TUI_BUTTON_BOX
