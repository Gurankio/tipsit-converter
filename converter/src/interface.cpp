#include "conversion.hpp"

#include <string>
#include <map>
#include <napi.h>

namespace converter {

  Napi::String convertWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 1 || !info[0].IsObject()) {
        Napi::TypeError::New(env, "Wrong convert parameters.").ThrowAsJavaScriptException();
    }

    Napi::Object inputObject = info[0].As<Napi::Object>();
    Napi::String input = inputObject.Get("data").As<Napi::String>();
    Napi::String inputType = inputObject.Get("inputType").As<Napi::String>();
    Napi::String outputType = inputObject.Get("outputType").As<Napi::String>();

    Napi::Object inputOptions = inputObject.Get("inputOptions").As<Napi::Object>();
    Napi::Array inputObjectKeys = inputOptions.GetPropertyNames();
    std::map<std::string, std::string> inputOptionsMap;
    for (size_t i = 0; i < inputObjectKeys.Length(); i++) {
      Napi::String key = inputObjectKeys.Get(i).As<Napi::String>();
      Napi::String value = inputOptions.Get(inputObjectKeys[i]).As<Napi::String>();
      inputOptionsMap.emplace(key, value);
    }

    Napi::Object outputOptions = inputObject.Get("outputOptions").As<Napi::Object>();
    Napi::Array outputObjectKeys = outputOptions.GetPropertyNames();
    std::map<std::string, std::string> outputOptionsMap;
    for (size_t i = 0; i < outputObjectKeys.Length(); i++) {
      Napi::String key = outputObjectKeys.Get(i).As<Napi::String>();
      Napi::String value = outputOptions.Get(outputObjectKeys[i]).As<Napi::String>();
      outputOptionsMap.emplace(key, value);
    }

    Napi::String output = Napi::String::New(env, converter::Conversion(input, inputType, inputOptionsMap, outputType, outputOptionsMap).convert());
    return output;
  }

  Napi::Object Initialize(Napi::Env env, Napi::Object exports) {
    exports.Set("convert", Napi::Function::New(env, converter::convertWrapped));
    return exports;
  }

  NODE_API_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
