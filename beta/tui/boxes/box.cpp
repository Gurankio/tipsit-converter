#ifndef TUI_BOX
#define TUI_BOX

#include <iostream>
#include "../constants.cpp"
#include "../vts.c"

using namespace std;

class Box {
private:
int x, y, width, height;
bool visible, extraVisible, fixed;

public:
Box(int x, int y, int width, int height) {
  this->x = x;
  this->y = y;
  this->width = width < 3 ? 0 : width - 2;
  this->height = height < 3 ? 0 : height - 2;
  setVisible(true);
  setExtraVisible(true);
  setFixed(true);
}

int getX() {
  return x;
}

int getY() {
  return y;
}

int getWidth() {
  return width + 2;
}

int getHeight() {
  return height + 2;
}

bool getVisible() {
  return visible;
}

bool getExtraVisible() {
  return extraVisible;
}

bool isFixed() {
  return fixed;
}

void setVisible(bool visible) {
  this->visible = visible;
}

void setExtraVisible(bool extraVisible) {
  this->extraVisible = extraVisible;
}

void setFixed(bool fixed) {
  this->fixed = fixed;
}

void print() {
  if (!getVisible()) return;

  vts_lineDrawingSet();

  // Top
  vts_xy(x, y);
  cout << TUI_CORNER_TL;

  for (int i = 0; i < width; i++)
    cout << TUI_HORIZONTAL;

  cout << TUI_CORNER_TR;

  // Middle
  for (int i = 1; i <= height; i++) {
    vts_xy(x, y + i);
    cout << TUI_VERTICAL;

    for (int j = 0; j < width; j++)
      cout << TUI_SPACE;

    cout << TUI_VERTICAL;
  }

  // Bottom
  vts_xy(x, y + height + 1);
  cout << TUI_CORNER_BL;

  for (int i = 0; i < width; i++)
    cout << TUI_HORIZONTAL;

  cout << TUI_CORNER_BR;

  vts_asciiSet();

  if (getExtraVisible()) printExtra();
}

virtual void printExtra() {
  return;
}
};

#endif // ifndef TUI_BOX
