//
//  xs3r.cpp
//  TIPSIT
//
//  Created by Gurankio on 17/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "xs3r.hpp"

std::string converter::Xs3r::to(const std::string& code) {
    std::string base10 = "";
    
    for (size_t i = 0; i < code.length(); i++) {
        if (code[i] == '-') {
            base10 += '-';
            continue;
        }
        
        if (code[i] == this->decimalSeparator) {
            base10 += this->decimalSeparator;
            continue;
        }
        
        if (code[i] != this->numberSeparator) {
            std::string number = code.substr(i, this->weight.size());
            
            int64_t sum = 0;
            for (size_t j = 0; j < this->weight.size(); j++)
                sum += (number[j] - '0') * this->weight.at(j);
            
            uint64_t mask = sum >> 1;
            while (mask != 0) {
               sum = sum ^ mask;
               mask = mask >> 1;
            }
            
            base10 += std::to_string(sum - 3); // notice the "-3"
            
            i += (this->weight.size() - 1); // nBits - 1
        }
    }
    
    return base10;
}

std::string converter::Xs3r::from(int64_t base10) {
    std::string code = "0000";
    base10 += 3;
    base10 = (base10 >> 1) ^ (base10);
    
    for (int64_t i = 0; i < this->weight.size(); ++i) {
        if (base10 >= this->weight.at(i)) {
            code[i] = '1';
            base10 -= this->weight.at(i);
        } else code[i] = '0';
    }
    
    return code;
}

converter::Xs3r::Xs3r () {
    this->weight = { 8, 4, 2, 1 };
}
