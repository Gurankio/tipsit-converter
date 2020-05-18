//
//  xs3.hpp
//  TIPSIT
//
//  Created by Gurankio on 17/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef xs3_hpp
#define xs3_hpp

#include "weighted.hpp"

namespace converter {

class Xs3 : public Weighted {
private:
    std::string to(const std::string& base10);
    
    // Code specific implementation
    std::string from(int64_t base10);
    
public:
    Xs3 ();
    // virtual ~Code ();
};

} /* converter */

#endif /* xs3_hpp */
