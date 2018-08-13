#pragma once
#include "WndC.h"
#include "TimerC.h"

class CoreC : public WndC
{
private:
	HDC     m_hOnScreenDC;
	HDC     m_hOffScreenDC;

private:
	TimerC  m_Timer;

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
	HDC     getOnDC();
	HDC     getOffDC();

public:
	CoreC(LPCWSTR LWndName);
	virtual ~CoreC();
};