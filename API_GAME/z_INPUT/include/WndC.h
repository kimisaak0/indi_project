#pragma once

#include "header.h"

class wndC
{
private:
	WNDCLASSEX   m_wndC;        //윈도우 클래스
	HWND         m_hWnd;        //윈도우 핸들
	LPCWSTR      m_lWndName;    //윈도우 이름

private:
	RECT         m_rtClient;    //생성된 윈도우의 작업영역 크기.
	RECT         m_rtWindow;    //생성된 윈도우의 전체영역 크기

private:
	//메시지 처리 함수
	static LRESULT CALLBACK MsgProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	bool registWnd(LPCWSTR LWndName);   //윈도우 등록 ... 생성자에서 호출함.

public:
	bool runWindow();                   //윈도우 돌리기

public:
	virtual bool gameInit() { return true; }
	virtual bool gameRun() { return true; }                    //게임 내용 처리 (상속받은 클래스에서 처리)
	virtual bool gameFrame() { return true; }
	virtual bool gameRender() { return true; }
	virtual bool gameRelease() { return true; }

public:
	HWND getHandle();                   //윈도우 핸들 반환
	RECT getClient();
	RECT getWindow();

public:
	wndC(LPCWSTR LWndName);
	virtual ~wndC();
};