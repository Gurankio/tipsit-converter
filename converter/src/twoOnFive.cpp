//
//  twoOnFive.cpp
//  TIPSIT
//
//  Created by Gurankio on 17/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "twoOnFive.hpp"

std::string converter::TwoOnFive::to(const std::string& code) {
    std::string base10 = "";
    
    for (size_t i = 0; i < code.length(); i++) {
        if (code[i] == '-') {
            base10 += '-';
            continue;
        }
        
        if (code[i] == this->decimalSeparator) {
            base10 += '.';
            continue;
        }
        
        if (code[i] != this->numberSeparator) {
            std::string number = code.substr(i, this->weight.size());
            
            int64_t sum = 0;
            for (size_t j = 0; j < this->weight.size(); j++)
                sum += (number[j] - '0') * this->weight.at(j);
            
            if (number == "00110") sum = 0;
            base10 += std::to_string(sum);
            
            i += (this->weight.size() - 1); // nBits - 1
        }
    }
    
    return base10;
}

std::string converter::TwoOnFive::from(int64_t base10) {
    std::string code = "00000";
    int64_t oneCounter = 0;
    
    if (base10 == 0) return "00110";
    else {
        for (size_t i = 0; i < 5 && oneCounter < 2; ++i) {
            if (base10 >= weight[i]) {
                code[i] = '1';
                base10 -= weight[i];
                oneCounter++;
            } else code[i] = '0';
        }
    }
    
    return code;
}

converter::TwoOnFive::TwoOnFive () {
    this->weight = { 6, 3, 2, 1, 0 };
}
