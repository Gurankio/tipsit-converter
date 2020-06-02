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
    setInput(input);
    setInputType(inputType);
    setInputOptions(inputOptions);
    setOutputType(outputType);
    setOutputOptions(outputOptions);
}

std::string converter::Conversion::getInput() const {
    return this->input;
}

std::string converter::Conversion::getInputType() const {
    return this->inputType;
}

std::map<std::string, std::string> converter::Conversion::getInputOptions() const {
    return this->inputOptions;
}

std::string converter::Conversion::getOutputType() const {
    return this->outputType;
}

std::map<std::string, std::string> converter::Conversion::getOutputOptions() const {
    return this->outputOptions;
}

void converter::Conversion::setInput(const std::string& input) {
    this->input = input;
}

void converter::Conversion::setInputType(const std::string& inputType) {
    this->inputType = inputType;
}

void converter::Conversion::setInputOptions(const std::map<std::string, std::string>& inputOptions) {
    this->inputOptions = inputOptions;
}

void converter::Conversion::setOutputType(const std::string& outputType) {
    this->outputType = outputType;
}

void converter::Conversion::setOutputOptions(const std::map<std::string, std::string>& outputOptions) {
    this->outputOptions = outputOptions;
}

#include <iostream>

std::string converter::Conversion::convert() {
    std::vector<std::string> temp;

    // Input: Splitting by ' '
    std::string input = getInput();
    size_t pos;
    while ((pos = input.find(" ")) != std::string::npos) {
        temp.push_back( input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    temp.push_back(input.substr(0, pos));

    // Converting
    temp = converter::CODES.at(getInputType())->setOptions(getInputOptions())->to(temp);
    temp = converter::CODES.at(getOutputType())->setOptions(getOutputOptions())->from(temp);

    // Output
    std::string output;
    for (auto it = temp.begin(); it != temp.end(); it++) output += *it + " ";
    output.erase(output.end() - 1); // Removes last space
    return output;
}
