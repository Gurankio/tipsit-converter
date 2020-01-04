#ifndef NUMERIC_UTILITY
#define NUMERIC_UTILITY

#include <string>

using namespace std;

// return index of a character in the alphabet
int getValue(char c) {
  const string alphabet = "0123456789ABCDEFGHILMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@_?!";

  for (long unsigned int i = 0; i < alphabet.length(); ++i)
    if (alphabet[i] == c) return i;
}

// reverse a string
string reverse(string in) {
  string res;

  // minus 1 because last char in string is "\0"
  for (int i = in.length() - 1; i >= 0; --i)
    res.push_back(in[i]);

  return res;
}

// add N char to a given string
string addNchar(string s, char c, int n) {
  for (; n > 0; n--)
    s.push_back(c);

  return s;
}

#endif // ifndef NUMERIC_UTILITY
