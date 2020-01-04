#ifndef TUI_BUTTON_BOX
#define TUI_BUTTON_BOX

#include <functional>

#include "interactionBox.cpp"

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
};

#endif // ifndef TUI_BUTTON_BOX
