#ifndef TUI_OUTPUT_BOX
#define TUI_OUTPUT_BOX

// #include <string>
// #include <vector>
//

#include "../tui.cpp"
#include "interactionBox.cpp"
#include "../../utility/stringCountSplit.cpp"

#define LIST_BOX_START 97

// // // // // // //

class OutputBox : public InteractionBox {
private:
char interaction;
bool longer = false;
string longerStrings;

public:
OutputBox(int x, int y, int w, int h, char i) : InteractionBox(x, y, w, h, i) {
  interaction = i;
}

void setValue(string value) {
  unsigned long int maxLength = getWidth() - (getMaxLeftLength() + getMaxRightLength()) / 2;

  if (value.length() > maxLength) {
    longer = true;
    longerStrings = value;
    TextBox::setValue("Interact to expand...");
  } else {
    longer = false;
    TextBox::setValue(value);
  }
}

void printExtra() {
  if (longer) setLeft(stringFormat("%c%c%c", '(', interaction, ')'));
  else setLeft("");

  TextBox::printExtra();
}

bool onInteraction(char index) {
  if (!longer) return false;

  // const int PADDING = 8;

  TextBox *longerBox = new TextBox(1, 2, 100 - 2, 40 - 3);
  longerBox->setValue(stringCountSplit(longerStrings, 100 - 4));

  Tui *fullView = new Tui();
  fullView->registerBox(longerBox);
  fullView->setLoop(true);
  fullView->loop();

  return true;
}
};

#endif // ifndef TUI_OUTPUT_BOX
