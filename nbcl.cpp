/* 
//  Number Base Converter Library
//  v 1.0
//  (c) Gionatan Buono
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;
// prototypes
string toBase(int, int);
int fromBase(string);
int findInAlphabet(char);
string reverse(string);

// int (base 10) --> string (base n)
string toBase(float num, int base, int precisione = 8)
{
    string res = "";
    const string alphabet = "0123456789ABCDEFGHILMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@_";
    
    int dec = (int)num;
    float dec1 = num-dec;
    while(dec > 0)
    {
        res.push_back(alphabet[dec%base]);
        dec/=base;
    }
    res = reverse(res);
    res.push_back('.');
    
    for(int i = 0; i < precisione; ++i)
    {
    	dec1 *= base;
    	res.push_back(alphabet[(int)dec1]);
    	dec1 -= (int)dec1;
	}
    
    return res;
}

// string (base N) --> int (base 10)
int fromBase(string in, int base)
{
    int res = 0;
    
    for(int i = 0; i < in.length(); i++)
        res += findInAlphabet(in[i])*pow(base, in.length()-i-1);

    return res;
}

// return index of a character in the alphabet
int findInAlphabet(char c)
{
    const string alphabet = "0123456789ABCDEFGHILMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@_";
    for(int i = 0; i < alphabet.length(); ++i)
        if(alphabet[i] == c)
            return i;
}

string reverse(string in){
	
	string res;
	// tolgo 1 a in.length perchè l'ultimo carattere di una stringa è '\0'
    for(int i = in.length()-1; i >= 0; --i)
    	res.push_back(in[i]);
    return res;
    
}
