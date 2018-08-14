#pragma once

#pragma comment(lib, "winmm.lib") //timeGetTime

#include <assert.h>
#include <Windows.h>
#include <tchar.h>

#include <vector>
using std::vector;

#include <string>
using std::string;

//--------외부 변수 정의 영역----------//

// winMain에서 뺐음...
extern HINSTANCE g_hInst;   

//WndC에서 뺐음...
extern HWND      g_hWnd;      //생성된 윈도우의 핸들값 (DC를 받아올 때 사용함)
extern RECT      g_rtWindow;  //생성된 윈도우 전체영역 크기
extern RECT      g_rtClient;  //생성된 윈도우 작업영역 크기

//CoreC에서 뺐음...
extern HDC       g_hOnScreenDC;
extern HDC       g_hOffScreenDC;    

//TimerC에서 뻈음...
extern double    g_dSecPerFrame; //초당 프레임 수

//--------외부 변수 정의 끝----------//

//--------열거형 정의 영역----------//
enum KeyState
{
	KEY_FREE = 0,
	KEY_DOWN,
	KEY_UP,
	KEY_HOLD,
	KEY_end
};


//--------열거형 정의 끝----------//

template<class T> class SingleMgr
{
public:
	static T& GetInstance()
	{
		static T Instance;
		return Instance;
	}
};