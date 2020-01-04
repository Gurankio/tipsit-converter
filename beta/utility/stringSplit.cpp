/*
 * String splitting
 * https://stackoverflow.com/questions/14265581
 */

#ifndef STRING_SPLIT
#define STRING_SPLIT

#include <string>
#include <vector>

using namespace std;

vector<string> stringSplit(const string& str, const string& delim) {
  vector<string> tokens;
  size_t prev = 0, pos = 0;

  do {
    pos = str.find(delim, prev);

    if (pos == string::npos) pos = str.length();

    string token = str.substr(prev, pos - prev);

    if (!token.empty()) tokens.push_back(token);

    prev = pos + delim.length();
  } while (pos < str.length() && prev < str.length());
  return tokens;
}

#endif // ifndef STRING_SPLIT
