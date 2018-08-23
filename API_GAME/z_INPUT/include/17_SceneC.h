#pragma once
#include "16_ButtonC.h"
#include "09_1_BgObjC.h"

class SceneC
{
protected:
	int   m_iSceneID;
	bool  m_bNextScene;

	BgObjC m_BackGround;
public:
	int getSceneID();

public:
	SceneC();
	virtual ~SceneC();

};