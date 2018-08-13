#pragma once

#include "header.h"

class wndC
{
private:
	WNDCLASSEX   m_wndC;        //윈도우 클래스
	HWND         m_hWnd;        //윈도우 핸들
	LPCWSTR      m_lWndName;    //윈도우 이름

private:
	RECT         m_rtClient;
	RECT         m_rtWindow;

	//메시지 처리 함수
	static LRESULT CALLBACK MsgProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
public:

	bool registWnd(LPCWSTR LWndName);   //윈도우 등록
	bool runWindow();                   //내용 돌리기
	
	HWND getHandle();                   //윈도우 핸들 반환


public:
	

public:
	wndC(LPCWSTR LWndName);
	~wndC();
};