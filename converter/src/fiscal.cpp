//
//  fiscal.cpp
//  TIPSIT
//
//  Created by Gurankio on 29/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#include "fiscal.hpp"

#include <sstream>
#include <fstream>
#include <regex>

std::string converter::Fiscal::to(const std::string& code) {
    std::vector<std::string> tokens;
    
    std::string input = code;
    size_t pos;
    while ((pos = input.find(",")) != std::string::npos) { // TODO: make ',' a variable.
        tokens.push_back( input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    tokens.push_back(input.substr(0, pos));
    
    std::string result = "";
    
    // Cognome
    
    
    
    
    // Nome
    
    
    
    // Data + Sesso
    
    
    
    // Luogo + Provincia
    std::ifstream csv("./ANPR_archivio_comuni_semplice.csv");
    
    std::ostringstream pattern;
    pattern << "....;" << ";" << ";";
    std::regex regex(pattern.str(), std::regex::icase);
    
    std::string temp;
    
    do {
        std::getline(csv, temp);
    } while (!std::regex_match(temp, regex));
    
    if (csv.eof() || csv.fail()) {
        return "Luogo di nascita e sigla provincia non validi.";
    }
    
    std::string catastale(temp.begin(), temp.begin() + 4);
    csv.close();
    
    return result;
}

std::string converter::Fiscal::from(const std::string& base10) {
    // This is intended.
    return base10;
}

converter::Fiscal::Fiscal () {
    // NO-OP
}

converter::Code* converter::Fiscal::setOptions(const std::map<std::string, std::string>& options) {
    Code::setOptions(options);
    return this;
}
