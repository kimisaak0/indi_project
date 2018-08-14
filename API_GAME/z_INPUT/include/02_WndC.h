#pragma once

//--------------------------------------------------------------------------------//
//-������ ������ ��� �� ������ �������� ũ�� ������ ���� ���븸 ������ �ֽ��ϴ�.-//
//--------------------------------------------------------------------------------//

#include "01_header.h"


class WndC
{
protected:
	WNDCLASSEX   m_wndC;        //������ Ŭ����
	HWND         m_hWnd;        //������ �ڵ�
	LPCWSTR      m_lWndName;    //������ �̸�

protected:
	RECT         m_rtClient;    //������ �������� �۾����� ũ��.
	RECT         m_rtWindow;    //������ �������� ��ü���� ũ��

private:
	//�޽��� ó�� �Լ�
	static LRESULT CALLBACK MsgProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	bool registWnd(LPCWSTR LWndName);   //������ ��� ... �����ڿ��� ȣ����.

public:
	bool runWindow();                   //������ ������

public:
	virtual bool gameInit() = 0;
	virtual bool gameRun() = 0;                    //���� ���� ó�� (��ӹ��� Ŭ�������� ó��)
	virtual bool gameFrame() = 0;
	virtual bool gameRender() = 0;
	virtual bool gameRelease() = 0;


	//�ϴ� ���� �������� �Q���� �� ������ ���� �� �������� �͵��� �־��.
//public:
//	HWND getHandle();                   //������ �ڵ� ��ȯ
//	RECT getClient();
//	RECT getWindow();
//
public:
	WndC(LPCWSTR LWndName);
	virtual ~WndC();
};