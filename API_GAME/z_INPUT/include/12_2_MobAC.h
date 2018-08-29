#pragma once
#include "11_CollisionObjC.h"

class MobAC : public CollisionObjC
{
protected:
	static int  g_maxId;
	int         m_iId;

	int         m_iMaxHp;           //최대 HP
	int         m_iCurrentHP;       //현재 HP

	double      m_dSpriteSpeed;    //스프라이트 속도
//	int         m_iSpriteIndex;

	double      m_dDirChg;         //이게 차면 이동방향을 바꿈
	double      m_dMoveCycleSpeed; //이동 방향을 바꾸는 주기

	int         m_iFSMid;

	dPointC     m_ptDest;

public:
	bool Init() override;
	bool Frame() override;
	bool Render() override;

	dPointC getPt();

	int Hit();

	void setFSM(int id);
	void setDest(dPointC pt);

public:
	MobAC();
	virtual ~MobAC();
};