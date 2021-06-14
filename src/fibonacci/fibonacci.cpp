#include <nan.h>

double fib(double n) {
    if (n == 0 || n == 1)
        return n;
    else
        return fib(n-2) + fib(n-1);
}

void Fibonacci(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    if (info.Length() != 1 ) {
        Nan::ThrowTypeError("需要 1 個引數");
        return;
    }

    if (!info[0]->IsNumber() || !info[0]->IsInt32()) {
        Nan::ThrowTypeError("參數型態錯誤 : 不屬於 int");
        return;
    }

    int n = info[0]->NumberValue(context).FromJust();
    v8::Local<v8::Number> num = Nan::New(fib(n));

    info.GetReturnValue().Set(num);
}

void CreateFunction(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    v8::Local<v8::FunctionTemplate> tpl = 
        Nan::New<v8::FunctionTemplate>(Fibonacci);

    v8::Local<v8::Function> fn = tpl->GetFunction(context).ToLocalChecked();

    // 如果為匿名函式，省略此段命名
    fn->SetName(Nan::New("theFunction").ToLocalChecked());

    info.GetReturnValue().Set(fn);
}

void Init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
    Nan::SetMethod(module, "exports", CreateFunction);
}

NODE_MODULE(fibonacci, Init)