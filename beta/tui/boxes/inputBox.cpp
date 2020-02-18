#ifndef TUI_INPUT_BOX
#define TUI_INPUT_BOX

#include <string.h>

#include "interactionBox.cpp"

// Could have its own file.
class InputBox : public InteractionBox {
private:

public:
InputBox(int x, int y, int w, char i) : InteractionBox(x, y, w, 3, i) {
}

bool onInteraction(char index) {
  int x = getX(), y = getY();
  string oldValue = getValue();

  vts_xy(x + 3, y + 1);

  for (int i = 0; i < getWidth() - 4; ++i) cout << " ";

  vts_xy(x + 3, y + 1);
  char input[getWidth()];
  for (int i=0; i<getWidth(); i++) {
    input[i] = '\0';
  }
  cin.ignore();
  cin.getline(input, getWidth(), '\n');

  if (input[0] == '\0') return false;

  setValue(string(input));
  return oldValue != getValue();
}

string getValue() {
  return TextBox::getValue().at(0);
}
};

#endif // ifndef TUI_INPUT_BOX
