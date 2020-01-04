/*
 * String Formatting
 * https://stackoverflow.com/a/49812018
 */

#ifndef STRING_FORMAT
#define STRING_FORMAT

#include <string>
#include <cstdarg>
#include <vector>

using namespace std;

const string stringFormat(const char *const zcFormat, ...) {
  // initialize use of the variable argument array
  va_list vaArgs;

  va_start(vaArgs, zcFormat);

  // reliably acquire the size
  // from a copy of the variable argument array
  // and a functionally reliable call to mock the formatting
  va_list vaArgsCopy;
  va_copy(vaArgsCopy, vaArgs);
  const int iLen = vsnprintf(NULL, 0, zcFormat, vaArgsCopy);
  va_end(vaArgsCopy);

  // return a formatted string without risking memory mismanagement
  // and without assuming any compiler or platform specific behavior
  vector<char> zc(iLen + 1);
  vsnprintf(zc.data(), zc.size(), zcFormat, vaArgs);
  va_end(vaArgs);
  return string(zc.data(), iLen);
}

#endif // ifndef STRING_FORMAT
