//
//  quinary.hpp
//  TIPSIT
//
//  Created by Gurankio on 17/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef quinary_hpp
#define quinary_hpp

#include "weighted.hpp"

namespace converter {

class Quinary : public Weighted {
private:
    // Code specific implementation
    std::string from(int64_t base10);
    
public:
    Quinary ();
    // virtual ~Code ();
};

} /* converter */

#endif /* quinary_hpp */
