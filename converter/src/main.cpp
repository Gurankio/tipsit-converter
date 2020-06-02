//
//  main.cpp
//  TIPSIT
//
//  Created by Gurankio on 14/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include <iostream>

#include "./conversion.hpp"


#define test(input, inputMod, expectedOutput, outputMod) \
std::cout << inputMod << " -> " << outputMod << ": " << \
(converter::Conversion(input, inputMod, {}, outputMod, {}).convert().getOutput() == expectedOutput) << std::endl;


int main(int argc, char const *argv[]) {
    test("-101.987", "numeric", "-0001_0000_0001.1111_1110_1101", "aiken");
    test("-101.987", "numeric", "-0001_0000_0001.1001_1000_0111", "bcd");
    test("-101.987", "numeric", "-0001_0000_0001.1100_1011_1010", "quinary");
    test("-101.987", "numeric", "-01_00010_01_00001_01_00010.10_10000_10_01000_10_00100", "biquinary");
    test("-101.987", "numeric", "-00011_00110_00011.11000_10100_10010", "twoOnFive");
    test("-101.987", "numeric", "-0100_0011_0100.1100_1011_1010", "xs3");
    test("-101.987", "numeric", "-0110_0010_0110.1010_1110_1111", "xs3r");
    test("-101.987", "numeric", "\233", "ascii");
    test("49", "numeric", "1", "ascii");
    test("-101.987", "numeric", "01100101", "utf8");
    test("8364", "numeric", "11100010_10000010_10101100", "utf8");
    test("-101.987", "numeric", "-CI", "roman");
    test("-101.987", "numeric", "-01010111", "gray");
    test("-10.987", "numeric", "0000001000000000", "oneOfN");
    test("-101.987", "numeric", "0000001_1011111_1011011", "7segment");
//  not implemented:  test("-101.987", "numeric", "asd", "fiscal");
    
    std::cout << std::endl;
    
    test("-0001_0000_0001.1111_1110_1101", "aiken", "-101.986999", "numeric");
    test("-0001_0000_0001.1001_1000_0111", "bcd", "-101.986999", "numeric");
    test("-0001_0000_0001.1100_1011_1010", "quinary", "-101.986999", "numeric");
    test("-01_00010_01_00001_01_00010.10_10000_10_01000_10_00100", "biquinary", "-101.986999", "numeric");
    test("-00011_00110_00011.11000_10100_10010", "twoOnFive", "-101.986999", "numeric");
    test("-0100_0011_0100.1100_1011_1010", "xs3", "-101.986999", "numeric");
    test("-0110_0010_0110.1010_1110_1111", "xs3r", "-101.986999", "numeric");
    test("1", "ascii", "49", "numeric");
    test("01100101", "utf8", "101", "numeric");
    test("-CI", "roman", "-101", "numeric");
//  TODO:  test("-01010111", "gray", "-101.987", "numeric");
    test("0000001000000000", "oneOfN", "10", "numeric");
    test("0000001_1011111_1011011", "7segment", "-101", "numeric");
//  not implemented:  test("-101.987", "numeric", "asd", "fiscal");

    return 0;
}
