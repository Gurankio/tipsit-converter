#include <iostream>
#include <string>
#include <map>

using namespace std;

class Converter {

public:
  virtual string from(string);
  virtual string to(string);

protected:
  // void registerConverter(string, Converter*);
  virtual map<int, string> getGui();
};

// map<string, Converter*> converterMap;
