//
//  biquinary.hpp
//  TIPSIT
//
//  Created by Gurankio on 17/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef biquinary_hpp
#define biquinary_hpp

#include "weighted.hpp"

namespace converter {

class Biquinary : public Weighted {
private:
    // Code specific implementation
    std::string from(int64_t base10);
    
public:
    Biquinary ();
    // virtual ~Code ();
};

} /* converter */

#endif /* biquinary_hpp */
