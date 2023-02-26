//#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

typedef int(*Count)(const wchar_t* str);
typedef const wchar_t* (*Through)(const wchar_t* str);
typedef const wchar_t* (*GetString)();

int main()
{
    auto dll = ::LoadLibrary(L"SampleDLL.dll");   // さっき作ったC# DLLの名前を指定する
    {
        auto count = reinterpret_cast<Count>(::GetProcAddress(dll, "Count"));
        wcout << count(L"ほげ") << endl;
        wcout << count(L"fuga") << endl;
        wcout << count(nullptr) << endl;

        auto through = reinterpret_cast<Through>(::GetProcAddress(dll, "Through"));
        auto str0 = through(L"test");
        wcout << str0 << endl;

        auto getString = reinterpret_cast<GetString>(::GetProcAddress(dll, "GetString"));
        auto str1 = getString();
        wcout << str1 << endl;
    }
    if (dll)
        ::FreeLibrary(dll); // 解放は忘れずに！！

    return 0;
}