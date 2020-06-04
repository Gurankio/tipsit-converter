//
//  utf8.cpp
//  TIPSIT
//
//  Created by Gurankio on 22/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "utf8.hpp"

#include <cmath>

std::string converter::Utf8::to(const std::string& code) {
    std::string codePositive = code;
    size_t negative = codePositive.find('-');
    if (negative != std::string::npos) codePositive.erase(negative, 1);
    
    std::string recoveredBinary = "";
    
    auto it = code.begin();
    while (*it == '1') it++;
    it++;
    
    while (it != code.end() && *it != this->numberSeparator) {
        recoveredBinary.push_back(*it++);
    }
    if (it != code.end()) it++;
    if (it != code.end()) it++;
    if (it != code.end()) it++;
    
    while (it != code.end()) {
        for (int64_t i = 0; i < 6; i++) recoveredBinary.push_back(*it++);
        if (it != code.end()) it++;
        if (it != code.end()) it++;
        if (it != code.end()) it++;
    }
    
    int64_t sum = 0;
    for (int64_t i = 0; i < recoveredBinary.length(); i++) {
        sum += (recoveredBinary[i] - 48) * std::pow(2, recoveredBinary.length() - i - 1);
    }

    std::string base10 = std::to_string(sum * ((negative != std::string::npos) ? -1 : 1));
    return base10;
}

std::string converter::Utf8::from(const std::string& base10) {
    int64_t number = abs(stoll(base10));
    int64_t numberBits = floor(log2(number)) + 1;
    if (numberBits > 31) numberBits = 31;
    
    std::string binaryNumber = "";
    for (int64_t i = 0; i < numberBits; i++) binaryNumber.push_back('0');
    for (int64_t i = numberBits - 1; i >= 0; i--) {
        if (number >= std::pow(2, i)) {
            binaryNumber[numberBits - i - 1] = '1';
            number -= std::pow(2, i);
        }
    }
    
    int64_t bytes = numberBits <= 7 ? 1 : ((numberBits - 7) / 6) + 2;
    std::string code = "";
    if (bytes == 1) code = "0xxxxxxx";
    else {
        for (int64_t i = 0; i < bytes; i++) code.push_back('1');
        code.push_back('0');
        for (int64_t i = 0; i < 8 - bytes - 1; i++) code.push_back('x');
        
        code.push_back(this->numberSeparator);
        
        for (int64_t i = 0; i < bytes - 1; i++) {
            code.push_back('1');
            code.push_back('0');
            for (int64_t i = 0; i < 6; i++) code.push_back('x');
            code.push_back(this->numberSeparator);
        }
        
        code.erase(code.end()-1);
    }
    
    auto it = code.rbegin();
    auto jt = binaryNumber.rbegin();
    
    while (jt != binaryNumber.rend()) {
        if (*it == 'x') *it = *jt++;
        it++;
    }
    
    for (auto kt = code.begin(); kt != code.end(); kt++) {
        if (*kt == 'x') *kt = '0';
    }
    
    return code;
}

converter::Utf8::Utf8 () {
    // NO-OP
}

converter::Code* converter::Utf8::setOptions(const std::map<std::string, std::string>& options) {
    Code::setOptions(options);
    
    for (auto it = options.begin(); it != options.end(); it++) {
        if (it->first == "numberSeparator") {
            this->numberSeparator = it->second.at(0);
            continue;
        }
    }
    
    return this;
}
