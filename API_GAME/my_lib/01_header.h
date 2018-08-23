#pragma once

#pragma comment(lib, "winmm.lib") //timeGetTime

#include <assert.h>
#include <Windows.h>
#include <tchar.h>

#include <iostream>

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <list>
using std::list;

typedef std::basic_string<char> C_STR;
typedef std::basic_string<wchar_t> W_STR;
typedef std::basic_string<TCHAR> T_STR;

//--------�ܺ� ���� ���� ����----------//

// winMain���� ����...
extern HINSTANCE g_hInst;   

//WndC���� ����...
extern HWND      g_hWnd;      //������ �������� �ڵ鰪 (DC�� �޾ƿ� �� �����)
extern RECT      g_rtWindow;  //������ ������ ��ü���� ũ��
extern RECT      g_rtClient;  //������ ������ �۾����� ũ��

//CoreC���� ����...
extern HDC       g_hOnScreenDC;
extern HDC       g_hOffScreenDC;    

//TimerC���� �Q��...
extern double    g_dSecPerFrame; //�ʴ� ������ ��

//--------�ܺ� ���� ���� ��----------//

//--------������ ���� ����----------//
enum KeyState
{
	KEY_FREE = 0,
	KEY_DOWN,
	KEY_UP,
	KEY_HOLD,
	KEY_end
};


//--------������ ���� ��----------//

template<class T> class SingleMgr
{
public:
	static T& GetInstance()
	{
		static T Instance;
		return Instance;
	}
};