//
//  aiken.cpp
//  TIPSIT
//
//  Created by Gurankio on 17/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "aiken.hpp"

std::string converter::Aiken::from(int64_t base10) {
    std::string code = "0000";
    
    if (base10 >= 5) {
        code[0] = '1';
        base10 -= this->weight.at(0);
    } else code[0] = '0';
    
    for (size_t i = 1; i < this->weight.size(); i++) {
        if (base10 >= this->weight.at(i)) {
            code[i] = '1';
            base10 -= this->weight.at(i);
        } else code[i] = '0';
    }
    
    return code;
}

converter::Aiken::Aiken () {
    this->weight = { 2, 4, 2, 1 };
}
