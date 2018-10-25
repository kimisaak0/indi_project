#pragma once
#include "18_3_SceneOverC.h"

SceneOverC::SceneOverC()
{
	
}

bool	SceneOverC::Init()
{
	m_iSceneID = 2;
	m_iNextSceneID = 2;

	m_bNextScene = false;

	m_BackGround.Init();
	m_BackGround.Load(L"../z_INPUT/data/50x50/Over.bmp");
	m_BackGround.Set(g_rtClient.right / 2, g_rtClient.bottom / 2, 0, 0, 800, 600);

	m_btnMain.Init();
	m_btnMain.Load(L"../z_INPUT/data/50x50/MainBtn.bmp");
	m_btnMain.Set(500, 900, 0, 0, 334, 82);

	m_btnContinue.Init();
	m_btnContinue.Load(L"../z_INPUT/data/50x50/ContinueBtn.bmp");
	m_btnContinue.Set(1000, 900, 0, 0, 334, 82);

	return true;
}

bool	SceneOverC::Frame()
{
	m_BackGround.Frame();

	if (I_ClsMgr.RectInPt(m_btnMain.getRtCls(), I_Input.m_MousePos)) {
		m_btnMain.Set(g_rtClient.left + 200, g_rtClient.bottom - 100, 0, 100, 334, 82);
		if (I_Input.Key(VK_LBUTTON)) {
			m_btnMain.Set(g_rtClient.left + 200, g_rtClient.bottom - 100, 0, 200, 334, 82);
			I_SoundMgr.PlayEffect(0);
			m_bNextScene = true;
			m_iNextSceneID = 0;
		}
	}
	else {
		m_btnMain.Set(g_rtClient.left + 200, g_rtClient.bottom - 100, 0, 0, 334, 82);
	}

	if (I_ClsMgr.RectInPt(m_btnContinue.getRtCls(), I_Input.m_MousePos)) {
		m_btnContinue.Set(g_rtClient.right - 600, g_rtClient.bottom - 100, 0, 100, 334, 82);
		if (I_Input.Key(VK_LBUTTON)) {
			m_btnContinue.Set(g_rtClient.right - 600, g_rtClient.bottom - 100, 0, 200, 334, 82);
			I_SoundMgr.PlayEffect(0);
			m_bNextScene = true;
			m_iNextSceneID = 1;
		}
	}
	else {
		m_btnContinue.Set(g_rtClient.right - 600, g_rtClient.bottom - 100, 0, 0, 334, 82);
	}

	return true;
}

bool	SceneOverC::Render()
{
	if (m_BackGround.m_iID == 1) {
		m_BackGround.m_iID = 0;
		Init();
	}


	m_BackGround.Render();
	m_btnMain.Render();
	m_btnContinue.Render();

	return true;
}

bool	SceneOverC::Release()
{
	m_BackGround.Release();
	m_btnMain.Release();
	m_btnContinue.Release();

	return true;
}

SceneOverC::~SceneOverC()
{

}