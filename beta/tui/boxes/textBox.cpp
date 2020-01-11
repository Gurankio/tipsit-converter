#ifndef TUI_TEXT_BOX
#define TUI_TEXT_BOX

#include <string>
#include <vector>

#include "../../utility/stringRemoveAll.cpp"
#include "../../utility/stringFormat.cpp"
#include "../../utility/stringSplit.cpp"
#include "box.cpp"


using namespace std;

class TextBox : public Box {
private:
static string pattern;
string top = "";
string bottom = "";
vector<string> left;
vector<string> right;
vector<string> value;

public:
TextBox(int x, int y, int width, int height) : Box(x, y, width, height) {
  for (int i = 0; i < height - 2; ++i)
    value.push_back("");
}

string getTop() {
  return top;
}

string getBottom() {
  return bottom;
}

vector<string> getLeft() {
  return left;
}

vector<string> getRight() {
  return right;
}

vector<string> getValue() {
  return value;
}

void setTop(string top) {
  stringRemoveAll(top, pattern);
  this->top = top;
}

void setTitle(string title) {
  setTop(stringFormat("( %s )", title.c_str()));
}

void setBottom(string bottom) {
  stringRemoveAll(bottom, pattern);
  this->bottom = bottom;
}

void setLeft(vector<string> left) {
  if ((int)left.size() <= this->getHeight() - 2) this->left = left;
}

void setLeft(string left) {
  setLeft(stringSplit(left, pattern));
}

void setRight(vector<string> right) {
  if ((int)right.size() <= this->getHeight() - 2) this->right = right;
}

void setRight(string right) {
  setRight(stringSplit(right, pattern));
}

void setValue(vector<string> value) {
  if ((int)value.size() <= this->getHeight() - 2) this->value = value;
}

void setValue(string value) {
  setValue(stringSplit(value, pattern));
}

void printExtra() {
  int x = getX(), y = getY();
  int width = getWidth(), height = getHeight();

  // Top

  if ((int)top.length() < width) {
    vts_xy(x + (width - top.length()) / 2, y);
    cout << top;
  }

  // Bottom

  if ((int)bottom.length() < width) {
    vts_xy(x + (width - bottom.length()) / 2, y + height - 1);
    cout << bottom;
  }

  // Left

  unsigned long int maxLeftLength = 0;

  if ((int)left.size() == 1) {
    maxLeftLength = left.at(0).length();

    vts_xy(x - (left.at(0).length() / 2), y + height / 2);
    cout << left.at(0);
  } else {
    for (int i = 0; i < (int)left.size(); ++i) {
      if (left.at(i).length() > maxLeftLength) maxLeftLength = left.at(i).length();

      vts_xy(x - (left.at(i).length()) / 2, y + i + 1);
      cout << left.at(i);
    }
  }

  // Right

  unsigned long int maxRightLength = 0;

  if ((int)right.size() == 1) {
    maxRightLength = right.at(0).length();

    vts_xy(x - (right.at(0).length() / 2), y + height / 2);
    cout << right.at(0);
  } else {
    for (int i = 0; i < (int)right.size(); ++i) {
      if (right.at(i).length() > maxRightLength) maxRightLength = right.at(i).length();

      vts_xy(x - (right.at(i).length()) / 2, y + i + 1);
      cout << right.at(i);
    }
  }

  // Value

  for (int i = 0; i < (int)value.size(); ++i) {
    //if (value.at(i).length() < width - (maxLeftLength + maxRightLength) / 2) {
      vts_xy(x + (maxLeftLength / 2) + 2, y + 1 + i);
      cout << value.at(i);
    //}
  }
}
};

string TextBox::pattern = "\n";

#endif // ifndef TUI_TEXT_BOX
