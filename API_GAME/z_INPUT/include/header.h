#pragma once

#pragma comment(lib, "winmm.lib") //timeGetTime

#include <assert.h>
#include <Windows.h>
#include <tchar.h>

#include <vector>
using std::vector;

#include <string>
using std::string;


extern HINSTANCE g_hInst;
extern HWND      g_hWnd;



template<class T> class SingleMgr
{
public:
	static T& GetInstance()
	{
		static T Instance;
		return Instance;
	}
};