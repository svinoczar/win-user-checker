#include <node.h>
#include <string>

using namespace v8;

extern "C" {
    void checkPrivilege(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = Isolate::GetCurrent();
        Local<Context> context = isolate->GetContext();
        Local<String> username = Local<String>::Cast(args[0]);
        Local<String> result = String::NewFromUtf8(isolate, checkPrivilege(std::string(username->Utf8Value())).c_str()).ToLocalChecked();
        args.GetReturnValue().Set(result);
    }
}

NODE_MODULE(addon, checkPrivilege)
