#pragma once
#include "18_1_SceneLobbyC.h"

SceneLobbyC::SceneLobbyC()
{

}

bool	SceneLobbyC::Init()
{
	m_iSceneID = 0;
	m_iNextSceneID = 0;

	m_bNextScene = false;



	m_BackGround.Init();
	m_BackGround.Load(L"../z_INPUT/data/50x50/start.bmp");
	m_BackGround.Set(g_rtClient.right / 2, g_rtClient.bottom / 2, 0, 0, 800, 600);

	m_btnStart.Init();
	m_btnStart.Load(L"../z_INPUT/data/50x50/btn.bmp");
	m_btnStart.Set(g_rtClient.right / 2, g_rtClient.bottom / 2, 0, 0, 334, 82);

	return true;
}

bool	SceneLobbyC::Frame()
{
	m_BackGround.Frame();

	if (I_ClsMgr.RectInPt(m_btnStart.getRtCls(), I_Input.m_MousePos)) {
		m_btnStart.Set(g_rtClient.right / 2, g_rtClient.bottom / 2, 0, 100, 334, 82);
		if (I_Input.Key(VK_LBUTTON)) {
			m_btnStart.Set(g_rtClient.right / 2, g_rtClient.bottom / 2, 0, 200, 334, 82);
			m_bNextScene = true;
		}
	}
	else {
		m_btnStart.Set(g_rtClient.right / 2, g_rtClient.bottom / 2, 0, 0, 334, 82);
	}

	return true;
}

bool	SceneLobbyC::Render()
{
	if (m_BackGround.m_iID == 1) {
		m_BackGround.m_iID = 0;
		Init();
	}

	m_BackGround.Render();
	m_btnStart.Render();

	return true;
}

bool	SceneLobbyC::Release()
{
	m_BackGround.Release();
	m_btnStart.Release();

	return true;
}

SceneLobbyC::~SceneLobbyC()
{

}