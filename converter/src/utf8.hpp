//
//  utf8.hpp
//  TIPSIT
//
//  Created by Gurankio on 22/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef utf8_hpp
#define utf8_hpp

#include "code.hpp"

namespace converter {

class Utf8 : public Code {
private:
    std::string to(const std::string& code);
    
    std::string from(const std::string& base10);

protected:
    char numberSeparator = '_';
    
public:
    Utf8 ();
    // virtual ~Code ();
    
    Code* setOptions(const std::map<std::string, std::string>& options);
};

} /* converter */

#endif /* utf8_hpp */
