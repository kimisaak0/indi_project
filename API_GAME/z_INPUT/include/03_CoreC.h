#pragma once
#include "02_WndC.h"   // - 1번 포함
#include "04_TimerC.h"
#include "05_InputC.h"
#include "07_BmpMgrC.h"  // - 6번 포함
#include "09_1_BgObjC.h" // - 8번 포함
#include "10_CollisionC.h"
#include "12_1_HeroObjC.h" // - 11번 포함
#include "12_2_MobAC.h"
#include "13_1MouseObjC.h"

//----------------------------------------------------------------//
//-현재 만든 모든 클래스의 정보를 가지고 있는 핵심 클래스 입니다.-//
//-윈도우 클래스를 상속 받고, 매니저 클래스는 사용만 합니다.------//
//-나머지 클래스는 멤버로 포함하고 있습니다.----------------------//
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
	}      // 초기화


	virtual bool    Frame() 
	{

		//m_BackGround.Frame(); 
		return true;
	};	 // 계산
	virtual bool    Render() { 
		
		//m_BackGround.Render(); 
		return true;
	};	 // 드로우
	virtual bool    Release() { 
		
		//m_BackGround.Release();
		return true;
	};	 // 소멸, 삭제

public:
	CoreC(LPCWSTR LWndName);
	virtual ~CoreC();
};