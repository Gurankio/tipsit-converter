//
//  roman.hpp
//  TIPSIT
//
//  Created by Gurankio on 29/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef roman_hpp
#define roman_hpp

#include "code.hpp"

namespace converter {

class Roman : public Code {
private:
    std::string to(const std::string& code);
    
    std::string from(const std::string& base10);

public:
    Roman ();
    // virtual ~Code ();
    
    Code* setOptions(const std::map<std::string, std::string>& options);
};

} /* converter */

#endif /* roman_hpp */
