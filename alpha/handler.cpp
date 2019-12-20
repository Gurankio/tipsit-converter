#ifndef HANDLER
#define HANDLER

// Base
#include "converter.cpp"
// List of converters
#include "numeric.cpp"

using namespace std;
using converterMap = map<string, function<Converter *()> >;
converterMap converters;

// Must get called once for each converter in handlerSetup();
template <typename T>
void registerConverter(string id) {
  // Sample:
  // converters.emplace("converter", []() -> Converter *{
  //   return new Converter;
  // });
  converters.emplace(id, []() -> Converter *{
    return new T;
  });
}

void handlerSetup() {
  registerConverter<Numeric>("numeric");
}

Converter * getConverter(string string) {
  auto constructor = converters[string];

  // TODO: must check before returning.
  return constructor();
}

#endif // ifndef HANDLER
