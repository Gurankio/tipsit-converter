
//#include "tipsit\nbcl.cpp"
//#include "tipsit\wccl.cpp"

#include <iostream>
#include <string>
#include <math.h>

#include "base.cpp"
#include "bcd.cpp"
#include "../../utility/weightedUtility.cpp"

using namespace std;

class XS3 : public Converter {
private:

public:
XS3() {
};

string check(string s, tuiData data) {
  cout << "Check.";
  return "TODO!";
}

string from(string input, tuiData data) // spaces? --> doesn't matter
{
    string res;
    string val = "";
    int bit = 4;
    
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '.') res += '.';
        else if (input[i] != ' ') {
            val = input.substr(i, bit);
            res += to_string(bit2int(val, {8,4,2,1}, bit)-3);
            i += (bit - 1);
        }
    }

    return res;
}

string to(string input, tuiData data)
{
    bool spaces = true;
    string res;
    BCD test = BCD();
    
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] != '.') {
            res += test.bcd('0' + ((input[i] - '0') + 3));
        } else res += ".";

        // adding spaces
        if (spaces && input[i + 1] != '.' && input[i + 1] != '\0' && input[i] != '.') res += " ";
    }
       
    return res;
}
};
