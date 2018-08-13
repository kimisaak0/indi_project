#pragma once

#include "header.h"

class wndC
{
private:
	WNDCLASSEX   m_wndC;        //������ Ŭ����
	HWND         m_hWnd;        //������ �ڵ�
	LPCWSTR      m_lWndName;    //������ �̸�

private:
	RECT         m_rtClient;    //������ �������� �۾����� ũ��.
	RECT         m_rtWindow;    //������ �������� ��ü���� ũ��

	//�޽��� ó�� �Լ�
	static LRESULT CALLBACK MsgProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	bool registWnd(LPCWSTR LWndName);   //������ ��� ... �����ڿ��� ȣ����.

public:
	bool runWindow();                   //���� ������

public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();

public:
	HWND getHandle();                   //������ �ڵ� ��ȯ
	RECT getClient();
	RECT getWindow();

public:
	wndC(LPCWSTR LWndName);
	virtual ~wndC();
};