#pragma comment(lib, "core_lib.lib")  //�� ���̺귯���� �߰�.


#include "wndC.h"


HINSTANCE g_hInst;

//������ ������ ������ Ŭ����ȭ ��Ŵ
//TODO : ������ �����츦 �����ϴ� �Ŵ��� Ŭ���� �ʿ�.

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//���α׷� �ڵ��� ���������� ����
	g_hInst = hInst;

	wndC GameWnd;

	GameWnd.runWindow();

}