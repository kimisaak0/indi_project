#pragma comment(lib, "core_lib.lib")  //�� ���̺귯���� �߰�.
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

	bool    Frame()	 // ���
	{
		/*m_BackGround.Frame();*/
		//m_Hero.Frame();
		return true;
	}

	bool    Render() 	 // ��ο�
	{
		/*m_BackGround.Render();*/
		//m_Hero.Render();

		return true;
	}

	bool    Release()  // �Ҹ�, ����
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

//������ ������ ������ Ŭ����ȭ ��Ŵ
//TODO : ������ �����츦 �����ϴ� �Ŵ��� Ŭ���� �ʿ�.

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//���α׷� �ڵ��� ���������� ����
	g_hInst = hInst;

	GameC GameWnd(L"GameWindow");

	GameWnd.runWindow();

}