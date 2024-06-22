#include <node.h>
#include "checkPrivilege.cpp"

using namespace v8;

extern "C" {
    void checkPrivilege(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = Isolate::GetCurrent();
        Local<Context> context = isolate->GetContext();
        Local<String> username = Local<String>::Cast(args[0]);
        Local<String> result = Local<String>::Cast(checkPrivilege(std::string(username->ToString())));
        args.GetReturnValue().Set(result);
    }
}

NODE_MODULE(addon, checkPrivilege)
