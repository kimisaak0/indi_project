#pragma comment(lib, "core_lib.lib")  //이 라이브러리를 추가.
#include "03_CoreC.h"
#include "12_1_HeroObjC.h"
#include "12_2_NpcObjC.h"


class GameC : public CoreC
{ 
	BgObjC     m_BackGround;
	HeroObjC   m_Hero;
	NpcObjC    m_Monster1;

public:
	bool    Init() override;
	bool    Frame() override;
	bool    Render() override;
	bool    Release() override;

public:
	GameC(LPCWSTR LWndName) : CoreC(LWndName) {}
	virtual ~GameC() {}
};

bool    GameC::Init()
{
	m_BackGround.Load(L"../z_INPUT/data/50x50/watar_tileset.bmp");
	m_BackGround.Set(0, 0, 0, 0, 50, 50);

	m_Hero.Load(L"../z_INPUT/data/50x50/Shipedits.bmp");
	m_Hero.Set(300, 300, 0, 0, 32, 30);

	m_Monster1.Load(L"../z_INPUT/data/50x50/bat.bmp");
	m_Monster1.Set(500, 500, 0, 0, 32, 32);
	return true;
}


bool    GameC::Frame()	 // 계산
{
	m_BackGround.Frame();
	m_Hero.Frame();

	m_Monster1.Frame();

	return true;
}

bool    GameC::Render() 	 // 드로우
{
	m_BackGround.Render();
	m_Hero.Render();

	m_Monster1.Render();

	return true;
}

bool    GameC::Release()  // 소멸, 삭제
{
	m_BackGround.Release();
	m_Hero.Release();

	m_Monster1.Release();

	return true;

}

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