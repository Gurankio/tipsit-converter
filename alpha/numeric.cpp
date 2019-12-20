#include <iostream>
#include <string>
#include <math.h>

#include "converter.cpp"
#include "utility.cpp"

using namespace std;

class Numeric : public Converter {
public:
Numeric() {
};

string check(string s, guiData data) {
  cout << "Check.";
  return "TODO!";
}

string from(string s, guiData data) {
  int base = stoi(data.at(1));
  int precision = stoi(data.at(2));
  double num = stod(s);
  string res = "";
  const string alphabet = "0123456789ABCDEFGHILMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@_";

  // dividing in integer and decimal part
  int dec = (int)num;
  double dec1 = num - dec;

  // converting the integer part
  while (dec > 0) {
    res.push_back(alphabet[dec % base]);
    dec /= base;
  }
  res = reverse(res);

  if (dec1 != 0 && precision != 0) {
    // add a dot
    res.push_back('.');

    // converting the decimal part
    for (int i = 0; i < precision; ++i) {
      dec1 *= base;
      res.push_back(alphabet[(int)dec1]);
      dec1 -= (int)dec1;
    }
  }

  return res;
}

string to(string s, guiData data) {
  int base = stoi(data.at(1));
  string res;
  double sum = 0;
  int dot = s.length();
  long unsigned int i, j;

  // first: find the dot
  for (i = 0; i < s.length(); ++i)
    if (s[i] == '.') dot = i;

  // second: converting integer part
  for (i = 0; i < dot; ++i)
    sum += getValue(s[i]) * pow(base, dot - i - 1);

  res = to_string((int)sum);

  // third: converting decimal part
  if (dot != s.length()) {
    for (j = -1, i = dot + 1; i < s.length(); ++i, --j)
      sum += getValue(s[i]) * pow(base, j);

    res = to_string(sum);
  }

  return res;
}

guiData getGui() {
  guiData data;

  // Additional data.
  data.emplace(1, "Base: ");
  data.emplace(2, "Precision: ");
  return data;
}
};
