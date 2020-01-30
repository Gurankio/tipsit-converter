#include <iostream>
#include <string>
#include <math.h>

#include "base.cpp"
#include "../../utility/alphanumericUtility.cpp"

using namespace std;

class ASCII : public Converter {
public:
ASCII() {
};

string check(string in, tuiData data) {
  cout << "Check.";
  return "TODO!";
}

string from(string in, tuiData data) {
  string res = "", temp = "";

  for (int i = 0; i < in.length(); i++) {
    if (in[i] != ' ') temp.push_back(in[i]);

    if (in[i] == ' ' || i == in.length() - 1) {
      temp = toBase1(temp, "2", "0");

      while (temp.length() != 7) temp = '0' + temp;
      res += temp;
      temp = "";

      if (in[i] == ' ') res += " ";
    }
  }

  return res;
}

string to(string in, tuiData data) {
  int len = in.length(), boole = 0;
  string temp = "", res = "";

  for (int i = 0; i < in.length(); i++) {
    if (in[i] != ' ') temp.push_back(in[i]);

    if (in[i] == ' ' || i == in.length() - 1) {
      res += fromBase1(remove0(temp), "2");

      if (in[i] == ' ') res += " ";

      boole = 0;
      temp = "";
    }
  }

  return res;
}
};
