#ifndef TUI_LIST_BOX
#define TUI_LIST_BOX

// #include <string>
// #include <vector>
//
#include "../tui.cpp"
#include "interactionBox.cpp"

// Could have its own file.
class PickerBox : public InteractionBox {
private:
vector<string> values;
TextBox *parent;

public:
PickerBox(int x, int y, int w, int h, vector<char> i, vector<string> values, TextBox *parent) : InteractionBox(x, y, w, h, i) {
  this->values = values;
  this->parent = parent;
  setValue(values);
}

void onInteraction(char index) {
  int actualIndex = index - 65;

  this->parent->setValue(this->values.at(actualIndex));
  return;
}
};

// // // // // // //

class ListBox : public InteractionBox {
private:
vector<string> values;

public:
ListBox(int x, int y, int w, char i, vector<string> values) : InteractionBox(x, y, w, 3, i) {
  this->values = values;
  this->setValue(values.at(0));
}

void onInteraction(char index) {
  Tui *list = new Tui();

  int x = getX(), y = getY();
  int width = getWidth(), height = getHeight();

  vector<char> interactions;

  for (int i = 0; i < (int)values.size(); ++i)
    interactions.push_back(65 + i);

  //InteractionBox *listBox = new InteractionBox(x, y + height - 1, width, (int)values.size(), interactions);
  PickerBox *listBox = new PickerBox(x, y + height - 1, width, 5, interactions, this->values, this);

  list->registerBox(listBox);
  list->registerInteraction(listBox);

  list->setLoop(false);
  list->loop();
  return;
}

string getValue() {
  return TextBox::getValue().at(0);
}
};

#endif // ifndef
