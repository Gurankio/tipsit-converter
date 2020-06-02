//
//  oneOfN.hpp
//  TIPSIT
//
//  Created by Gurankio on 31/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef oneOfN_hpp
#define oneOfN_hpp

#include "code.hpp"

namespace converter {

class OneOfN : public Code {
private:
    std::string to(const std::string& code);
    
    std::string from(const std::string& base10);

protected:
    int64_t length = 8;
    
public:
    OneOfN ();
    // virtual ~Code ();
    
    Code* setOptions(const std::map<std::string, std::string>& options);
};

} /* converter */

#endif /* oneOfN_hpp */
