//
//  twoOnFive.cpp
//  TIPSIT
//
//  Created by Gurankio on 17/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "twoOnFive.hpp"

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
