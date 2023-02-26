#include "pch.h"

// C#をC++/CLIでラップするラッパー関数群
#include "CsWrapperCppCLI.h"

// C#(.net)のクラスのnamespace
using namespace DllCs;

// C++/CLIラッパー関数
int __cdecl Add(int a, int b)
{
    // ここで、C#(.net)のメソッドを呼ぶ
    int ret = DllCsClass::Add(a, b);

    return ret;
}
