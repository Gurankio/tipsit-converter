//
//  ascii.cpp
//  TIPSIT
//
//  Created by Gurankio on 21/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "ascii.hpp"

#include <cmath>
#include <iostream>

std::vector<std::string> converter::Ascii::to(const std::vector<std::string>& code) {
    std::vector<std::string> split;
    for (auto it = code.begin(); it != code.end(); it++) {
        for (auto jt = it->begin(); jt != it->end(); jt++) {
            std::string t;
            t += *jt;
            split.push_back(t);
        }
    }
    return Code::to(split);
}

std::string converter::Ascii::to(const std::string& code) {
    return std::to_string((int64_t)code.c_str()[0]);
}

// Code specific implementation
std::string converter::Ascii::from(const std::string& base10) {
    std::string code = "";
    code += (char)stoll(base10);
    return code;
}

converter::Ascii::Ascii () {
    // NO-OP
}

converter::Code* converter::Ascii::setOptions(const std::map<std::string, std::string>& options) {
    Code::setOptions(options);
    return this;
}
