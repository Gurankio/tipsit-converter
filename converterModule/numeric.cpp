//
//  numeric.cpp
//  TIPSIT
//
//  Created by Gurankio on 14/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "numeric.hpp"

#include <algorithm>
#include <sstream>
#include <cmath>

std::string converter::Numeric::to(const std::string& code) {
    size_t dot = code.length();
    double_t sum = 0;
    
    // first: find the dot
    for (size_t i = 0; i < code.length(); ++i)
        if (code[i] == this->decimalSeparator) dot = i;
    
    // second: converting integer part
    size_t value;
    for (size_t i = 0; i < code.length(); ++i) {
        if ((value = this->alphabet.find(code[i])) != std::string::npos) sum += value * std::pow(this->base, (signed)(dot - i - (i <= dot)));
    }
    
    std::string base10 = std::to_string(sum);
    base10.erase(base10.find_last_not_of('0') + 1, std::string::npos);
    base10.erase(base10.find_last_not_of('.') + 1, std::string::npos);
    return base10;
}

// Code specific implementation
std::string converter::Numeric::from(const std::string& base10) {
    double_t number = stod(base10);
    std::string code = "";
    
    // Dividing in integer and decimal part
    int64_t integerPart = (int64_t)number;
    double_t decimalPart = number - integerPart;
    
    // Converting the integer part
    while (integerPart > 0) {
        code.push_back(this->alphabet[integerPart % this->base]);
        integerPart /= this->base;
    }
    
    reverse(code.begin(), code.end());
    
    if (decimalPart != 0 && this->precision != 0) {
        // Add a dot
        code.push_back(this->decimalSeparator);
        
        // Converting the decimal part
        for (size_t i = 0; i < this->precision; ++i) {
            decimalPart *= this->base;
            code.push_back(this->alphabet[(int64_t)decimalPart]);
            decimalPart -= (int64_t)decimalPart;
        }
    }
    
    return code;
}

converter::Numeric::Numeric () {
    // NO-OP
}

converter::Code* converter::Numeric::setOptions(const std::map<std::string, std::string>& options) {
    Code::setOptions(options);
    
    for (auto it = options.begin(); it != options.end(); it++) {
        if (it->first == "base") {
            this->base = stoi(it->second);
            continue;
        }
        
        if (it->first == "precision") {
            this->precision = stoi(it->second);
            continue;
        }
    }
    
    return this;
}
