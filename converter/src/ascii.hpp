//
//  ascii.hpp
//  TIPSIT
//
//  Created by Gurankio on 21/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef ascii_hpp
#define ascii_hpp

#include "code.hpp"

namespace converter {

class Ascii : public Code {
private:
    std::vector<std::string> to(const std::vector<std::string>& code);
    std::string to(const std::string& code);
    
    std::string from(const std::string& base10);

public:
    Ascii ();
    // virtual ~Code ();
    
    Code* setOptions(const std::map<std::string, std::string>& options);
};

} /* converter */

#endif /* ascii_hpp */
