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
string toBase(double, int, int);
double fromBase(string, int);
int getValue(char);
string reverse(string);

/*
    toBase(number, base, precision):
    Given a double number and precision(optional)
    convert to given base
    
    type:
    double (base 10) --> string (base n)
*/
string toBase(double num, int base, int precision = 8)
{
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
    
    // add a dot
    res.push_back('.');
    
    // converting the decimal part
    for(int i = 0; i < precision; ++i)
    {
    	dec1 *= base;
    	res.push_back(alphabet[(int)dec1]);
    	dec1 -= (int)dec1;
	}
    
    return res;
}

/*
    fromBase(number, N):
    Given a string code and base N
    convert to base 10
    
    type:
    string (base N) --> double (base 10)
*/
double fromBase(string in, int base)
{
    double res = 0;
    int dot = 0;
    int i, j;

    // first: find the dot
    while(in[dot] != '.')
        ++dot;
    
    // second: converting integer part
    for(i = 0; i < dot; ++i)
        res += getValue(in[i])*pow(base, dot-i-1);

    // third: converting decimal part
    for(j = -1, i = dot+1; i < in.length(); ++i, --j)
        res += getValue(in[i])*pow(base, j);

    return res;
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
