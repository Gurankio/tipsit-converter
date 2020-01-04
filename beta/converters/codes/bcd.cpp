#include <iostream>
#include <string>
#include <math.h>

#include "base.cpp"
#include "../../utility/weightedUtility.cpp"

using namespace std;

class BCD : public Converter {
private:
string bcd(char figure) {
  int weight[] = { 8, 4, 2, 1 };
  int digit = figure - '0';
  string res = "0000";

  for (int i = 0; i < 4; ++i) {
    if (digit >= weight[i]) {
      res[i] = '1';
      digit -= weight[i];
    } else res[i] = '0';
  }

  return res;
}

public:
BCD() {
};

string check(string s, tuiData data) {
  cout << "Check.";
  return "TODO!";
}

string from(string s, tuiData data) {
  string res = "";
  vector<int> weights = { 8, 4, 2, 1 };
  int bit = 4;

  string val = "";

  for (int i = 0; i < (int)s.length(); i++) {
    if (s[i] == '.') res += '.';
    else if (s[i] != ' ') {
      val = s.substr(i, bit);
      res += to_string(bit2int(val, weights, bit));
      i += (bit - 1);
    }
  }

  return res;
}

string to(string s, tuiData data) {
  bool spaces = true;
  string res = "";

  for (int i = 0; i < (int)s.length(); ++i) {
    if (s[i] != '.') res += bcd(s[i]);
    else res += ".";

    // adding spaces
    if (spaces && s[i + 1] != '.' && s[i + 1] != '\0' && s[i] != '.') res += " ";
  }

  return res;
}
};
