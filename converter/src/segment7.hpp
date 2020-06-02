//
//  segment7.hpp
//  TIPSIT
//
//  Created by Gurankio on 31/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef segment7_hpp
#define segment7_hpp

#include "code.hpp"

namespace converter {

class Segment7 : public Code {
private:
    std::string to(const std::string& code);
    
    std::string from(const std::string& base10);
    
protected:
    std::vector<std::string> base16;
    std::string minus;
    
    char numberSeparator = '_';
    
public:
    Segment7 ();
    // virtual ~Code ();
    
    Code* setOptions(const std::map<std::string, std::string>& options);
};

} /* converter */
#endif /* segment7_hpp */
