#ifndef HANDLER
#define HANDLER

#include <vector>

// Base
#include "codes/base.cpp"
// List of converters
#include "codes/aiken.cpp"
#include "codes/bcd.cpp"
#include "codes/biquinary.cpp"
#include "codes/numeric.cpp"
#include "codes/quinary.cpp"
#include "codes/twoOnFive.cpp"


using namespace std;
using converterMap = map<string, function<Converter *()> >;

class ConverterHandler {
private:
vector<string> keys;
converterMap converters;

ConverterHandler() {
  registerConverter<Aiken>("Aiken");
  registerConverter<BCD>("BCD");
  registerConverter<Biquinary>("Biquinary");
  registerConverter<Numeric>("Numeric");
  registerConverter<Quinary>("Quinary");
  registerConverter<TwoOnFive>("2/5");
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
