//
//  roman.cpp
//  TIPSIT
//
//  Created by Gurankio on 29/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "roman.hpp"

#include <cmath>

std::string converter::Roman::to(const std::string& code) {
#define handleRomanValue(value) \
if (value >= lastAdded) { \
sum += value; \
lastAdded = value; \
} else sum -= value;
    
    int64_t sum = 0;
    
    std::string codePositive = code;
    size_t negative = codePositive.find('-');
    if (negative != std::string::npos) codePositive.erase(negative, 1);
    
    size_t dot = codePositive.length();
    // first: find the dot
    for (size_t i = 0; i < codePositive.length(); i++)
        if (codePositive[i] == this->decimalSeparator) dot = i;
    
    int64_t lastAdded = 0;
    for (int64_t i = dot - 1; i >= 0; i--) {
        switch (codePositive[i]) {
            case 'I':
                handleRomanValue(1);
                break;
                
            case 'V':
                handleRomanValue(5);
                break;
                
            case 'X':
                handleRomanValue(10);
                break;
                
            case 'L':
                handleRomanValue(50);
                break;
                
            case 'C':
                handleRomanValue(100);
                break;
                
            case 'D':
                handleRomanValue(500);
                break;
                
            case 'M':
                handleRomanValue(1000);
                break;
                
            default:
                break;
        }
    }
        
    std::string base10 = std::to_string(sum * ((negative != std::string::npos) ? -1 : 1));
    return base10;
    
}

// Code specific implementation
std::string converter::Roman::from(const std::string& base10) {
    double number = stod(base10);
    std::string code = "";
    
    // Dividing in integer and decimal part
    int64_t integerPart = std::abs((int64_t)number);
    
    for (int64_t i = 0; i < integerPart / 1000; i++) code.push_back('M');
    integerPart %= 1000;
    
    int64_t hundreds = integerPart / 100;
    integerPart %= 100;
    
    switch (hundreds) {
        case 9:
            code.push_back('C');
            code.push_back('M');
            break;
            
        case 4: code.push_back('C');
        case 8:
        case 7:
        case 6:
        case 5:
            code.push_back('D');
            for (int64_t i = 0; i < hundreds - 5; i++) code.push_back('C');
            break;
            
        case 3: code.push_back('C');
        case 2: code.push_back('C');
        case 1: code.push_back('C');
            break;
    }
    
    int64_t tens = integerPart / 10;
    integerPart %= 10;
    
    switch (tens) {
        case 9:
            code.push_back('X');
            code.push_back('C');
            break;
            
        case 4: code.push_back('X');
        case 8:
        case 7:
        case 6:
        case 5:
            code.push_back('L');
            for (int64_t i = 0; i < tens - 5; i++) code.push_back('X');
            break;
            
        case 3: code.push_back('X');
        case 2: code.push_back('X');
        case 1: code.push_back('X');
            break;
    }
    
    int64_t units = integerPart;
    
    switch (units) {
        case 9:
            code.push_back('I');
            code.push_back('X');
            break;
            
        case 4: code.push_back('I');
        case 8:
        case 7:
        case 6:
        case 5:
            code.push_back('V');
            for (int64_t i = 0; i < units - 5; i++) code.push_back('I');
            break;
            
        case 3: code.push_back('I');
        case 2: code.push_back('I');
        case 1: code.push_back('I');
            break;
    }
    
    if (number < 0) code.insert(code.begin(), '-');
    return code;
}

converter::Roman::Roman () {
    // NO-OP
}

converter::Code* converter::Roman::setOptions(const std::map<std::string, std::string>& options) {
    Code::setOptions(options);
    return this;
}
