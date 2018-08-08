#include "core.h"

class game : public core
{
	
	bkObjClass m_BackGround;
	heroClass  m_Hero;



public:
	bool Init()
	{
		m_BackGround.Load(L"../z_INPUT/data/50x50/watar_tileset.bmp");
		m_BackGround.Set(0, 0, 102, 0, 50, 50);

		m_Hero.Load(L"../z_INPUT/data/50x50/Shipedits.bmp");
		m_Hero.Set(300, 300, 0, 0, 32, 30);


		return true;
	}

	bool Frame()
	{
		m_BackGround.Frame();
		m_Hero.Frame();
		return true;
	}
	bool Render()
	{
		m_BackGround.Render();
		m_Hero.Render();

		return true;
	}

	bool Release()
	{
		m_BackGround.Release();
		m_Hero.Release();

		return true;

	}

public:
	game() {}
	~game() {}
};

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR   lpCmdLine, int   nCmdShow) {

	game win;
	win.SetWindow(hInst, L"WidnowClass", 800, 600);
	win.Run();
}
