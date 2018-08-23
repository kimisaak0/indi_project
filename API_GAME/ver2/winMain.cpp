#pragma comment(lib, "core_lib.lib")  //이 라이브러리를 추가.
#include "03_CoreC.h"
#include "12_1_HeroObjC.h"
#include "12_2_MobAC.h"
#include "13_1MouseObjC.h"
#include "14_1_StatueMOC.h"
#include "14_2_Rock1MOC.h"

#define  g_MaxMobA  100
#define  g_MaxRock  10


class GameC : public CoreC
{ 
	BgObjC     m_BackGround;

	StatueMOC    m_statue;
	vector<Rock1MOC>    m_Rock1_List;

	HeroObjC   m_Hero;
	vector<MobAC>   m_MobA_List;

	MouseObjC  m_MouseCursor;

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
	srand((unsigned)GetTickCount());

	m_MouseCursor.Load(L"../z_INPUT/data/50x50/CursorImage.bmp");
	m_MouseCursor.Set(0, 0, 0, 0, 200,200);

	m_BackGround.Load(L"../z_INPUT/data/50x50/watar_tileset.bmp");
	m_BackGround.Set(0, 0, 0, 0, 50, 50);

	m_statue.Load(L"../z_INPUT/data/50x50/Statue.bmp");
	m_statue.Set(800, 300, 0, 0, 135, 160);

	

	m_Hero.Load(L"../z_INPUT/data/50x50/Shipedits.bmp");
	m_Hero.Set(300, 300, 0, 0, 32, 30);

	m_MobA_List.resize(g_MaxMobA);
	for (int iObj = 0; iObj < g_MaxMobA; iObj++) {
		m_MobA_List[iObj].Load(L"../z_INPUT/data/50x50/bat.bmp");
		m_MobA_List[iObj].Set(rand() % (g_rtClient.right - 200) + 100, rand() % (g_rtClient.bottom - 200) + 100 , 0, 0, 32, 32);
		//m_MobA_List[iObj].Set(0,0, 0, 0, 32, 32);
	}
	
	m_Rock1_List.resize(g_MaxRock);
	for (int iObj = 0; iObj < g_MaxRock; iObj++) {
		m_Rock1_List[iObj].Load(L"../z_INPUT/data/50x50/Rock.bmp");
		m_Rock1_List[iObj].Set(rand() % (g_rtClient.right - 200) + 100, rand() % (g_rtClient.bottom - 200) + 100, 21, 7, 48, 48);

	}

	return true;
}


bool    GameC::Frame()	 // 계산
{
	

	m_BackGround.Frame();
	m_Hero.Frame();

	m_statue.Frame();

	for (int iObj = 0; iObj < g_MaxMobA; iObj++) {
		m_MobA_List[iObj].Frame();
	}
	
	for (int iObj = 0; iObj < g_MaxRock; iObj++) {
		m_Rock1_List[iObj].setMapCls(true, m_Rock1_List[iObj].getRtCls());
	}

	//몹1 관련 충돌
	for (int iObj = 0; iObj < g_MaxMobA; iObj++) {
		if (I_ClsMgr.RectInRect(m_MobA_List[iObj].getRtCls(), m_Hero.getRtCls())) {
			m_MobA_List[iObj].setExist(false);
		}

		if (I_ClsMgr.RectInRect(m_MobA_List[iObj].getRtCls(), m_statue.getRtCls())) {
			m_MobA_List[iObj].setMapCls(true, m_statue.getRtCls());
		}

		for (int kObj = 0; kObj < g_MaxRock; kObj++) {
			if (I_ClsMgr.RectInRect(m_MobA_List[iObj].getRtCls(), m_Rock1_List[kObj].getRtCls())) {
				m_MobA_List[iObj].setMapCls(true, m_Rock1_List[kObj].getRtCls());
			}
		}
	}



	m_MouseCursor.Frame();

	return true;
}

bool    GameC::Render() 	 // 드로우
{

	m_BackGround.Render();
	m_Hero.Render();

	m_statue.Render();

	for (int iObj = 0; iObj < g_MaxMobA; iObj++) {
		m_MobA_List[iObj].Render();
	}

	for (int iObj = 0; iObj < g_MaxRock; iObj++) {
		m_Rock1_List[iObj].Render();
	}


	m_MouseCursor.Render();


	return true;
}

bool    GameC::Release()  // 소멸, 삭제
{
	
	m_BackGround.Release();
	m_Hero.Release();

	m_statue.Release();

	for (int iObj = 0; iObj < g_MaxMobA; iObj++) {
		m_MobA_List[iObj].Release();
	}

	for (int iObj = 0; iObj < g_MaxRock; iObj++) {
		m_Rock1_List[iObj].Release();
	}

	m_MouseCursor.Release();


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