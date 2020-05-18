//
//  main.cpp
//  TIPSIT
//
//  Created by Gurankio on 14/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include <iostream>

#include "./conversion.hpp"

int main(int argc, char const *argv[]) {
    std::cout << "Hello" << std::endl;
    std::cout << converter::Conversion("11.123", "numeric", {{"base", "10"}}, "xs3r", {}).convert().getOutput() << std::endl;
    return 0;
}
