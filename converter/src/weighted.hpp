//
//  weighted.hpp
//  TIPSIT
//
//  Created by Gurankio on 16/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef weighted_hpp
#define weighted_hpp

#include "code.hpp"

namespace converter {

class Weighted : public Code {
private:
    std::string to(const std::string& code);
    
    std::string from(const std::string& base10);
    
    // Code specific implementation
    virtual std::string from(int64_t base10);
    
protected:
    std::vector<int> weight;
    
    char numberSeparator = '-';
    
public:
    Weighted ();
    // virtual ~Code ();
    
    Code* setOptions(const std::map<std::string, std::string>& options);
};

} /* converter */

#endif /* aiken_hpp */
