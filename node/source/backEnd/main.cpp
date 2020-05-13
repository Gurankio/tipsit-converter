#include <napi.h>

namespace converter {

  int add(int a, int b){
    return a + b;
  }

  Napi::Number AddWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Numbers expected.").ThrowAsJavaScriptException();
    }

    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    Napi::Number returnValue = Napi::Number::New(env, converter::add(first.Int32Value(), second.Int32Value()));
    return returnValue;
  }

  std::string hello() {
    return "Hello World";
  }

  Napi::String HelloWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::String returnValue = Napi::String::New(env, converter::hello());

    return returnValue;
  }

  Napi::Object Initialize(Napi::Env env, Napi::Object exports) {
    exports.Set("add", Napi::Function::New(env, converter::AddWrapped));
    exports.Set("hello", Napi::Function::New(env, converter::HelloWrapped));
    return exports;
  }

  NODE_API_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
