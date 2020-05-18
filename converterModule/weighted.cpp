//
//  weighted.cpp
//  TIPSIT
//
//  Created by Gurankio on 16/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "weighted.hpp"

#include <sstream>

std::string converter::Weighted::to(const std::string& code) {
    std::string base10 = "";
    
    for (size_t i = 0; i < code.length(); i++) {
        
        if (code[i] == this->decimalSeparator) {
            base10 += '.';
            continue;
        }
        
        if (code[i] != this->numberSeparator) {
            std::string number = code.substr(i, this->weight.size());
            
            int64_t sum = 0;
            for (size_t j = 0; j < this->weight.size(); j++)
                sum += (number[j] - '0') * this->weight.at(j);
            base10 += std::to_string(sum);
            
            i += (this->weight.size() - 1); // nBits - 1
        }
    }
    
    return base10;
}

// Code specific implementation
std::string converter::Weighted::from(const std::string& base10) {
    std::string code = "";
    
    for (size_t i = 0; i < base10.length(); i++) {
        if (base10[i] == '.') {
            code += this->decimalSeparator;
            continue;
        }
        
        code += this->from(base10[i] - '0');
        
        // adding spaces
        if (base10[i + 1] != '.' && base10[i + 1] != '\0') code += this->numberSeparator;
    }
    
    return code;
}

std::string converter::Weighted::from(int64_t base10) {
    return std::to_string(base10);
}

converter::Weighted::Weighted () {
    // NO-OP
}

converter::Code* converter::Weighted::setOptions(const std::map<std::string, std::string>& options) {
    Code::setOptions(options);
    
    for (auto it = options.begin(); it != options.end(); it++) {
        if (it->first == "numberSeparator") {
            this->numberSeparator = it->second.at(0);
            continue;
        }
    }
    
    return this;
}
