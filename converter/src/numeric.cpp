//
//  numeric.cpp
//  TIPSIT
//
//  Created by Gurankio on 14/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "numeric.hpp"

#include <cmath>

// TODO: check alphabet bounds (ie: base 16 => max 16 chars), if base is less then 34 make all uppercase.
std::string converter::Numeric::to(const std::string& code) {
    double sum = 0;

    std::string codePositive = code;
    size_t negative = codePositive.find('-');
    if (negative != std::string::npos) codePositive.erase(negative, 1);
    
    size_t dot = codePositive.length();
    for (size_t i = 0; i < codePositive.length(); i++)
        if (codePositive[i] == this->decimalSeparator) dot = i;
    
    size_t value;
    for (size_t i = 0; i < codePositive.length(); i++) {
        if ((value = this->alphabet.find(codePositive[i])) != std::string::npos) sum += value * std::pow(this->base, (signed)(dot - i - (i <= dot)));
    }
    
    std::string base10 = std::to_string(sum * ((negative != std::string::npos) ? -1 : 1));
    base10.erase(base10.find_last_not_of('0') + 1, std::string::npos);
    base10.erase(base10.find_last_not_of('.') + 1, std::string::npos);
    return base10;
}

// Code specific implementation
// TODO: Might lose decimal precision even in base10 to base10, half bug?
std::string converter::Numeric::from(const std::string& base10) {
    double number = stod(base10);
    std::string code = "";
    
    // Dividing in integer and decimal part
    int64_t integerPart = (int64_t)number;
    double_t decimalPart = std::abs(number - integerPart);
    integerPart = std::abs(integerPart);

    // Converting the integer part
    if (integerPart == 0) code.push_back(this->alphabet[0]);
    else while (integerPart > 0) {
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
    
    if (number < 0) code.insert(code.begin(), '-');
    return code;
}

converter::Numeric::Numeric () {
    // NO-OP
}

converter::Code* converter::Numeric::setOptions(const std::map<std::string, std::string>& options) {
    Code::setOptions(options);
    
    for (auto it = options.begin(); it != options.end(); it++) {
        if (it->first == "base") {
            this->base = stoll(it->second);
            continue;
        }
        
        if (it->first == "precision") {
            this->precision = stoll(it->second);
            continue;
        }
    }
    
    return this;
}
