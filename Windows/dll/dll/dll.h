#pragma once
#ifdef MYLIB_EXPORTS ���
#define MYLIBAPI extern "C" __declspec(dllexport)
#else
#define MYLIBAPI extern "C" __declspec(dllimport)
#endif
MYLIBAPI int add(int nLeft, int nRight);
MYLIBAPI int sub(int nLeft, int nRight);
