#include <iostream>
#include <string>
#include <map>

using namespace std;

class Converter {

public:
  virtual string check(string, map<int, string>);
  virtual string from(string, map<int, string>);
  virtual string to(string, map<int, string>);

protected:
  // void registerConverter(string, Converter*);
  virtual map<int, string> getGui();
};

// map<string, Converter*> converterMap;
