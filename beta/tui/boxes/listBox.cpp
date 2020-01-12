#ifndef TUI_LIST_BOX
#define TUI_LIST_BOX

// #include <string>
// #include <vector>
//
#include "../tui.cpp"
#include "interactionBox.cpp"
#include "pickerBox.cpp"

#define LIST_BOX_START 97

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

  PickerBox *listBox = new PickerBox(x, y + height - 1, width, (int)values.size() + 2, LIST_BOX_START, this->values);

  auto pos = find(this->values.begin(), this->values.end(), oldValue);

  if (pos != this->values.end()) listBox->setIndexBoolean(distance(this->values.begin(), pos), true);

  list->registerBox(listBox);
  list->registerInteraction(listBox);
  list->registerEvent(listBox, this->pickEvent);

  list->setLoop(false);
  list->loop();

  if (listBox->getValue().size() != 1) return false;

  string newValue = listBox->getValue().at(0);
  setValue(newValue);

  return oldValue != newValue;
}

string getValue() {
  return TextBox::getValue().at(0);
}
};

#endif // ifndef
