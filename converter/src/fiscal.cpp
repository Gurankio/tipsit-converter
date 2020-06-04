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
#include <iostream>

std::vector<std::string> converter::Fiscal::to(const std::vector<std::string>& code) {
    std::string temp = "";
    for (auto it = code.begin(); it != code.end(); it++) {
        temp.append(*it);
        temp.push_back(' ');
    }
    return { this->to(temp) };
}

std::string converter::Fiscal::to(const std::string& code) {
    std::vector<std::string> tokens;

    std::string input = code;
    for (auto it = input.begin(); it != input.end(); it++) {
        *it = std::toupper(*it);
    }

    size_t pos;
    while ((pos = input.find(";")) != std::string::npos) { // TODO: make ',' a variable.
        tokens.push_back( input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    tokens.push_back(input.substr(0, pos));

    std::string result = "";

    // Cognome  i=1
    if (tokens.at(1).length() < 3) {
        result.append(tokens.at(1));
        result.push_back('X');
    } else {
        std::vector<char> consonant;
        std::vector<char> vowels;

        for (auto it = tokens.at(1).begin(); it != tokens.at(1).end(); it++) {
            if (*it == ' ') continue;
            if (*it != 'A' && *it != 'E' && *it != 'I' && *it != 'O' && *it != 'U') consonant.push_back(*it);
            else vowels.push_back(*it);
        }

        if (consonant.size() >= 3) {
            result.push_back(consonant.at(0));
            result.push_back(consonant.at(1));
            result.push_back(consonant.at(2));
        } else {
            result.push_back(consonant.at(0));
            result.push_back(consonant.at(1));
            result.push_back(vowels.at(0));
        }
    }

    // Nome  i=0
    if (tokens.at(0).length() < 3) {
        result.append(tokens.at(0));
        result.push_back('X');
    } else {
        std::vector<char> consonant;
        std::vector<char> vowels;

        for (auto it = tokens.at(0).begin(); it != tokens.at(0).end(); it++) {
            if (*it == ' ') continue;
            if (*it != 'A' && *it != 'E' && *it != 'I' && *it != 'O' && *it != 'U') consonant.push_back(*it);
            else vowels.push_back(*it);
        }

        if (consonant.size() >= 4) {
            result.push_back(consonant.at(0));
            result.push_back(consonant.at(2));
            result.push_back(consonant.at(3));
        } else if (consonant.size() == 3) {
            result.push_back(consonant.at(0));
            result.push_back(consonant.at(1));
            result.push_back(consonant.at(2));
        } else {
            result.push_back(consonant.at(0));
            result.push_back(consonant.at(1));
            result.push_back(vowels.at(0));
        }
    }

    // Data + Sesso  i=2, i=5
    std::string year(tokens.at(5).end() - 3, tokens.at(5).end() - 1);
    result.append(year);

    const char monthAlphabet[] = "ABCDEHLMPRST";
    auto firstDot = tokens.at(5).find_first_of('.');
    auto lastDot = tokens.at(5).find_last_of('.');
    std::string month(tokens.at(5).begin() + firstDot + 1, tokens.at(5).begin() + lastDot);
    int monthIndex = std::stoi(month) - 1;
    result.push_back(monthAlphabet[monthIndex]);

    bool isFemale = (tokens.at(2).at(0) == 'F');
    std::string day(tokens.at(5).begin(), tokens.at(5).begin() + 3);
    int actualDay = std::stoi(day) + isFemale * 40;
    result.append(std::to_string(actualDay));

    // Luogo + Provincia  i = 3, 4
    std::ifstream csv("./ANPR_archivio_comuni_semplice.csv");

    std::ostringstream pattern;
    pattern << "....;" << tokens.at(3) << ";" << tokens.at(4) << "\r";
    std::regex regex(pattern.str(), std::regex::icase);

    std::string temp;
    do {
        std::getline(csv, temp);
        std::cout << temp << std::endl;
    } while (!csv.eof() && !csv.fail() && !std::regex_match(temp, regex));

    if (csv.eof() || csv.fail()) {
        return "Luogo di nascita e sigla provincia non validi.";
    }

    std::string catastale(temp.begin(), temp.begin() + 4);
    csv.close();

    result.append(catastale);

    // Carattere Controllo

    std::map<char, int64_t> pari = {
        {'0', 1},
        {'1', 0},
        {'2', 5},
        {'3', 7},
        {'4', 9},
        {'5', 13},
        {'6', 15},
        {'7', 17},
        {'8', 19},
        {'9', 21},
        {'A', 1},
        {'B', 0},
        {'C', 5},
        {'D', 7},
        {'E', 9},
        {'F', 13},
        {'G', 15},
        {'H', 17},
        {'I', 19},
        {'J', 21},
        {'K', 2},
        {'L', 4},
        {'M', 18},
        {'N', 20},
        {'O', 11},
        {'P', 3},
        {'Q', 6},
        {'R', 8},
        {'S', 12},
        {'T', 14},
        {'U', 16},
        {'V', 10},
        {'W', 22},
        {'X', 25},
        {'Y', 24},
        {'Z', 23}
    };
    std::map<char, int64_t> dispari = {
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'A', 0},
        {'B', 1},
        {'C', 2},
        {'D', 3},
        {'E', 4},
        {'F', 5},
        {'G', 6},
        {'H', 7},
        {'I', 8},
        {'J', 9},
        {'K', 10},
        {'L', 11},
        {'M', 12},
        {'N', 13},
        {'O', 14},
        {'P', 15},
        {'Q', 16},
        {'R', 17},
        {'S', 18},
        {'T', 19},
        {'U', 20},
        {'V', 21},
        {'W', 22},
        {'X', 23},
        {'Y', 24},
        {'Z', 25}
    };
    const char resto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int64_t sum = 0;
    for (size_t i = 0; i < result.length(); i++) {
        if (i % 2) sum += dispari.at(result[i]);
        else sum += pari.at(result[i]);
    }
    sum %= 26;
    result.push_back(resto[sum]);

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
