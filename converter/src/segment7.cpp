//
//  segment7.cpp
//  TIPSIT
//
//  Created by Gurankio on 31/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "segment7.hpp"

#include <algorithm>
#include <cmath>

std::string converter::Segment7::to(const std::string& code) {
    std::string codePositive = code;
    size_t negative = codePositive.find('-');
    if (negative != std::string::npos) codePositive.erase(negative, 1);
    
    negative = codePositive.find(this->minus);
    if (negative != std::string::npos) codePositive.erase(negative, 8);
    
    std::string input = codePositive;
    std::vector<std::string> split;
    size_t pos;
    while ((pos = input.find(this->numberSeparator)) != std::string::npos) {
        split.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    split.push_back(input.substr(0, pos));
    
    int64_t sum = 0;
    for (size_t i = 0; i < split.size(); i++) {
        sum += std::distance(this->base16.begin(), std::find(this->base16.begin(), this->base16.end(), split[i])) * std::pow(16, split.size() - i - 1);
    }
    
    std::string base10 = std::to_string(sum * ((negative != std::string::npos) ? -1 : 1));
    return base10;
}

std::string converter::Segment7::from(const std::string& base10) {
    double number = stod(base10);
    std::string code = "";
    
    // Dividing in integer and decimal part
    int64_t integerPart = std::abs((int64_t)number);
    
    if (integerPart == 0) code.append(this->base16[0]);
    else while (integerPart > 0) {
        code.insert(0, this->numberSeparator + this->base16[integerPart % 16]);
        integerPart /= 16;
    }
    code.erase(code.begin(), code.begin() + 1);

    if (number < 0) code.insert(0, this->minus + this->numberSeparator);
    return code;
}

converter::Segment7::Segment7 () {
    this->base16 = {
        "1111110",
        "0110000",
        "1101101",
        "1111001",
        "0110011",
        "1011011",
        "1011111",
        "1110000",
        "1111111",
        "1111011",
        "1110111",
        "0011111",
        "1001110",
        "0111101",
        "1001111",
        "1000111"
    };
    this->minus = "0000001";
}

converter::Code* converter::Segment7::setOptions(const std::map<std::string, std::string>& options) {
    Code::setOptions(options);
    
    for (auto it = options.begin(); it != options.end(); it++) {
        if (it->first == "numberSeparator") {
            this->numberSeparator = it->second.at(0);
            continue;
        }
    }
    
    return this;
}
