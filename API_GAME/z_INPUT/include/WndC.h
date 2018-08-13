#pragma once

#include "header.h"

class wndC
{
private:
	WNDCLASSEX   m_wndC;        //������ Ŭ����
	HWND         m_hWnd;        //������ �ڵ�
	LPCWSTR      m_lWndName;    //������ �̸�

private:
	RECT         m_rtClient;
	RECT         m_rtWindow;

	//�޽��� ó�� �Լ�
	static LRESULT CALLBACK MsgProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
public:

	bool registWnd(LPCWSTR LWndName);   //������ ���
	bool runWindow();                   //���� ������
	
	HWND getHandle();                   //������ �ڵ� ��ȯ


public:
	

public:
	wndC(LPCWSTR LWndName);
	~wndC();
};