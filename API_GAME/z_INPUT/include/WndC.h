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

private:
	//�޽��� ó�� �Լ�
	static LRESULT CALLBACK MsgProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	bool registWnd(LPCWSTR LWndName);   //������ ��� ... �����ڿ��� ȣ����.

public:
	bool runWindow();                   //������ ������

public:
	virtual bool gameInit() { return true; }
	virtual bool gameRun() { return true; }                    //���� ���� ó�� (��ӹ��� Ŭ�������� ó��)
	virtual bool gameFrame() { return true; }
	virtual bool gameRender() { return true; }
	virtual bool gameRelease() { return true; }

public:
	HWND getHandle();                   //������ �ڵ� ��ȯ
	RECT getClient();
	RECT getWindow();

public:
	wndC(LPCWSTR LWndName);
	virtual ~wndC();
};