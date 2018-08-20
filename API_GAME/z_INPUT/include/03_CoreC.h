#pragma once
#include "02_WndC.h"   // - 1�� ����
#include "04_TimerC.h"
#include "05_InputC.h"
#include "07_BmpMgrC.h"  // - 6�� ����

//----------------------------------------------------------------//
//-���� ���� ��� Ŭ������ ������ ������ �ִ� �ٽ� Ŭ���� �Դϴ�.-//
//-������ Ŭ������ ��� �ް�, �Ŵ��� Ŭ������ ��븸 �մϴ�.------//
//-������ Ŭ������ ����� �����ϰ� �ֽ��ϴ�.----------------------//
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