#include "pch.h"

// C#��C++/CLI�Ń��b�v���郉�b�p�[�֐��Q
#include "CsWrapperCppCLI.h"

// C#(.net)�̃N���X��namespace
using namespace DllCs;

// C++/CLI���b�p�[�֐�
int __cdecl Add(int a, int b)
{
    // �����ŁAC#(.net)�̃��\�b�h���Ă�
    int ret = DllCsClass::Add(a, b);

    return ret;
}
