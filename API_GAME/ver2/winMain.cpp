#pragma comment(lib, "core_lib.lib")  //이 라이브러리를 추가.
#include "03_CoreC.h"


class GameC : public CoreC
{

public:
	GameC(LPCWSTR LWndName) : CoreC(LWndName) {}
	virtual ~GameC() {}
};

HINSTANCE g_hInst;

//윈도우 생성을 완전히 클래스화 시킴
//TODO : 생성한 윈도우를 관리하는 매니저 클래스 필요.

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//프로그램 핸들을 전역변수로 대입
	g_hInst = hInst;

	GameC GameWnd(L"GameWindow");

	GameWnd.runWindow();

}