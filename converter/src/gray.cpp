//
//  gray.cpp
//  TIPSIT
//
//  Created by Gurankio on 22/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "gray.hpp"

#include <cmath>

std::string converter::Gray::to(const std::string& code) {
    std::string codePositive = code;
    size_t negative = codePositive.find('-');
    if (negative != std::string::npos) codePositive.erase(negative, 1);

    int64_t sum = 0;
    for (size_t i = 0; i < codePositive.length(); i++) {
        sum += (codePositive[i] - 48) * std::pow(2, codePositive.length() - i - 1);
    }

     uint64_t mask = sum >> 1;
     while (mask != 0) {
        sum = sum ^ mask;
        mask = mask >> 1;
     }

    std::string base10 = std::to_string(sum * ((negative != std::string::npos) ? -1 : 1));
    base10.erase(base10.find_last_not_of('0') + 1, std::string::npos);
    base10.erase(base10.find_last_not_of('.') + 1, std::string::npos);
    return base10;
}

std::string converter::Gray::from(const std::string& base10) {
    double number = stod(base10);
    int64_t integerPart = std::abs((int64_t)number);

    int64_t length = 4, gray = integerPart ^ (integerPart >> 1);
    while (std::ceil(std::log2(gray)) > length) length *= 2;

    std::string code;
    for (int64_t i = 0; i < length; i++) code.push_back('0');

    for (int64_t i = length - 1; i >= 0; i--) {
        if (gray >= std::pow(2, i)) {
            code[length - 1 - i] = '1';
            gray -= std::pow(2, i);
        }
    }

    if (number < 0) code.insert(code.begin(), '-');
    return code;
}

converter::Gray::Gray () {
    // NO-OP
}

converter::Code* converter::Gray::setOptions(const std::map<std::string, std::string>& options) {
    Code::setOptions(options);
    return this;
}
