#include "handler.cpp"

using namespace std;

int main() {
  handlerSetup(); // Registers converters

  cout << "Inserisci il tipo in INPUT:";
  string modIn;
  cin >> modIn;

  // Controllo stupido
  if (modIn != "numeric") return 0;

  auto c = getConverter("numeric");
  guiData data = c->getGui();

  for (auto i = data.begin(); i != data.end(); ++i) {
    cout << i->second;
    string t;
    cin >> t;
    int p = i->first;
    data[p] = t;
  }

  cout << "Inserisci il numero: ";
  string dataIn;
  cin >> dataIn;

  string internal = c->to(dataIn, data);
  cout << internal << endl;

  cout << "Inserisci il tipo in OUTPUT:";
  string modOut;
  cin >> modOut;

  c = getConverter("numeric");
  data = c->getGui();

  for (auto i = data.begin(); i != data.end(); ++i) {
    cout << i->second;
    string t;
    cin >> t;
    int p = i->first;
    data[p] = t;
  }

  string result = c->from(internal, data);
  cout << result << endl;

  return 0;
}
