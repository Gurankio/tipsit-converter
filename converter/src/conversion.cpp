//
//  conversion.cpp
//  TIPSIT
//
//  Created by Gurankio on 14/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "conversion.hpp"

// Conversion

converter::Conversion::Conversion() {
    // NO-OP
}

converter::Conversion::Conversion (const std::string& input,
                                   const std::string& inputType,
                                   const std::map<std::string, std::string>& inputOptions,
                                   const std::string& outputType,
                                   const std::map<std::string, std::string>& outputOptions) {
    this->input = input;
    this->inputType = inputType;
    this->inputOptions = inputOptions;
    this->outputType = outputType;
    this->outputOptions = outputOptions;
}

std::string converter::Conversion::convert() {
    std::vector<std::string> temp;

    // Input: Splitting by ' '
    std::string input = this->input;
    size_t pos;
    while ((pos = input.find(" ")) != std::string::npos) {
        temp.push_back( input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    temp.push_back(input.substr(0, pos));

    // Converting
    temp = converter::CODES.at(this->inputType)->setOptions(this->inputOptions)->to(temp);
    temp = converter::CODES.at(this->outputType)->setOptions(this->outputOptions)->from(temp);

    // Output
    std::string output;
    for (auto it = temp.begin(); it != temp.end(); it++) output += *it + " ";
    output.erase(output.end() - 1); // Removes last space
    return output;
}
