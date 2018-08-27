#pragma once
#include "17_SceneC.h"

class SceneOverC : public SceneC
{
protected:
	BgObjC m_BackGround;

	ButtonC m_btnMain;
	ButtonC m_btnContinue;

public:
	virtual bool	Init();
	virtual bool	Frame();
	virtual bool	Render();
	virtual bool	Release();

public:
	SceneOverC();
	~SceneOverC();
};