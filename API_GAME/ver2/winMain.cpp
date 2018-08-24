#pragma comment(lib, "core_lib.lib")  //이 라이브러리를 추가.
#include "03_CoreC.h"

#include "18_1_SceneLobbyC.h"
#include "18_2_SceneGame.h"




class GameC : public CoreC
{ 

	MouseObjC  m_MouseCursor;

	SceneC*    m_pScene;

	SceneC*    m_pLobby;
	SceneC*    m_pGame;

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
	m_MouseCursor.Load(L"../z_INPUT/data/50x50/CursorImage.bmp");
	m_MouseCursor.Set(0, 0, 0, 0, 200, 200);

	m_pLobby = new SceneLobbyC;
	m_pGame = new SceneGame;
	
	m_pScene = m_pLobby;

	switch (m_pScene->getSceneID()) {
		case 0: {
			//m_pScene->m_BackGround.m_iID = 0;
		} break;
			
		case 1: {
		}break;
	}
	
	m_pScene->Init();
	return true;
}


bool    GameC::Frame()	 // 계산
{
	
	switch (m_pScene->getSceneID()) {
		case 0: {
			if (m_pScene->getNextScene()) {
				m_pScene = m_pGame;
				m_pScene->Init();
				//m_pScene->m_BackGround.m_iID = 1;

			}
		} break;

		case 1: {
			
		}break;
	}

	m_pScene->Frame();
	m_MouseCursor.Frame();

	return true;
}

bool    GameC::Render() 	 // 드로우
{

	m_pScene->Render();
	m_MouseCursor.Render();

	return true;
}

bool    GameC::Release()  // 소멸, 삭제
{

	m_pScene->Frame();
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