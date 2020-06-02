//
//  fiscal.cpp
//  TIPSIT
//
//  Created by Gurankio on 29/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "fiscal.hpp"

std::string converter::Fiscal::to(const std::string& code) {
    return code;
}

std::string converter::Fiscal::from(const std::string& base10) {
    return base10;
}

converter::Fiscal::Fiscal () {
    // NO-OP
}

converter::Code* converter::Fiscal::setOptions(const std::map<std::string, std::string>& options) {
    Code::setOptions(options);
    
    
    
    return this;
}
