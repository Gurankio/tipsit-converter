

#ifndef ALPHANUMERIC_UTILITY
#define ALPHANUMERIC_UTILITY

#include <string>
#include <math.h>

using namespace std;

string remove0 (string);
string toBase1(string, string, string);
string fromBase1(string, string);
int getValue1(char);
string reverse1(string); 

string remove0 (string in){
	int boole=1;
	while (boole){
		if (in[0]=='0'){
			in.erase(0,1);
		}
		else boole=0;
	}
	return in;
}

string toBase1(string n, string base_str, string precision_str) {
  int base = stoi(base_str);
  int precision = stoi(precision_str);
  double num = stod(n);
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
  res = reverse1(res);

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

string fromBase1(string in, string base_str) {
  int base = stoi(base_str);
  string res;
  double sum = 0;
  int dot = in.length();
  int i, j;

  // first: find the dot
  for (i = 0; i < in.length(); ++i)
    if (in[i] == '.') dot = i;

  // second: converting integer part
  for (i = 0; i < dot; ++i)
    sum += getValue1(in[i]) * pow(base, dot - i - 1);

  res = to_string((int)sum);

  // third: converting decimal part
  if (dot != in.length()) {
    for (j = -1, i = dot + 1; i < in.length(); ++i, --j)
      sum += getValue1(in[i]) * pow(base, j);

    res = to_string(sum);
  }

  return res;
}

int getValue1(char c) {
  const string alphabet = "0123456789ABCDEFGHILMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@_?!";

  for (int i = 0; i < alphabet.length(); ++i)
    if (alphabet[i] == c) return i;
  return -1;
}

string reverse1(string in) {
  string res;

  // minus 1 because last char in string is "\0"
  for (int i = in.length() - 1; i >= 0; --i)
    res.push_back(in[i]);

  return res;
}

#endif // ifndef ALPHANUMERIC_UTILITY


