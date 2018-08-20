#pragma once
#include "02_WndC.h"   // - 1번 포함
#include "04_TimerC.h"
#include "05_InputC.h"
#include "07_BmpMgrC.h"  // - 6번 포함

//----------------------------------------------------------------//
//-현재 만든 모든 클래스의 정보를 가지고 있는 핵심 클래스 입니다.-//
//-윈도우 클래스를 상속 받고, 매니저 클래스는 사용만 합니다.------//
//-나머지 클래스는 멤버로 포함하고 있습니다.----------------------//
//----------------------------------------------------------------//

class CoreC : public WndC
{
	//bool sw;


protected:
	HDC     m_hOnScreenDC;
	HDC     m_hOffScreenDC;


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
	//HDC     getOnDC();
	//HDC     getOffDC();

public:
	CoreC(LPCWSTR LWndName);
	virtual ~CoreC();
};