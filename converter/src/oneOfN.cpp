//
//  oneOfN.cpp
//  TIPSIT
//
//  Created by Gurankio on 31/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "oneOfN.hpp"

#include <algorithm>
#include <iostream>

// TODO: negativi
std::string converter::OneOfN::to(const std::string& code) {
    // 00010 = 2
    int64_t t = code.length() - code.find('1');
    return t == code.length() + 1 ? "0" : std::to_string(t);
}

std::string converter::OneOfN::from(const std::string& base10) {
    double number = stod(base10);
    
    // Dividing in integer and decimal part
    int64_t integerPart = std::abs((int64_t)number);
    while (integerPart > this->length) this->length *= 2;
   
    std::string code = "";
    for (int64_t i = 0; i < this->length; i++) code.push_back('0');
    
    code[this->length - integerPart] = '1';
    
    return code;
}

converter::OneOfN::OneOfN () {
    // NO-OP
}

converter::Code* converter::OneOfN::setOptions(const std::map<std::string, std::string>& options) {
    Code::setOptions(options);
    
    for (auto it = options.begin(); it != options.end(); it++) {
        if (it->first == "length") {
            this->length = stoll(it->second);
            continue;
        }
    }
    
    return this;
}
