/* 
//  Number Base Converter Library
//  v 1.0
//  Sushi Squad, 2019
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// prototypes
string toBase(string, int, int);
string fromBase(string, int);
string toRoman(string);

int getValue(char);
string reverse(string);
string addNchar(string, char, int);


/*
//  toBase(number, base, (precision)):
//  Given a string rappresenting a double and 
//  an (optional) int precision
//  convert to given base
//  
//  type:
//  string (base 10) --> string (base N)
*/
string toBase(string n, int base, int precision = 8)
{
    double num = stod(n);
    string res = "";
    const string alphabet = "0123456789ABCDEFGHILMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@_";
    
    // dividing in integer and decimal part
    int dec = (int)num;
    double dec1 = num - dec;

    // converting the integer part
    while(dec > 0)
    {
        res.push_back(alphabet[dec%base]);
        dec/=base;
    }
    res = reverse(res);
    
    if(dec1 != 0 || precision == 0)
    {
        // add a dot
        res.push_back('.');
        
        // converting the decimal part
        for(int i = 0; i < precision; ++i)
        {
            dec1 *= base;
            res.push_back(alphabet[(int)dec1]);
            dec1 -= (int)dec1;
        }
    }

    return res;
}

/*
//  fromBase(number, N):
//  Given a string code and base N
//  convert to a string rappresenting
//  a number in base 10
//  
//  type:
//  string (base N) --> string (base 10)
*/
string fromBase(string in, int base)
{
    string res;
    double sum = 0;
    int dot = in.length();
    int i, j;

    // first: find the dot
    for(i = 0; i < in.length(); ++i)
        if(in[i] == '.')
            dot = i;

    // second: converting integer part
    for(i = 0; i < dot; ++i)
        sum += getValue(in[i])*pow(base, dot-i-1);

    res = to_string((int)sum);

    // third: converting decimal part
    if(dot != in.length())
    {
        for(j = -1, i = dot+1; i < in.length(); ++i, --j)
            sum += getValue(in[i])*pow(base, j);
        res = to_string(sum);
    }

    return res;
}


/*
//  toRoman(number):
//  Given a string decimal convert to Roman
//  
//  !up to 3999!
//  type:
//  string (base 10) --> string (Roman)
*/
string toRoman(string num)
{
    int n = stoi(num);
    string res = "";
    string symbols = "IVXLCDM";
    int cifra = 0; 

    for(int i = 0; n != 0; i+=2, n/=10)
    {
        cifra = n%10;

        if(cifra < 4) {
            res = addNchar(res, symbols[i], cifra);
        } else if (cifra == 4) {
            res.push_back(symbols[i+1]);
            res.push_back(symbols[i]);
        } else if (cifra < 9) {
            res = addNchar(res, symbols[i], cifra-5);
            res.push_back(symbols[i+1]);
        } else {
            res.push_back(symbols[i+2]);
            res.push_back(symbols[i]);
        }
        
    }
    return reverse(res);
}

// return index of a character in the alphabet
int getValue(char c)
{
    const string alphabet = "0123456789ABCDEFGHILMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@_";
    for(int i = 0; i < alphabet.length(); ++i)
        if(alphabet[i] == c)
            return i;
}

// reverse a string
string reverse(string in){
    string res;
    // minus 1 because last char in string is "\0"
    for(int i = in.length()-1; i >= 0; --i)
    	res.push_back(in[i]);
    return res;   
}

// add N char to a given string
string addNchar(string s, char c, int n)
{
    for(; n > 0; n--)
        s.push_back(c);
    return s;
}
