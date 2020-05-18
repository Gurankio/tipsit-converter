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

namespace converter {

class Result {
private:
    //    int status;
    std::string output;
    
public:
    Result ();
    Result (const std::string& output);
    // virtual ~Result ();
    
    std::string getOutput() const;
    void setOutput(const std::string &output);
};

class Conversion {
private:
    std::string input;
    std::string inputType;
    std::map<std::string, std::string> inputOptions;
    std::string outputType;
    std::map<std::string, std::string> outputOptions;
    
public:
    Conversion ();
    Conversion (const std::string& input,
                const std::string& inputType,
                const std::map<std::string, std::string>& inputOptions,
                const std::string& outputType,
                const std::map<std::string, std::string>& outputOptions);
    // virtual ~Conversion ();
    
    std::string getInput() const;
    std::string getInputType() const;
    std::map<std::string, std::string> getInputOptions() const;
    std::string getOutputType() const;
    std::map<std::string, std::string> getOutputOptions() const;
    
    void setInput(const std::string& input);
    void setInputType(const std::string& inputType);
    void setInputOptions(const std::map<std::string, std::string>& inputOptions);
    void setOutputType(const std::string& outputType);
    void setOutputOptions(const std::map<std::string, std::string>& outputOptions);
    
    Result convert();
};

static const std::map<std::string, Code *> CODES = {
    { "numeric", new Numeric() },
    { "aiken", new Aiken() },
    { "bcd", new Bcd() },
    { "quinary", new Quinary() },
    { "biquinary", new Biquinary() },
    { "twoOnFive", new TwoOnFive() },
    { "xs3", new Xs3() },
    { "xs3r", new Xs3r() }
};

} /* converter */

#endif /* converter_hpp */
