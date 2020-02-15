/*
 * String splitting
 * https://stackoverflow.com/a/25022977
 */

#ifndef STRING_COUNT_SPLIT
#define STRING_COUNT_SPLIT

#include <string>
#include <vector>

using namespace std;

vector<string> stringCountSplit(const string& str, int splitLength) {
  int NumSubstrings = str.length() / splitLength;
  vector<string> ret;

  for (auto i = 0; i < NumSubstrings; i++)
    ret.push_back(str.substr(i * splitLength, splitLength));

  // If there are leftover characters, create a shorter item at the end.
  if (str.length() % splitLength != 0) ret.push_back(str.substr(splitLength * NumSubstrings));

  return ret;
}

#endif // ifndef STRING_COUNT_SPLIT
