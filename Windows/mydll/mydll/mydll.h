#pragma once
#ifdef MYLIB_EXPORTS    
#define MYLIBAPI extern "C" __declspec(dllexport)
#else
#define MYLIBAPI extern "C" __declspec(dllimport)
#endif
MYLIBAPI int add1(int nLeft, int nRight);
MYLIBAPI int sub1(int nLeft, int nRight);
MYLIBAPI int mul1(int nLeft, int nRight);
MYLIBAPI int div1(int nLeft, int nRight);
