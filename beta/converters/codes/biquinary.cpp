#include <iostream>
#include <string>
#include <math.h>

#include "base.cpp"
#include "../../utility/weightedUtility.cpp"

using namespace std;

class Biquinary : public Converter {
private:
string biquinary(char figure) {
  int digit = figure - '0';
  string res = "00 00000";

  if (digit >= 5) {
    res[0] = '1';
    res[1] = '0';
    digit -= 5;
  } else {
    res[0] = '0';
    res[1] = '1';
  }

  res[7 - digit] = '1';

  return res;
}

public:
Biquinary() {
};

string check(string s, tuiData data) {
  cout << "Check.";
  return "TODO!";
}

string from(string s, tuiData data) {
  string res = "";
  vector<int> weights = { 0, 5, 0, 4, 3, 2, 1, 0 };
  int bit = 8;

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
    if (s[i] != '.') res += biquinary(s[i]);
    else res += ".";

    // adding spaces
    if (spaces && s[i + 1] != '.' && s[i + 1] != '\0' && s[i] != '.') res += " ";
  }

  return res;
}
};
