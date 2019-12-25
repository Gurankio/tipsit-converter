/* 
//  Weighted Codes Converter Library
//  v 1.0
//  Sushi Squad, 2019
*/

#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;

// prototipi
string toWBase(string, string, bool);

string aiken(char);
string bcd(char);
string quinary(char);
string biquinary(char);
string twoOutOfFive(char);

// the main function
//
// toWBase(value, encoding, (spaces))
//
// Description:
// given a value (string), the encoding (string) and (optional) option spaces (bool), 
// it returns che converted value (string)
//
// string, string, bool -->  string
// ex. toWBase("10.23", "Aiken", false); // default true
// encodings names:
// "Aiken", "BCD", "Quinario", "Biquinario", "2su5"

string toWBase(string value, string encoding, bool spaces = true)
{
    string res = "";
    for(int i = 0; i < value.length(); ++i)
    {
        if(value[i] != '.')
        {
            if(encoding == "Aiken")
                res += aiken(value[i]);
            else if(encoding == "BCD")
                res += bcd(value[i]);
            else if(encoding == "Quinario")
                res += quinary(value[i]);
            else if(encoding == "Biquinario")
                res += biquinary(value[i]);
            else if(encoding == "2su5")
                res += twoOutOfFive(value[i]);
        }
        else
            res += ".";
        
        // adding spaces
        if(value[i+1] != '.' && value[i+1] != '\0' && value[i] != '.' && spaces)
            res += " ";
    }
    return res;
}


/*
// The following functions convert a 
// digit (char type) to their codes 
//  
// type:
// char (encoding 10) --> string (code)
*/

string aiken(char figure)
{
    int weight[] = {2,4,2,1};
    int digit = figure - '0';
    int i = 1;
    string res = "0000";

    if(digit >= 5)
    {
        res[0] = '1';
        digit -= weight[0];
    } else res[0] = '0';

    for(i = 1; i < 4; ++i)
    {
        if(digit >= weight[i])
        {
            res[i] = '1';
            digit -= weight[i];
        } else res[i] = '0';
    } 
    return res;
}

string bcd(char figure)
{
    int weight[] = {8,4,2,1};
    int digit = figure - '0';
    string res = "0000";

    for(int i = 0; i < 4; ++i)
    {
        if(digit >= weight[i])
        {
            res[i] = '1';
            digit -= weight[i];
        } else res[i] = '0';
    } 
    return res;
}

string quinary(char figure)
{
    int weight[] = {5,4,2,1};
    int digit = figure - '0';
    string res = "0000";

    for(int i = 0; i < 4; ++i)
    {
        if(digit >= weight[i])
        {
            res[i] = '1';
            digit -= weight[i];
        } else res[i] = '0';
    } 
    return res;
}

string biquinary(char figure)
{
    int digit = figure - '0';
    string res = "00 00000";

    if(digit >= 5) {
        res[0] = '1';
        res[1] = '0';
        digit -= 5;
    } else {
        res[0] = '0';
        res[1] = '1';
    }

    res[7-digit] = '1';

    return res;
}

string twoOutOfFive(char figure)
{
    int weight[] = {6,3,2,1,0};
    int digit = figure - '0';
    string res = "00000";
    int cont = 0;

    if(digit == 0)
        return "00110";
    else
    {
        for(int i = 0; i < 5, cont < 2; ++i)
        {
            if(digit >= weight[i])
            {
                res[i] = '1';
                digit -= weight[i];
                cont++;
            } else res[i] = '0';
        }
    }
    return res;
}