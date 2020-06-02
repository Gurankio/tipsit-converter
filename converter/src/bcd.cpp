//
//  bcd.cpp
//  TIPSIT
//
//  Created by Gurankio on 17/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "bcd.hpp"

std::string converter::Bcd::from(int64_t base10) {
    std::string code = "0000";
    
    for (size_t i = 0; i < this->weight.size(); ++i) {
        if (base10 >= this->weight.at(i)) {
            code[i] = '1';
            base10 -= this->weight.at(i);
        } else code[i] = '0';
    }
    
    return code;
}

converter::Bcd::Bcd () {
    this->weight = { 8, 4, 2, 1 };
}
