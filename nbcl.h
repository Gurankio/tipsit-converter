/*
//  nbcl.h
*/

#include <iostream>
#include <string>
#include "nbcl.cpp"
using namespace std;

// int (base 10) --> string (base n)
string toBase(float, int, int);
// string (base N) --> int (base 10)
int fromBase(string, int);

// utils
int findInAlphabet(char);
string reverse(string);
