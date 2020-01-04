#ifndef CONVERTER
#define CONVERTER

#include <functional>
#include <iostream>
#include <string>
#include <map>

using namespace std;
using tuiData = map < int, string >;

class Converter {
public:
Converter() {
};

virtual string check(string, tuiData) {
  return "-";
};

virtual string from(string, tuiData) {
  return "-";
};

virtual string to(string, tuiData) {
  return "-";
};

virtual tuiData getTui() {
  tuiData data;

  return data;
}
};

#endif // ifndef CONVERTER
