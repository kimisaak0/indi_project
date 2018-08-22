#pragma comment(lib, "core_lib.lib")  //�� ���̺귯���� �߰�.
#include "03_CoreC.h"
#include "12_1_HeroObjC.h"
#include "12_2_MobAC.h"

#define  g_MaxMobA  100


class GameC : public CoreC
{ 
	BgObjC     m_BackGround;
	HeroObjC   m_Hero;

	vector<MobAC>   m_MobA_List;

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

	m_MobA_List.resize(g_MaxMobA);
	for (int iObj = 0; iObj < g_MaxMobA; iObj++) {
		m_MobA_List[iObj].Load(L"../z_INPUT/data/50x50/bat.bmp");
		m_MobA_List[iObj].Set(rand() % (g_rtClient.right - 200) + 100, rand() % (g_rtClient.bottom - 200) + 100 , 0, 0, 32, 32);
		//m_MobA_List[iObj].Set(0,0, 0, 0, 32, 32);

	}
	
	return true;
}


bool    GameC::Frame()	 // ���
{
	m_BackGround.Frame();
	m_Hero.Frame();

	for (int iObj = 0; iObj < g_MaxMobA; iObj++) {
		m_MobA_List[iObj].Frame();
	}
	return true;
}

bool    GameC::Render() 	 // ��ο�
{
	m_BackGround.Render();
	m_Hero.Render();

	for (int iObj = 0; iObj < g_MaxMobA; iObj++) {
		m_MobA_List[iObj].Render();
	}

	return true;
}

bool    GameC::Release()  // �Ҹ�, ����
{
	m_BackGround.Release();
	m_Hero.Release();

	for (int iObj = 0; iObj < g_MaxMobA; iObj++) {
		m_MobA_List[iObj].Release();
	}


	return true;

}

HINSTANCE g_hInst;

//������ ������ ������ Ŭ����ȭ ��Ŵ
//TODO : ������ �����츦 �����ϴ� �Ŵ��� Ŭ���� �ʿ�.

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//���α׷� �ڵ��� ���������� ����
	g_hInst = hInst;

	GameC GameWnd(L"GameWindow");

	GameWnd.runWindow();

}