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

	//����� ���� �浹
	if (I_ClsMgr.RectInRect(m_Hero.getRtCls(), m_statue.getRtCls())) {
		m_Hero.setMapCls(true, m_statue.getRtCls());
	}

	for (int kObj = 0; kObj < g_MaxRock; kObj++) {
		if (I_ClsMgr.RectInRect(m_Hero.getRtCls(), m_Rock1_List[kObj].getRtCls())) {
			m_Hero.setMapCls(true, m_Rock1_List[kObj].getRtCls());
		}
	}

	//�������� �ʴ� ��1 ����Ʈ���� ����
	for (MobAIt = m_MobA_List.begin(); MobAIt != m_MobA_List.end(); ) {
		if (!MobAIt->getExist()) {
			MobAIt = m_MobA_List.erase(MobAIt);
		}
		else {
			MobAIt++;
		}
	}


	//��1 ���� �浹
	for (MobAIt = m_MobA_List.begin(); MobAIt != m_MobA_List.end(); MobAIt++) {
		//���ΰ��̶� �ε����� ���ΰ��� ����
		if (I_ClsMgr.RectInRect(MobAIt->getRtCls(), m_Hero.getRtCls())) {
			MobAIt->setFSM(0); //FSM�� 0����
			if (g_dGameTimer > 10000000) {
				m_Hero.setExist(false);
				m_bNextScene = true;
			}
		}

		//�ҳ��� ������ �ൿ ���� 1�� ��ȯ
		if (I_ClsMgr.RectInRect(MobAIt->getRtCls(), m_Hero.m_sona.getRtCls())) {
			if (m_Hero.getSonaSw()) {
				MobAIt->setFSM(1);
			}
		}


		//��ֹ��� �ε����� �з���
		if (I_ClsMgr.RectInRect(MobAIt->getRtCls(), m_statue.getRtCls())) {
			MobAIt->setMapCls(true, m_statue.getRtCls());
		}

		for (int kObj = 0; kObj < g_MaxRock; kObj++) {
			if (I_ClsMgr.RectInRect(MobAIt->getRtCls(), m_Rock1_List[kObj].getRtCls())) {
				MobAIt->setMapCls(true, m_Rock1_List[kObj].getRtCls());
			}
		}

		//�Ѿ˰� �ε����� ���� �������� ��
		for (shot1It = m_Hero.shot1_list.begin(); shot1It != m_Hero.shot1_list.end(); shot1It++) {
			if (I_ClsMgr.RectInRect(MobAIt->getRtCls(), shot1It->getRtCls())) {
				if (shot1It->getExist()) {
					MobAIt->setFSM(1); //�ൿ������ 1�� ��ȯ
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

	//shot1 ���� �浹
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

	//�Ƹ��� empty�� ����ִ� ���°� �Ǹ� �� �̻� �������� ���� �ʱ� ������ �����̴� ������ ������.
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