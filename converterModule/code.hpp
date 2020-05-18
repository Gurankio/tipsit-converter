//
//  code.hpp
//  TIPSIT
//
//  Created by Gurankio on 14/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef code_hpp
#define code_hpp

#include <map>
#include <vector>
#include <string>

namespace converter {

class Code {
private:
    // Code specific implementation
    virtual std::string to(const std::string &code);
    
    // Code specific implementation
    virtual std::string from(const std::string &base10);
    
protected:
    char decimalSeparator = '.';
    
public:
    Code ();
    // virtual ~Code ();
    
    // Parse JS sent options
    virtual Code* setOptions(const std::map<std::string, std::string> &options);
    
    // Converts from Code to Internal (Base10)
    std::vector<std::string> to(const std::vector<std::string> &code);
    
    // Converts from Internal (Base10) to Code
    std::vector<std::string> from(const std::vector<std::string> &base10);
};

} /* converter */

#endif /* code_hpp */
