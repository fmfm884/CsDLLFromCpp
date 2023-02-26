#pragma once

// エクスポートとインポートの切り替え
#ifdef VC_DLL_EXPORTS
#undef VC_DLL_EXPORTS
#define VC_DLL_EXPORTS extern "C" __declspec(dllexport)
#else
#define VC_DLL_EXPORTS extern "C" __declspec(dllimport)
#endif

VC_DLL_EXPORTS int __cdecl Add(int a, int b);

using namespace System;

namespace CsWrapperCppCLI {
	public ref class Class1
	{
		// TODO: このクラスのメソッドをここに追加します。
	};
}
