#pragma once

#pragma comment(lib, "winmm.lib") //timeGetTime

#include <assert.h>
#include <Windows.h>
#include <tchar.h>

#include <vector>
using std::vector;

#include <string>
using std::string;

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