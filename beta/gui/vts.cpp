#include <iostream>
#include <string>

using namespace std;

class VTS {
private:
string escape;

void activateCommands();

public:
VTS();

void flush();

// Miscellanous

void title(string);
void resize(int, int);
void clear();
void lineDrawingSet();
void asciiSet();

// Cursor

void xy(int, int);

// Text Modifier

void textBold();
void textLowIntesity();
void textUnderline();
void textBlinking();
void textReverse();
void textInvisible();

void textModifierReset();

// Text Colors

void textBlack();
void textRed();
void textGreen();
void textYellow();
void textBlue();
void textMagenta();
void textCyan();
void textWhite();

void textBrightBlack();
void textBrightRed();
void textBrightGreen();
void textBrightYellow();
void textBrightBlue();
void textBrightMagenta();
void textBrightCyan();
void textBrightWhite();

void textColorReset();

// Background Colors

void backgroundBlack();
void backgroundRed();
void backgroundGreen();
void backgroundYellow();
void backgroundBlue();
void backgroundMagenta();
void backgroundCyan();
void backgroundWhite();

void backgroundBrightBlack();
void backgroundBrightRed();
void backgroundBrightGreen();
void backgroundBrightYellow();
void backgroundBrightBlue();
void backgroundBrightMagenta();
void backgroundBrightCyan();
void backgroundBrightWhite();

void backgroundReset();
};


#ifdef _WIN32
void VTS::activateCommands() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD consoleMode;

  GetConsoleMode(hConsole, &consoleMode);
  consoleMode |= 0x004;

  if (!SetConsoleMode(hConsole, consoleMode)) cout << "Error during activation. Check for windows updates." << endl;

  // Should quit.
}

#else
void VTS::activateCommands() {
  // NO-OP
  // There is no need on non windows systems.
}

#endif /* ifdef _WIN32 */

VTS::VTS() {
  activateCommands();
  this->escape = "\e";
}

void VTS::flush() {
  cout << "" << std::flush;
}

//

void VTS::title(string title) {
  //]0;hello\x07 unknown meanings!
  cout << this->escape + "]0;" + title + "\x07";
}

void VTS::resize(int width, int height) {
  // [8;50;100t what does the mean?
  cout << this->escape + "[8;" + to_string(height) + ";" + to_string(width) + "t";
  this->flush();
}

void VTS::clear() {
  cout << this->escape + "[2J";
  this->flush();
}

void VTS::lineDrawingSet() {
  cout << this->escape + "(0";
  this->flush();
}

void VTS::asciiSet() {
  cout << this->escape + "(B";
  this->flush();
}

// Cursor
void VTS::xy(int x, int y) {
  cout << this->escape + "[" + to_string(y + 1) + ";" + to_string(x) + "H";
  this->flush();
}

// Text Modifier

void VTS::textBold() {
  cout << this->escape + "[1m";
  this->flush();
}

void VTS::textLowIntesity() {
  cout << this->escape + "[2m";
  this->flush();
}

void VTS::textUnderline() {
  cout << this->escape + "[4m";
  this->flush();
}

void VTS::textBlinking() {
  cout << this->escape + "[5m";
  this->flush();
}

void VTS::textReverse() {
  cout << this->escape + "[7m";
  this->flush();
}

void VTS::textInvisible() {
  cout << this->escape + "[8m";
  this->flush();
}

void VTS::textModifierReset() {
  cout << this->escape + "[9m";
  this->flush();
}

// Text Colors

void VTS::textBlack() {
  cout << this->escape + "[30m";
  this->flush();
}

void VTS::textRed() {
  cout << this->escape + "[31m";
  this->flush();
}

void VTS::textGreen() {
  cout << this->escape + "[32m";
  this->flush();
}

void VTS::textYellow() {
  cout << this->escape + "[33m";
  this->flush();
}

void VTS::textBlue() {
  cout << this->escape + "[34m";
  this->flush();
}

void VTS::textMagenta() {
  cout << this->escape + "[35m";
  this->flush();
}

void VTS::textCyan() {
  cout << this->escape + "[36m";
  this->flush();
}

void VTS::textWhite() {
  cout << this->escape + "[37m";
  this->flush();
}

//

void VTS::textBrightBlack() {
  cout << this->escape + "[91m";
  this->flush();
}

void VTS::textBrightRed() {
  cout << this->escape + "[91m";
  this->flush();
}

void VTS::textBrightGreen() {
  cout << this->escape + "[92m";
  this->flush();
}

void VTS::textBrightYellow() {
  cout << this->escape + "[93m";
  this->flush();
}

void VTS::textBrightBlue() {
  cout << this->escape + "[94m";
  this->flush();
}

void VTS::textBrightMagenta() {
  cout << this->escape + "[95m";
  this->flush();
}

void VTS::textBrightCyan() {
  cout << this->escape + "[96m";
  this->flush();
}

void VTS::textBrightWhite() {
  cout << this->escape + "[97m";
  this->flush();
}

//

void VTS::textColorReset() {
  cout << this->escape + "[39m";
  this->flush();
}

// Background Colors

void VTS::backgroundBlack() {
  cout << this->escape + "[40m";
  this->flush();
}

void VTS::backgroundRed() {
  cout << this->escape + "[41m";
  this->flush();
}

void VTS::backgroundGreen() {
  cout << this->escape + "[42m";
  this->flush();
}

void VTS::backgroundYellow() {
  cout << this->escape + "[43m";
  this->flush();
}

void VTS::backgroundBlue() {
  cout << this->escape + "[44m";
  this->flush();
}

void VTS::backgroundMagenta() {
  cout << this->escape + "[45m";
  this->flush();
}

void VTS::backgroundCyan() {
  cout << this->escape + "[46m";
  this->flush();
}

void VTS::backgroundWhite() {
  cout << this->escape + "[47m";
  this->flush();
}

//

void VTS::backgroundBrightBlack() {
  cout << this->escape + "[100m";
  this->flush();
}

void VTS::backgroundBrightRed() {
  cout << this->escape + "[101m";
  this->flush();
}

void VTS::backgroundBrightGreen() {
  cout << this->escape + "[102m";
  this->flush();
}

void VTS::backgroundBrightYellow() {
  cout << this->escape + "[102m";
  this->flush();
}

void VTS::backgroundBrightBlue() {
  cout << this->escape + "[104m";
  this->flush();
}

void VTS::backgroundBrightMagenta() {
  cout << this->escape + "[105m";
  this->flush();
}

void VTS::backgroundBrightCyan() {
  cout << this->escape + "[106m";
  this->flush();
}

void VTS::backgroundBrightWhite() {
  cout << this->escape + "[107m";
  this->flush();
}

//

void VTS::backgroundReset() {
  cout << this->escape + "[49m";
  this->flush();
}
