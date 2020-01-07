#ifndef TUI
#define TUI

#include <iostream>
#include <functional>
#include <algorithm>
#include <future>
#include <vector>
#include <map>

#include "vts.c"
#include "../utility/sleep.c"
#include "../utility/mapDeleteValue.cpp"
#include "boxes/box.cpp"
#include "boxes/textBox.cpp"
#include "boxes/interactionBox.cpp"

using namespace std;

class Tui {
private:
vector<Box *> boxes;
map<char, InteractionBox *> interactions;
map<char, function<void(char)> > events;
char exitChar;
bool shouldLoop;

void printAll() {
  for (unsigned long int i = 0; i < boxes.size(); ++i)
    boxes.at(i)->print();
}

public:
Tui() {
  setExitChar('0');
  setLoop(true);
  return;
}

Tui(int width, int height, string title) : Tui() {
  cp_sleep(250); // Must wait for the terminal window. there must be a better way.
  vts_resize(width, height);

  cp_sleep(50); // Must wait for the terminal window. there must be a better way.

  TextBox *root = new TextBox(0, 0, width, height);
  root->setTitle(title);
  registerBox(root);
}

void registerBox(Box *box) {
  boxes.push_back(box);
}

void deleteBox(Box *box) {
  boxes.erase(remove(boxes.begin(), boxes.end(), box), boxes.end());
}

void registerInteraction(InteractionBox *interactionBox) {
  for (unsigned long int i = 0; i < interactionBox->getInteractionIndex().size(); ++i)
    interactions.emplace(interactionBox->getInteractionIndex().at(i), interactionBox);
}

void deleteInteraction(InteractionBox *interactionBox) {
  mapDeleteValue(interactions, interactionBox);
}

void registerEvent(InteractionBox *interactionBox, function<void(int)> function) {
  for (unsigned long int i = 0; i < interactionBox->getInteractionIndex().size(); ++i)
    events.emplace(interactionBox->getInteractionIndex().at(i), function);
}

void deleteEvent(InteractionBox *);

char getExitChar() {
  return exitChar;
}

void setExitChar(char exitChar) {
  this->exitChar = exitChar;
}

bool getLoop() {
  return shouldLoop;
}

void setLoop(bool shouldLoop) {
  this->shouldLoop = shouldLoop;
}

// // // // // //

void loop() {
  do {
    printAll();

    // Input code. First row is reserved for input.
    vts_xy(1, 1);
    // vts_foregroundBlack();
    // vts_cursorHide();
    char input;
    cin >> input;
    // vts_foregroundDefault();
    // vts_cursorShow();

    // isExit(input) -> break
    if (input == getExitChar()) break;

    // isValid(input)
    if (interactions.count(input) == 1) {
      // Get the correct "interactionBox" instance and calls its handler.
      bool changed = interactions.at(input)->onInteraction(input);

      // isValid(input)
      if (changed && events.count(input) == 1) {
        // Get the correct function and calls it.
        events.at(input)(input);
        //
      }
    }

    // shouldLoop() or loopCount() -> continue or break
    // if (!getLoop()) break;
  } while (getLoop());
}
};

#endif // ifndef TUI
