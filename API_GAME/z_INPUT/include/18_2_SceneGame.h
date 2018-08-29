#pragma once
#include "17_SceneC.h"

#include "12_1_HeroObjC.h"
#include "12_2_MobAC.h"
#include "13_1MouseObjC.h"
#include "14_1_StatueMOC.h"
#include "14_2_Rock1MOC.h"

#include "19_1_SpriteDead1C.h"

class SceneGame : public SceneC
{
protected:
	BgObjC     m_BackGround;

	StatueMOC    m_statue;
	vector<Rock1MOC>    m_Rock1_List;

	HeroObjC   m_Hero;
	list<MobAC>   m_MobA_List;

	list<dPointC> m_Effect_pos;

public:
	virtual bool	Init();
	virtual bool	Frame();
	virtual bool	Render();
	virtual bool	Release();

public:
	SceneGame();
	~SceneGame();
};