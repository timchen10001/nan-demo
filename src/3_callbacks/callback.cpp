#include <nan.h>

void CallBack(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Function> cb = info[0].As<v8::Function>();
    
    const unsigned argc = 1;

    v8::Local<v8::Value> argv[argc] = { Nan::New("Hello World").ToLocalChecked() };

    Nan::AsyncResource resource("nan:makeCallback");

    resource.runInAsyncScope(Nan::GetCurrentContext()->Global(), cb, argc, argv);
}

void Init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
    Nan::SetMethod(module, "exports", CallBack);
}

NODE_MODULE(callback, Init);