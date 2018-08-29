#pragma once
#include "11_CollisionObjC.h"

class MobAC : public CollisionObjC
{
protected:
	static int  g_maxId;
	int         m_iId;

	int         m_iMaxHp;           //�ִ� HP
	int         m_iCurrentHP;       //���� HP

	double      m_dSpriteSpeed;    //��������Ʈ �ӵ�
//	int         m_iSpriteIndex;

	double      m_dDirChg;         //�̰� ���� �̵������� �ٲ�
	double      m_dMoveCycleSpeed; //�̵� ������ �ٲٴ� �ֱ�

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