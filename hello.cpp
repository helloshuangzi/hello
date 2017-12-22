#include <unordered_set>
#include <node.h>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

static std::unordered_set<std::string> _set;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "hello", Method);

  printf("before emplace\n");
  const char* name = "console";
  _set.emplace(name);
  printf("emplace console");
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo
