#ifndef CONVERTER
#define CONVERTER

#include <functional>
#include <iostream>
#include <string>
#include <map>

using namespace std;
using guiData = map < int, string >;

class Converter {
public:
Converter() {
};

virtual string check(string, guiData) {
  return "-";
};

virtual string from(string, guiData) {
  return "-";
};

virtual string to(string, guiData) {
  return "-";
};

virtual guiData getGui() {
  guiData data;

  return data;
}
};

#endif // ifndef CONVERTER
