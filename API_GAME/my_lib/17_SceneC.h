#pragma once
#include "16_ButtonC.h"
#include "09_1_BgObjC.h"
#include "10_CollisionC.h"
#include "04_TimerC.h"

class SceneC
{
protected:
	int   m_iSceneID;
	bool  m_bNextScene;
	int   m_iNextSceneID;

public:
	int getSceneID();
	bool getNextScene();
	int getNextSceneID();

public:
	virtual bool	Init() { return true; };
	virtual bool	Frame() { return true; };
	virtual bool	Render() { return true; };
	virtual bool	Release() { return true; };

public:
	 SceneC();
	virtual ~SceneC();

};