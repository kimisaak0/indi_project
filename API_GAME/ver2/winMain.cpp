#pragma comment(lib, "core_lib.lib")  //이 라이브러리를 추가.
#include "03_CoreC.h"


class GameC : public CoreC
{
	/*BgObjC m_BackGround;*/

public:
	bool    Init() 
	{
		//m_BackGround.Load(L"../z_INPUT/data/50x50/watar_tileset.bmp");
		//m_BackGround.Set(0, 0, 0, 0, 50, 50);

		//m_Hero.Load(L"../z_INPUT/data/50x50/Shipedits.bmp");
		//m_Hero.Set(300, 300, 0, 0, 32, 30);


		return true;
	}

	bool    Frame()	 // 계산
	{
		/*m_BackGround.Frame();*/
		//m_Hero.Frame();
		return true;
	}

	bool    Render() 	 // 드로우
	{
		/*m_BackGround.Render();*/
		//m_Hero.Render();

		return true;
	}

	bool    Release()  // 소멸, 삭제
	{
		/*m_BackGround.Release();*/
		//m_Hero.Release();

		return true;

	}

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