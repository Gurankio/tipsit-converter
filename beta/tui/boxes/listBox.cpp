#ifndef TUI_LIST_BOX
#define TUI_LIST_BOX

// #include <string>
// #include <vector>
//
#include "../tui.cpp"
#include "interactionBox.cpp"

#define LIST_BOX_OFFSET 97

// Could have its own file.
class PickerBox : public InteractionBox {
private:
vector<string> values;
TextBox *parent;
function<void(char)> pickEvent;

public:
PickerBox(int x, int y, int w, int h, vector<char> i, vector<string> values, TextBox *parent) : InteractionBox(x, y, w, h, i) {
  this->values = values;
  this->parent = parent;

  setValue(values);
}

bool onInteraction(char index) {
  int actualIndex = index - LIST_BOX_OFFSET;
  string oldValue = this->parent->getValue().at(0);
  string newValue = this->values.at(actualIndex);

  this->parent->setValue(newValue);
  return oldValue != newValue;
}
};

// // // // // // //

class ListBox : public InteractionBox {
private:
vector<string> values;
function<void(char)> pickEvent;

public:
ListBox(int x, int y, int w, char i, vector<string> values) : InteractionBox(x, y, w, 3, i) {
  this->values = values;
  this->setValue("Empty");
}

void setPickEvent(function<void(char)> pickEvent) {
  this->pickEvent = pickEvent;
}

bool onInteraction(char index) {
  Tui *list = new Tui();
  int x = getX(), y = getY();
  int width = getWidth(), height = getHeight();
  string oldValue = getValue();
  vector<char> interactions;

  for (int i = 0; i < (int)values.size(); ++i)
    interactions.push_back(LIST_BOX_OFFSET + i);

  PickerBox *listBox = new PickerBox(x, y + height - 1, width, (int)values.size() + 2, interactions, this->values, this);

  list->registerBox(listBox);
  list->registerInteraction(listBox);
  list->registerEvent(listBox, this->pickEvent);

  list->setLoop(false);
  list->loop();

  return oldValue != getValue();
}

string getValue() {
  return TextBox::getValue().at(0);
}
};

#endif // ifndef
