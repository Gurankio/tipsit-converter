#include <locale.h>

// Converters
#include "converters/handler.cpp"

// Tui
#include "tui/tui.cpp"
#include "tui/boxes/textBox.cpp"
#include "tui/boxes/inputBox.cpp"
#include "tui/boxes/listBox.cpp"
#include "tui/boxes/buttonBox.cpp"

using namespace std;

void tuiStart();
void convertAction();
void inputAddFields(char);
void outputAddFields(char);

int main() {
  setlocale(LC_ALL, "");
  vts_activateCommands();
  // auto tuiThread = async(tuiStart);
  tuiStart();
}

Tui *tui;

char nextInteraction = 0x31;

InputBox *inputData;
ListBox *inputMod;
map<int, InputBox *> inputExtraData;

TextBox *outputData;
ListBox *outputMod;
map<int, InputBox *> outputExtraData;

void tuiStart() {
  vector<string> keys = ConverterHandler::getInstance().getKeys();

  tui = new Tui(100, 40, "Converter 3000");

  inputData = new InputBox(5, 2, 30, nextInteraction++);
  inputData->setTitle("Input Data");
  tui->registerBox(inputData);
  tui->registerInteraction(inputData);

  inputMod = new ListBox(5, 6, 30, nextInteraction++, keys);
  inputMod->setTitle("Input Mod");
  inputMod->setPickEvent(inputAddFields);
  tui->registerBox(inputMod);
  tui->registerInteraction(inputMod);

  outputData = new TextBox(66, 2, 30, 3);
  outputData->setTitle("Output Data");
  tui->registerBox(outputData);

  outputMod = new ListBox(66, 6, 30, nextInteraction++, keys);
  outputMod->setTitle("Output Mod");
  outputMod->setPickEvent(outputAddFields);
  tui->registerBox(outputMod);
  tui->registerInteraction(outputMod);

  ButtonBox *button = new ButtonBox(45, 2, 15, nextInteraction++, convertAction);
  button->setValue("Convert");
  tui->registerBox(button);
  tui->registerInteraction(button);

  /*
     vector<string> v;
     v.push_back("Test 1");
     v.push_back("Test 2");
     PickerBox *settings = new PickerBox(45, 10, 15, 4, '-', v);
     settings->setTitle("Settings");
     settings->setMultiple(true);
     tui->registerBox(settings);
     tui->registerInteraction(settings);
   */

  tui->loop();
}

void convertAction() {
  string cInKey = inputMod->getValue();

  if (cInKey == "Empty") return;

  auto cIn = ConverterHandler::getInstance().getConverter(cInKey);
  tuiData dataIn;

  for (auto i = inputExtraData.begin(); i != inputExtraData.end(); ++i)
    dataIn.emplace(i->first, i->second->getValue());

  string internal = cIn->to(inputData->getValue(), dataIn);

  string cOutKey = outputMod->getValue();

  if (cOutKey == "Empty") return;

  auto cOut = ConverterHandler::getInstance().getConverter(cOutKey);
  tuiData dataOut;

  for (auto i = outputExtraData.begin(); i != outputExtraData.end(); ++i)
    dataOut.emplace(i->first, i->second->getValue());

  string result = cOut->from(internal, dataOut);

  outputData->setValue(result);
}

void inputAddFields(char index) {
  for (auto i = inputExtraData.begin(); i != inputExtraData.end(); ++i) {
    tui->deleteBox(i->second);
    tui->deleteInteraction(i->second);
    nextInteraction--;
  }

  inputExtraData.clear();

  vector<string> keys = ConverterHandler::getInstance().getKeys();
  string key = keys.at(index - LIST_BOX_START);

  tuiData data = ConverterHandler::getInstance().getConverter(key)->getTui();

  for (auto i = data.begin(); i != data.end(); ++i) {
    vector<string> subData = stringSplit(i->second, "-");
    int pos = inputExtraData.size();

    InputBox *extra = new InputBox(5, 10 + (4 * pos), 30, nextInteraction++);
    extra->setTitle(subData.at(0));
    extra->setValue(subData.at(1));

    tui->registerBox(extra);
    tui->registerInteraction(extra);

    inputExtraData.emplace(i->first, extra);
  }
}

void outputAddFields(char index) {
  for (auto i = outputExtraData.begin(); i != outputExtraData.end(); ++i) {
    tui->deleteBox(i->second);
    tui->deleteInteraction(i->second);
    nextInteraction--;
  }

  outputExtraData.clear();

  vector<string> keys = ConverterHandler::getInstance().getKeys();
  string key = keys.at(index - LIST_BOX_START);

  tuiData data = ConverterHandler::getInstance().getConverter(key)->getTui();

  for (auto i = data.begin(); i != data.end(); ++i) {
    vector<string> subData = stringSplit(i->second, "-");
    int pos = outputExtraData.size();

    InputBox *extra = new InputBox(66, 10 + (4 * pos), 30, nextInteraction++);
    extra->setTitle(subData.at(0));
    extra->setValue(subData.at(1));

    tui->registerBox(extra);
    tui->registerInteraction(extra);

    outputExtraData.emplace(i->first, extra);
  }
}
