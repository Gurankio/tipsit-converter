/* 
//  Number Base Converter Library
//  v 1.0
//  Sushi Squad, 2019
//  nbcl.h
*/

#include <iostream>
#include <string>
#include "nbcl.cpp"
using namespace std;

// double (base 10) --> string (base n)
string toBase(string, int, int);

// string (base N) --> double (base 10)
double fromBase(string, int);

// int (base 10) --> string (roman) !up to 3999
string toRoman(int n);

// utils
int getValue(char);
string reverse(string);
string addNchar(string, char, int); 
/* adds N chars to a string
 ex. 
 string s = "";
 s = addNchar(s, 'Y', 3);
 cout << s << endl;
 // output = "YYY"
*/
