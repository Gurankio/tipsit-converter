//
//  twoOnFive.hpp
//  TIPSIT
//
//  Created by Gurankio on 17/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef twoOnFive_hpp
#define twoOnFive_hpp

#include "weighted.hpp"

namespace converter {

class TwoOnFive : public Weighted {
private:
    // Code specific implementation
    std::string from(int64_t base10);
    
public:
    TwoOnFive ();
    // virtual ~Code ();
};

} /* converter */

#endif /* twoOnFive_hpp */
