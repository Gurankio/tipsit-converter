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
(converter::Conversion(input, inputMod, {}, outputMod, {}).convert() == expectedOutput)  << std::endl;


int main(int argc, char const *argv[]) {
    test("-101.987", "numeric", "-0001_0000_0001.1111_1110_1101", "aiken");
    test("-101.987", "numeric", "-0001_0000_0001.1001_1000_0111", "bcd");
    test("-101.987", "numeric", "-0001_0000_0001.1100_1011_1010", "quinary");
    test("-101.987", "numeric", "-0100010_0100001_0100010.1010000_1001000_1000100", "biquinary");
    test("-101.987", "numeric", "-00011_00110_00011.11000_10100_10010", "twoOnFive");
    test("-101.987", "numeric", "-0100_0011_0100.1100_1011_1010", "xs3");
    test("-101.987", "numeric", "-0110_0010_0110.1010_1110_1111", "xs3r");
    test("-101.987", "numeric", "\233", "ascii");
    test("49", "numeric", "1", "ascii");
    test("-101.987", "numeric", "01100101", "utf8");
    test("8364", "numeric", "11100010_10000010_10101100", "utf8");
    test("16", "numeric", "00010000", "utf8");
    test("-101.987", "numeric", "-CI", "roman");
    test("-101.987", "numeric", "-01010111", "gray");
    test("-10.987", "numeric", "0000001000000000", "oneOfN");
    test("-101.987", "numeric", "0000001_1011111_1011011", "segment7");
        
    std::cout << std::endl;
    
    test("-0001_0000_0001.1111_1110_1101", "aiken", "-101.986999", "numeric");
    test("-0001_0000_0001.1001_1000_0111", "bcd", "-101.986999", "numeric");
    test("-0001_0000_0001.1100_1011_1010", "quinary", "-101.986999", "numeric");
    test("-0100010_0100001_0100010.1010000_1001000_1000100", "biquinary", "-101.986999", "numeric");
    test("-00011_00110_00011.11000_10100_10010", "twoOnFive", "-101.986999", "numeric");
    test("-0100_0011_0100.1100_1011_1010", "xs3", "-101.986999", "numeric");
    test("-0110_0010_0110.1010_1110_1111", "xs3r", "-101.986999", "numeric");
    test("1", "ascii", "49", "numeric");
    test("11100010_10011101_10110101", "utf8", "10101", "numeric");
    test("01101001", "utf8", "105", "numeric");
    test("-CI", "roman", "-101", "numeric");
    test("-01010111", "gray", "-101", "numeric");
    test("0000001000000000", "oneOfN", "10", "numeric");
    test("0000001_1011111_1011011", "segment7", "-101", "numeric");
    
    std::cout << std::endl;
    
    std::cout << "case check 1: " << (converter::Conversion("20af", "numeric", {{"base", "16"}}, "numeric", {}).convert() == converter::Conversion("20AF", "numeric", {{"base", "16"}}, "numeric", {}).convert()) << std::endl;
    std::cout << "case check 2: " << (converter::Conversion("20az", "numeric", {{"base", "16"}}, "numeric", {}).convert() == converter::Conversion("20AZ", "numeric", {{"base", "16"}}, "numeric", {}).convert()) << std::endl;

    std::cout << "Fiscale Test:" << std::endl;
    std::cout << converter::Conversion("Jacopo;Del Granchio;M;Bagno A Ripoli;FI;14.04.2003", "fiscal", {}, "fiscal", {}).convert() << std::endl;
    
    return 0;
}
