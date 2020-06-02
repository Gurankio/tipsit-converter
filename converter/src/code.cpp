//
//  code.cpp
//  TIPSIT
//
//  Created by Gurankio on 14/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "code.hpp"

// Code specific implementation
std::string converter::Code::to(const std::string& code) {
    return code;
}

// Code specific implementation
std::string converter::Code::from(const std::string& base10) {
    return base10;
}

converter::Code::Code() {
    // NO-OP
}

// Parse JS sent options
converter::Code* converter::Code::setOptions(const std::map<std::string, std::string>& options) {
    for (auto it = options.begin(); it != options.end(); it++) {
        if (it->first == "decimalSeparator") {
            this->decimalSeparator = it->second[0];
            continue;
        }
    }
    
    return this;
}

// Converts from Code to Internal (Base10)
std::vector<std::string> converter::Code::to(const std::vector<std::string>& code) {
    std::vector<std::string> base10;
    for (auto it = code.begin(); it != code.end(); it++) base10.push_back(this->to(*it));
    return base10;
}

// Converts from Internal (Base10) to Code
std::vector<std::string> converter::Code::from(const std::vector<std::string>& base10) {
    std::vector<std::string> code;
    for (auto it = base10.begin(); it != base10.end(); it++) code.push_back(this->from(*it));
    return code;
}
