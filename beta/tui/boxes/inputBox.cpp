#ifndef TUI_INPUT_BOX
#define TUI_INPUT_BOX

#include "interactionBox.cpp"

// Could have its own file.
class InputBox : public InteractionBox {
private:

public:
InputBox(int x, int y, int w, char i) : InteractionBox(x, y, w, 3, i) {
}

void onInteraction(char index) {
  int x = getX(), y = getY();

  vts_xy(x + 3, y + 1);
  // can allow movement by getting each charachter by himself. then vts.
  char input[getWidth()];
  cin.ignore();
  cin.getline(input, 100, '\n');
  setValue(string(input));
  return;
}

string getValue() {
  return TextBox::getValue().at(0);
}
};

#endif // ifndef TUI_INPUT_BOX
