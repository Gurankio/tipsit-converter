//
//  biquinary.cpp
//  TIPSIT
//
//  Created by Gurankio on 17/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "biquinary.hpp"

std::string converter::Biquinary::from(int64_t base10) {
    std::string code = "00_00000"; // TODO: remove '_'

    if (base10 >= 5) {
      code[0] = '1';
      code[1] = '0';
      base10 -= 5;
    } else {
      code[0] = '0';
      code[1] = '1';
    }

    code[7 - base10] = '1';
    
    return code;
}

converter::Biquinary::Biquinary () {
    this->weight = { 0, 5, 0, 4, 3, 2, 1, 0 };
}
