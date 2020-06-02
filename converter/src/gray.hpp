//
//  gray.hpp
//  TIPSIT
//
//  Created by Gurankio on 22/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef gray_hpp
#define gray_hpp

#include "code.hpp"

namespace converter {

class Gray : public Code {
private:
    std::string to(const std::string& code);
    
    std::string from(const std::string& base10);

public:
    Gray ();
    // virtual ~Code ();
    
    Code* setOptions(const std::map<std::string, std::string>& options);
};

} /* converter */

#endif /* gray_hpp */
