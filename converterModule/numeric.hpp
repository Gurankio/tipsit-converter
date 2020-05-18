//
//  numeric.hpp
//  TIPSIT
//
//  Created by Gurankio on 14/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef numeric_hpp
#define numeric_hpp

#include "code.hpp"

namespace converter {

class Numeric : public Code {
private:
    // Code specific implementation
    std::string to(const std::string& code);
    
    // Code specific implementation
    std::string from(const std::string& base10);
        
protected:
    const std::string alphabet = "0123456789ABCDEFGHILMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@_";
    
    int base = 10;
    int precision = 6;
    
public:
    Numeric ();
    // virtual ~Code ();
    
    Code* setOptions(const std::map<std::string, std::string>& options);
};

} /* converter */

#endif /* numeric_hpp */
