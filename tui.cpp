#include <iostream>
#include <string>
#include <locale>

#include <map>

// #include <vector>
// #include <array>

// #include <atomic>
#include <chrono>
#include <future>

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
  #define TUI_FORMAT     "%s"

  #define TUI_SPACE      " "
  #define TUI_HORIZONTAL "─"
  #define TUI_VERTICAL   "│"
  #define TUI_CORNER_TL  "┌"
  #define TUI_CORNER_TR  "┐"
  #define TUI_CORNER_BL  "└"
  #define TUI_CORNER_BR  "┘" // L before string make it print its hex value

#endif /* ifdef _WIN32 */

using namespace std;

//  //
//  //
//  //
// Worth reading:
// https://docs.microsoft.com/en-us/cpp/cpp/string-and-character-literals-cpp?view=vs-2019
// https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences


// TODO: could have missed someone
class CSI {

private:
  string command;

  void activateCommands();

public:
  CSI();

  string getCommand();
  void setCommand(string);
  CSI reset();
  void execute();

  // Miscellanous

  CSI title(string);
  CSI resize(int, int);
  CSI clear();
  CSI lineDrawingSet();
  CSI asciiSet();

  // Cursor
  CSI xy(int, int);

  // Text Modifier

  CSI textBold();
  CSI textLowIntesity();
  CSI textUnderline();
  CSI textBlinking();
  CSI textReverse();
  CSI textInvisible();

  CSI textModifierReset();

  // Text Colors

  CSI textRed();
  CSI textGreen();
  CSI textYellow();
  CSI textBlue();
  CSI textMagenta();
  CSI textCyan();
  CSI textWhite();

  CSI textBrightRed();
  CSI textBrightGreen();
  CSI textBrightYellow();
  CSI textBrightBlue();
  CSI textBrightMagenta();
  CSI textBrightCyan();
  CSI textBrightWhite();

  CSI textColorReset();

  // Background Colors

  CSI backgroundRed();
  CSI backgroundGreen();
  CSI backgroundYellow();
  CSI backgroundBlue();
  CSI backgroundMagenta();
  CSI backgroundCyan();
  CSI backgroundWhite();

};

#ifdef _WIN32
void CSI::activateCommands() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD consoleMode;

  GetConsoleMode(hConsole, &consoleMode);
  consoleMode |= 0x004;

  if (!SetConsoleMode(hConsole, consoleMode)) {
    cout << "Error during activation. Check for windows updates." << endl;
    // Should quit.
  }
}

#else
void CSI::activateCommands() {
  // NO-OP
  // There is no need on non windows systems.
}

#endif /* ifdef _WIN32 */

CSI::CSI() {
  activateCommands();
  reset();
}

string CSI::getCommand() {
  return this->command;
}

void CSI::setCommand(string command) {
  this->command = command;
}

CSI CSI::reset() {
  this->command = "\e";
  return *this;
}

// TODO: auto executes.
void CSI::execute() {
  cout << this->command << flush;
}

CSI CSI::title(string title) {
  //]0;hello\x07 unknown meanings!
  this->command += "]0;" + title + "\x07";
  return *this;
}

CSI CSI::resize(int width, int height) {
  // [8;50;100t what does the mean?
  this->command += "[8;" + to_string(height) + ";" + to_string(width) + "t";
  return *this;
}

CSI CSI::clear(){
  this->command += "[2J";
  return *this;
}

CSI CSI::lineDrawingSet(){
  this->command += "(0";
  return *this;
}

CSI CSI::asciiSet(){
  this->command += "(B";
  return *this;
}

// Cursor
CSI CSI::xy(int x, int y) {
  this->command += "[" + to_string(y + 1) + ";" + to_string(x) + "H";
  return *this;
}

// Text Modifier

CSI CSI::textBold() {
  this->command += "[1m";
  return *this;
}

CSI CSI::textLowIntesity() {
  this->command += "[2m";
  return *this;
}

CSI CSI::textUnderline() {
  this->command += "[4m";
  return *this;
}

CSI CSI::textBlinking() {
  this->command += "[5m";
  return *this;
}

CSI CSI::textReverse(){
  this->command += "[7m";
  return *this;
}

CSI CSI::textInvisible() {
  this->command += "[8m";
  return *this;
}

CSI CSI::textModifierReset() {
  this->command += "[9m";
  return *this;
}

// Text Colors

CSI CSI::textRed(){return *this;}
CSI CSI::textGreen(){return *this;}
CSI CSI::textYellow(){return *this;}
CSI CSI::textBlue(){return *this;}
CSI CSI::textMagenta(){return *this;}
CSI CSI::textCyan(){return *this;}
CSI CSI::textWhite(){return *this;}

CSI CSI::textBrightRed(){return *this;}
CSI CSI::textBrightGreen(){return *this;}
CSI CSI::textBrightYellow(){return *this;}
CSI CSI::textBrightBlue(){return *this;}
CSI CSI::textBrightMagenta(){return *this;}
CSI CSI::textBrightCyan(){return *this;}
CSI CSI::textBrightWhite(){return *this;}

CSI CSI::textColorReset(){return *this;}

// Background Colors

CSI CSI::backgroundRed(){return *this;}
CSI CSI::backgroundGreen(){return *this;}
CSI CSI::backgroundYellow(){return *this;}
CSI CSI::backgroundBlue(){return *this;}
CSI CSI::backgroundMagenta(){return *this;}
CSI CSI::backgroundCyan(){return *this;}
CSI CSI::backgroundWhite(){return *this;}

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
  CSI csi;
  csi.resize(width, height).execute();
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

void print_box(int x, int y, int width, int height) {
  CSI csi;
  csi.xy(x, y).execute();
  printf(TUI_FORMAT, TUI_CORNER_TL);

  for (int i = 0; i < width; i++)
    printf(TUI_FORMAT, TUI_HORIZONTAL);

  printf(TUI_FORMAT, TUI_CORNER_TR);

  for (int i = 1; i <= height; i++) {
    csi.reset().xy(x, y + i).execute();
    printf(TUI_FORMAT, TUI_VERTICAL);

    for (int j = 0; j < width; j++)
      printf(TUI_FORMAT, TUI_SPACE);

    printf(TUI_FORMAT, TUI_VERTICAL);
  }

  // bottom
  csi.reset().xy(x, y + height + 1).execute();
  printf(TUI_FORMAT, TUI_CORNER_BL);

  for (int i = 0; i < width; i++)
    printf(TUI_FORMAT, TUI_HORIZONTAL);

  printf(TUI_FORMAT, TUI_CORNER_BR);
}

int main() {
  // cout << "\e[8;50;100t";   // works!
  // cout << "\e]0;hello\x07"; // works!8
  //
  cout << "\e(0";
  cout << "jklmnqtuvwz" << endl;
  cout << "\e(B";

  // // ESC [ ? 1 0 4 9 h

  Tui tui = Tui(120, 24);
  tui.test(3, 3);

  for (int i=0; i<=50; i++) {
    CSI csi;
    int w = i*2.5, h = i;
    csi.resize(w+1, h+1).execute();
    this_thread::sleep_for(chrono::milliseconds(150));
    csi.reset().clear().execute();
    print_box(0, 0, w-1, h-1);
    cout << flush;
  }
}
