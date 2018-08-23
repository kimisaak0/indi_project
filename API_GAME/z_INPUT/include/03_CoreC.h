#pragma once
#include "02_WndC.h"   // - 1�� ����
#include "04_TimerC.h"
#include "05_InputC.h"
#include "07_BmpMgrC.h"  // - 6�� ����
#include "09_1_BgObjC.h" // - 8�� ����
#include "10_CollisionC.h"
#include "12_1_HeroObjC.h" // - 11�� ����
#include "12_2_MobAC.h"
#include "13_1MouseObjC.h"

//----------------------------------------------------------------//
//-���� ���� ��� Ŭ������ ������ ������ �ִ� �ٽ� Ŭ���� �Դϴ�.-//
//-������ Ŭ������ ��� �ް�, �Ŵ��� Ŭ������ ��븸 �մϴ�.------//
//-������ Ŭ������ ����� �����ϰ� �ֽ��ϴ�.----------------------//
//----------------------------------------------------------------//

class CoreC : public WndC
{

protected:
	HDC     m_hOnScreenDC;
	HDC     m_hOffScreenDC;
	HBITMAP m_hOffBmp;
	HBRUSH  m_hBrBack;

	bool    m_TimerSw;

public:
	bool    gameInit() override;
	bool    gameRun()  override;            
	bool    gameFrame()  override;
	bool    gameRender()  override;
	bool    gameRelease()  override;

public:
	bool    GamePreRender();
	bool    GamePostRender();

public:
	virtual bool    Init() 
	{
	/*	m_BackGround.Load(L"../z_INPUT/data/50x50/watar_tileset.bmp");
		m_BackGround.Set(0, 0, 0, 0, 50, 50);*/
		return true;
	}      // �ʱ�ȭ


	virtual bool    Frame() 
	{

		//m_BackGround.Frame(); 
		return true;
	};	 // ���
	virtual bool    Render() { 
		
		//m_BackGround.Render(); 
		return true;
	};	 // ��ο�
	virtual bool    Release() { 
		
		//m_BackGround.Release();
		return true;
	};	 // �Ҹ�, ����

public:
	CoreC(LPCWSTR LWndName);
	virtual ~CoreC();
};