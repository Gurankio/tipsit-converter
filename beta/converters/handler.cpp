#ifndef HANDLER
#define HANDLER

#include <vector>

// Base
#include "codes/base.cpp"
// List of converters
#include "codes/numeric.cpp"

using namespace std;
using converterMap = map<string, function<Converter *()> >;

class ConverterHandler {
private:
vector<string> keys;
converterMap converters;

ConverterHandler() {
  registerConverter<Numeric>("Numeric");
}

ConverterHandler(ConverterHandler const&);
void operator=(ConverterHandler const&);

// Must get called once for each converter in handlerSetup();
template <typename T>
void registerConverter(string id) {
  keys.push_back(id);
  converters.emplace(id, []() -> Converter *{
      return new T;
    });
}

public:
static ConverterHandler& getInstance() {
  static ConverterHandler instance = ConverterHandler();

  return instance;
}

vector<string> getKeys() {
  return keys;
}

Converter * getConverter(string string) {
  auto constructor = converters[string];

  // TODO: must check before returning.
  return constructor();
}
};

#endif // ifndef HANDLER
