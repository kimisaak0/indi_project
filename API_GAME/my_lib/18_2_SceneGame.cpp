#pragma once
#include "18_2_SceneGame.h"

SceneGame::SceneGame()
{

}

bool	SceneGame::Init()
{
	m_iSceneID = 1;
	m_iNextSceneID = 1;
	g_dGameTimer = 0;
	
	I_Timer.Init();

	m_bNextScene = false;

	srand((unsigned)GetTickCount());

	I_SoundMgr.Play(3, true, true);

	m_BackGround.Load(L"../z_INPUT/data/50x50/watar_tileset.bmp");
	m_BackGround.Set(0, 0, 0, 0, 50, 50);

	m_statue.Load(L"../z_INPUT/data/50x50/Statue.bmp");
	m_statue.Set(800, 300, 0, 0, 135, 160);

	m_Hero.Load(L"../z_INPUT/data/50x50/Shipedits.bmp");
	m_Hero.Set(300, 300, 0, 0, 32, 30);
	m_Hero.Init();

	list<MobAC>::iterator MobAIt;

	for (MobAIt = m_MobA_List.begin(); MobAIt != m_MobA_List.end(); ) {
			MobAIt = m_MobA_List.erase(MobAIt);
	}

	for (int iObj = 0; iObj < g_MaxMobA; iObj++) {
		MobAC mobATemp;
		mobATemp.Load(L"../z_INPUT/data/50x50/bat.bmp");
		mobATemp.Set(rand() % (g_rtClient.right - 200) + 100, rand() % (g_rtClient.bottom - 200) + 100, 0, 0, 32, 32);
		mobATemp.Init();
		m_MobA_List.push_back(mobATemp);
		//m_MobA_List[iObj].Set(0,0, 0, 0, 32, 32);
	}

	m_Rock1_List.resize(g_MaxRock);
	for (int iObj = 0; iObj < g_MaxRock; iObj++) {
		m_Rock1_List[iObj].Load(L"../z_INPUT/data/50x50/Rock.bmp");
		m_Rock1_List[iObj].Set(rand() % (g_rtClient.right - 200) + 100, rand() % (g_rtClient.bottom - 200) + 100, 21, 7, 48, 48);
	}


	EffectC* DeadEffect = new SpriteDead1C;
	DeadEffect->Load(L"../z_INPUT/data/50x50/explosion01.bmp");
	DeadEffect->Set(0, 0, 0, 0, 150, 150);
	
	I_EffectMgr.Load(DeadEffect);

	return true;
}

