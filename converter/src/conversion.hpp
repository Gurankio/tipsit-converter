//
//  conversion.hpp
//  TIPSIT
//
//  Created by Gurankio on 14/05/2020.
//  Copyright © 2020 Gurankio. All rights reserved.
//

#ifndef converter_hpp
#define converter_hpp

#include <string>
#include <map>

#include "numeric.hpp"
#include "aiken.hpp"
#include "bcd.hpp"
#include "quinary.hpp"
#include "biquinary.hpp"
#include "twoOnFive.hpp"
#include "xs3.hpp"
#include "xs3r.hpp"
#include "ascii.hpp"
#include "utf8.hpp"
#include "roman.hpp"
#include "gray.hpp"
#include "oneOfN.hpp"
#include "segment7.hpp"
#include "fiscal.hpp"

namespace converter {

class Conversion {
private:
    std::string input;
    std::string inputType;
    std::map<std::string, std::string> inputOptions;
    std::string outputType;
    std::map<std::string, std::string> outputOptions;

public:
    Conversion (); // EXPLODE
    Conversion (const std::string& input,
                const std::string& inputType,
                const std::map<std::string, std::string>& inputOptions,
                const std::string& outputType,
                const std::map<std::string, std::string>& outputOptions);
    // virtual ~Conversion ();

    std::string getInput() const; // EXPLODE
    std::string getInputType() const; // EXPLODE
    std::map<std::string, std::string> getInputOptions() const; // EXPLODE
    std::string getOutputType() const; // EXPLODE
    std::map<std::string, std::string> getOutputOptions() const; // EXPLODE

    void setInput(const std::string& input); // EXPLODE
    void setInputType(const std::string& inputType); // EXPLODE
    void setInputOptions(const std::map<std::string, std::string>& inputOptions); // EXPLODE
    void setOutputType(const std::string& outputType); // EXPLODE
    void setOutputOptions(const std::map<std::string, std::string>& outputOptions); // EXPLODE

    std::string convert();
};

static const std::map<std::string, Code *> CODES = {
    { "numeric", new Numeric() },
    { "aiken", new Aiken() },
    { "bcd", new Bcd() },
    { "quinary", new Quinary() },
    { "biquinary", new Biquinary() },
    { "twoOnFive", new TwoOnFive() },
    { "xs3", new Xs3() },
    { "xs3r", new Xs3r() },
    { "ascii", new Ascii() },
    { "utf8", new Utf8() },
    { "roman", new Roman() },
    { "gray", new Gray() },
    { "oneOfN", new OneOfN() },
    { "segment7", new Segment7() },
    { "fiscal", new Fiscal() }
};

} /* converter */

#endif /* converter_hpp */
