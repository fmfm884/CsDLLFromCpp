﻿using System;
using System.Runtime.InteropServices;  // Marshalを使うのに必要

namespace SampleDLL
{
    public class TestDLL
    {
        [DllExport]
        public static int Count(IntPtr stringPtr)
        {
            var str = Marshal.PtrToStringAuto(stringPtr);    // IntPtrをstring型に変換
            return str?.Length ?? 0;                         // intやdoubleなどのプリミティブはそのままreturnでOK!!
        }

        [DllExport]
        public static IntPtr Through(IntPtr stringPtr)
        {
            var str = Marshal.PtrToStringAuto(stringPtr);    // IntPtrをstring型に変換
            return Marshal.StringToHGlobalAuto(str);         // string型をIntPtrに変換してreturn
        }

        [DllExport]
        public static IntPtr GetString()
        {
            return Marshal.StringToHGlobalAuto("hoge fuga piyo");    // string型をIntPtrに変換してreturn
        }

       
    }
}