bool	SceneGame::Frame()
{
	m_BackGround.Frame();
	m_Hero.Frame();

	m_statue.Frame();

	list<MobAC>::iterator MobAIt;
	list<shot1C>::iterator shot1It;

	for (MobAIt = m_MobA_List.begin(); MobAIt != m_MobA_List.end(); MobAIt++) {
		MobAIt->Frame();
	}


	for (int iObj = 0; iObj < g_MaxRock; iObj++) {
		m_Rock1_List[iObj].setMapCls(true, m_Rock1_List[iObj].getRtCls());
	}

	//히어로 관련 충돌
	if (I_ClsMgr.RectInRect(m_Hero.getRtCls(), m_statue.getRtCls())) {
		m_Hero.setMapCls(true, m_statue.getRtCls());
	}

	for (int kObj = 0; kObj < g_MaxRock; kObj++) {
		if (I_ClsMgr.RectInRect(m_Hero.getRtCls(), m_Rock1_List[kObj].getRtCls())) {
			m_Hero.setMapCls(true, m_Rock1_List[kObj].getRtCls());
		}
	}

	//존재하지 않는 몹1 리스트에서 제거
	for (MobAIt = m_MobA_List.begin(); MobAIt != m_MobA_List.end(); ) {
		if (!MobAIt->getExist()) {
			MobAIt = m_MobA_List.erase(MobAIt);
		}
		else {
			MobAIt++;
		}
	}


	//몹1 관련 충돌
	for (MobAIt = m_MobA_List.begin(); MobAIt != m_MobA_List.end(); MobAIt++) {
		//주인공이랑 부딪히면 주인공이 다이
		if (I_ClsMgr.RectInRect(MobAIt->getRtCls(), m_Hero.getRtCls())) {
			MobAIt->setFSM(0); //FSM은 0으로
			if (g_dGameTimer > 10000000) {
				m_Hero.setExist(false);
				m_bNextScene = true;
			}
		}

		//소나를 맞으면 행동 패턴 1로 변환
		if (I_ClsMgr.RectInRect(MobAIt->getRtCls(), m_Hero.m_sona.getRtCls())) {
			if (m_Hero.getSonaSw()) {
				MobAIt->setFSM(1);
			}
		}


		//장애물과 부딪히면 밀려남
		if (I_ClsMgr.RectInRect(MobAIt->getRtCls(), m_statue.getRtCls())) {
			MobAIt->setMapCls(true, m_statue.getRtCls());
		}

		for (int kObj = 0; kObj < g_MaxRock; kObj++) {
			if (I_ClsMgr.RectInRect(MobAIt->getRtCls(), m_Rock1_List[kObj].getRtCls())) {
				MobAIt->setMapCls(true, m_Rock1_List[kObj].getRtCls());
			}
		}

		//총알과 부딪히면 몹의 에너지가 담
		for (shot1It = m_Hero.shot1_list.begin(); shot1It != m_Hero.shot1_list.end(); shot1It++) {
			if (I_ClsMgr.RectInRect(MobAIt->getRtCls(), shot1It->getRtCls())) {
				if (shot1It->getExist()) {
					MobAIt->setFSM(1); //행동패턴은 1로 변환
					I_SoundMgr.PlayEffect(2);
					MobAIt->Hit();
					MobAIt->setDest(shot1It->getSpawn());

					dPointC pos;
					pos.x = MobAIt->getPt().x;
					pos.y = MobAIt->getPt().y;
					m_Effect_pos.push_back(pos);
				}
			}
		}


	}

	//shot1 관련 충돌
	for (shot1It = m_Hero.shot1_list.begin(); shot1It != m_Hero.shot1_list.end(); shot1It++) {
		for (MobAIt = m_MobA_List.begin(); MobAIt != m_MobA_List.end(); MobAIt++) {
			if (I_ClsMgr.RectInRect(shot1It->getRtCls(), MobAIt->getRtCls())) {
				shot1It->setExist(false);
			}
		}

		if (m_statue.getExist()) {
			if (I_ClsMgr.RectInRect(shot1It->getRtCls(), m_statue.getRtCls())) {
				shot1It->setExist(false);
				m_statue.Hit();
			}
		}

		for (int kObj = 0; kObj < g_MaxRock; kObj++) {
			if (I_ClsMgr.RectInRect(shot1It->getRtCls(), m_Rock1_List[kObj].getRtCls())) {
				//shot1It->setExist(false);
			}
		}

	}



	return true;
}

bool	SceneGame::Render()
{
	if (m_BackGround.m_iID == 0) {
		m_BackGround.m_iID = 1;
		Init();
	}

	m_BackGround.Render();
	m_Hero.Render();

	m_statue.Render();

	list<MobAC>::iterator MobAIt;
	for (MobAIt = m_MobA_List.begin(); MobAIt != m_MobA_List.end(); MobAIt++) {
		MobAIt->Render();
	}

	for (int iObj = 0; iObj < g_MaxRock; iObj++) {
		m_Rock1_List[iObj].Render();
	}

	//아마도 empty가 비어있는 상태가 되면 더 이상 렌더링을 하지 않기 때문에 깜빡이는 것으로 생각됨.
	if (!m_Effect_pos.empty()) {
		double x = m_Effect_pos.front().x;
		double y = m_Effect_pos.front().y;
		I_EffectMgr.Play(0, x, y);

		m_Effect_pos.pop_front();
	}

	return true;
}

bool	SceneGame::Release()
{
	

	m_BackGround.Release();
	m_Hero.Release();

	m_statue.Release();

	list<MobAC>::iterator MobAIt;
	for (MobAIt = m_MobA_List.begin(); MobAIt != m_MobA_List.end(); MobAIt++) {
		MobAIt->Release();
	}

	for (int iObj = 0; iObj < g_MaxRock; iObj++) {
		m_Rock1_List[iObj].Release();
	}

	return true;
}


SceneGame::~SceneGame()
{

}