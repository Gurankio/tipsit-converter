#ifndef TUI_PICKER_BOX
#define TUI_PICKER_BOX

// #include <string>
// #include <vector>
//
#include "../tui.cpp"
#include "interactionBox.cpp"

class PickerBox : public InteractionBox {
private:
bool multiple;
char starting;
vector<string> values;
map<int, bool> booleanValue;

PickerBox(int x, int y, int w, int h, char starting) : InteractionBox(x, y, w, h) {
  this->starting = starting;
  setMultiple(false);
}

public:
PickerBox(int x, int y, int w, int h, char starting, vector<string> values) : PickerBox(x, y, w, h, starting) {
  this->values = values;

  vector<char> interactions;

  for (int i = 0; i < (int)values.size(); i++) {
    this->booleanValue.emplace(i, false);
    interactions.push_back(this->starting + i);
  }

  setInteractionIndex(interactions);
  setValue(values);
}

void setMultiple(bool multiple) {
  this->multiple = multiple;
}

vector<string> getValue() {
  vector<string> trueValues;

  for (auto i = booleanValue.begin(); i != booleanValue.end(); i++)
    if (i->second) trueValues.push_back(this->values.at(i->first));

  return trueValues;
}

void setIndexBoolean(int index, bool value) {
  this->booleanValue.at(index) = value;
}

bool onInteraction(char index) {
  int actualIndex = index - this->starting;

  if (this->multiple) {
    this->booleanValue.at(actualIndex) = !this->booleanValue.at(actualIndex);
    return true;
  }

  // If it is alredy true, quit and return false (did not change).
  if (this->booleanValue.at(actualIndex) == true) return false;

  for (auto i = this->booleanValue.begin(); i != this->booleanValue.end(); i++)
    i->second = false;

  this->booleanValue.at(actualIndex) = true;
  return true;
}

void printExtra() {
  TextBox::printExtra();

  int x = getX(), y = getY();
  int width = getWidth();

  // Left

  unsigned long int maxLeftLength = 0;

  for (int i = 0; i < (int)getLeft().size(); ++i)
    if (getLeft().at(i).length() > maxLeftLength) maxLeftLength = getLeft().at(i).length();

  // Right

  unsigned long int maxRightLength = 0;

  for (int i = 0; i < (int)getRight().size(); ++i)
    if (getRight().at(i).length() > maxRightLength) maxRightLength = getRight().at(i).length();

  // Value

  for (int i = 0; i < (int)this->values.size(); ++i) {
    if (this->values.at(i).length() < width - (maxLeftLength + maxRightLength) / 2) {
      if (booleanValue.at(i)) vts_textBold();

      vts_xy(x + (maxLeftLength / 2) + 2, y + 1 + i);
      cout << this->values.at(i);
      vts_textDefault();
    }
  }
}
};

#endif // ifndef TUI_PICKER_BOX
