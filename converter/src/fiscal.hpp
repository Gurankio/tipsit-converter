//
//  fiscal.hpp
//  TIPSIT
//
//  Created by Gurankio on 29/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef fiscal_hpp
#define fiscal_hpp

#include "code.hpp"

namespace converter {

class Fiscal : public Code {
private:
    std::string to(const std::string& code);
    
    std::string from(const std::string& base10);
    
public:
    Fiscal ();  
    // virtual ~Code ();
    
    Code* setOptions(const std::map<std::string, std::string>& options);
};

} /* converter */

#endif /* fiscal_hpp */
