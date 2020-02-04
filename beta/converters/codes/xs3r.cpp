
//#include "tipsit\nbcl.cpp"
//#include "tipsit\wccl.cpp"

#include <iostream>
#include <string>
#include <math.h>

//#include "xs3.cpp"
#include "base.cpp"
#include "bcd.cpp"
#include "../../utility/weightedUtility.cpp"

using namespace std;

class XS3r : public Converter {
private:

public:
XS3r() {
};

string check(string s, tuiData data) {
  cout << "Check.";
  return "TODO!";
}

string from(string input, tuiData data) // ???
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
    BCD b = BCD();
    
    string byte, byter;

    for (int i = 0; i < input.length(); ++i) {
        //byter = "0";
        if (input[i] != '.') {
            byte = b.bcd('0' + ((input[i] - '0') + 3)); // eccesso tre
            byter = "0" + byte.substr(0, 3);
            for(int h = 0; h < 4; h++)
                if(byte[h] == byter[h])
                    res += "0";
                else
                    res += "1";
        } else res += ".";

        // adding spaces
        if (spaces && input[i + 1] != '.' && input[i + 1] != '\0' && input[i] != '.') res += " ";
    }
       
    return res;
}
};
