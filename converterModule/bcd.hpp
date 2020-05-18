//
//  bcd.hpp
//  TIPSIT
//
//  Created by Gurankio on 17/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef bcd_hpp
#define bcd_hpp

#include "weighted.hpp"

namespace converter {

class Bcd : public Weighted {
private:
    // Code specific implementation
    std::string from(int64_t base10);
    
public:
    Bcd ();
    // virtual ~Code ();
};

} /* converter */

#endif /* bcd_hpp */
