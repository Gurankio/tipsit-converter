#ifndef TUI_INTERACTION_BOX
#define TUI_INTERACTION_BOX

#include <string>
#include <vector>

#include "../../utility/stringFormat.cpp"
#include "textBox.cpp"

class InteractionBox : public TextBox {
private:
vector<char> interactionIndex;

public:
InteractionBox(int x, int y, int width, int height, char interactionIndex) : TextBox(x, y, width, height) {
  this->interactionIndex.push_back(interactionIndex);
  vector<string> temp = { stringFormat("%c%c%c", '(', interactionIndex, ')') };
  this->setLeft(temp);
}

InteractionBox(int x, int y, int width, int height, vector<char> interactionIndex) : TextBox(x, y, width, height) {
  this->interactionIndex = interactionIndex;
  vector<string> temp;

  for (int i = 0; i < (int)interactionIndex.size(); ++i)
    temp.push_back(stringFormat("%c%c%c", '(', interactionIndex.at(i), ')'));

  this->setLeft(temp);
}

vector<char> getInteractionIndex() {
  return interactionIndex;
}

virtual bool onInteraction(char index) {
  return false;
}
};

#endif // ifndef TUI_INTERACTION_BOX
