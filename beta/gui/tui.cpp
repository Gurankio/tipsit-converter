#include <iostream>
#include <string>
#include <locale>

#include <map>

// #include <vector>
// #include <array>

// #include <atomic>
#include <chrono>
#include <future>

#include "vts.cpp"
#include "numeric.cpp"

// #include <thread>

#ifdef _WIN32
// Windows ONLY libraries and constants.
  #include <windows.h>

  #define TUI_FORMAT     "%c"

  #define TUI_SPACE      32
  #define TUI_VERTICAL   179
  #define TUI_HORIZONTAL 196
  #define TUI_CORNER_TL  218
  #define TUI_CORNER_TR  191
  #define TUI_CORNER_BL  192
  #define TUI_CORNER_BR  217

#else
// Non windows platforms should support wide characters.
  #define TUI_SPACE      " "
  #define TUI_HORIZONTAL "q"
  #define TUI_VERTICAL   "x"
  #define TUI_CORNER_TL  "l"
  #define TUI_CORNER_TR  "k"
  #define TUI_CORNER_BL  "m"
  #define TUI_CORNER_BR  'j' // L before string make it print its hex value

#endif /* ifdef _WIN32 */

using namespace std;

//  //
//  //
//  //
// Worth reading:
// https://docs.microsoft.com/en-us/cpp/cpp/string-and-character-literals-cpp?view=vs-2019
// https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences


// TODO: could have missed someone


//  //
//  //
//  //

class Tui {
private:
int width, height;
string title;

public:
Tui(int, int);
// ~Tui();

// Getters and Setters
int getWidth();
void setWidth(int);
int getHeight();
void setHeight(int);

//
void test(int, int);
};

Tui::Tui(int width, int height) {
  this->width = width;
  this->height = height;
  VTS vts;
  vts.resize(width, height);
}

int Tui::getWidth() {
  return this->width;
}

void Tui::setWidth(int width) {
  this->width = width;
  // set terminal size again.
}

int Tui::getHeight() {
  return this->width;
}

void Tui::test(int x, int y) {
  cout << getWidth();
}

//  //
//  //
//  //

void printBox(int x, int y, int width, int height) {
  VTS vts;

  vts.lineDrawingSet();

  // Top
  vts.xy(x, y);
  cout << TUI_CORNER_TL;

  for (int i = 0; i < width; i++)
    cout << TUI_HORIZONTAL;

  cout << TUI_CORNER_TR << flush;

  // Middle
  for (int i = 1; i <= height; i++) {
    vts.xy(x, y + i);
    cout << TUI_VERTICAL;

    for (int j = 0; j < width; j++)
      cout << TUI_SPACE;

    cout << TUI_VERTICAL << flush;
  }

  // Bottom
  vts.xy(x, y + height + 1);
  cout << TUI_CORNER_BL;

  for (int i = 0; i < width; i++)
    cout << TUI_HORIZONTAL;

  cout << TUI_CORNER_BR << flush;

  vts.asciiSet();
}

int main() {
  Tui tui = Tui(120, 24);

  tui.test(3, 3);
  VTS vts;

  for (int i = 0; i <= 50; i++) {
    int w = i * 2.5 * 2.1, h = i * 0.9;
    vts.clear();
    vts.resize(w + 1, h + 1);
    printBox(0, 0, w - 1, h);
    this_thread::sleep_for(chrono::milliseconds(250));
  }

  //vts.xy(0, 0);
}
