#include <future>

// Tui Dependencies
#include "tui/tui.cpp"
#include "tui/boxes/inputBox.cpp"
#include "tui/boxes/listBox.cpp"
#include "tui/boxes/buttonBox.cpp"

using namespace std;

void tuiStart();
void convertAction();

int main() {
  // auto tuiThread = async(tuiStart);
  tuiStart();
}

void tuiStart() {
  Tui *tui = new Tui(100, 40, (char *)"Title");

  InputBox *input = new InputBox(5, 2, 30, '1');

  input->setTitle((char *)"Input Data");

  tui->registerBox(input);
  tui->registerInteraction(input);

  vector<string> v = { "asd", "qwe", "rty" };
  ListBox *box1 = new ListBox(5, 6, 30, '2', v);

  box1->setTitle((char *)"Input Mod");

  tui->registerBox(box1);
  tui->registerInteraction(box1);

  ButtonBox *button = new ButtonBox(50, 4, 10, '3', convertAction);
  button->setValue("Convert");

  tui->registerBox(button);
  tui->registerInteraction(button);

  tui->loop();
}

void convertAction() {
  cout << "ASDRUBALE!" << flush;
  cp_sleep(1000);
}
