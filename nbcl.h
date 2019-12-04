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
string toBase(double, int, int);

// string (base N) --> double (base 10)
double fromBase(string, int);

// utils
int getValue(char);
string reverse(string);
