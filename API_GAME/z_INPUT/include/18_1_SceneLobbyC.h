#pragma once
#include "17_SceneC.h"

class SceneLobbyC : public SceneC
{
protected:
	BgObjC m_BackGround;

	ButtonC m_btnStart;

public:
	virtual bool	Init();
	virtual bool	Frame();
	virtual bool	Render();
	virtual bool	Release();

public:
	SceneLobbyC();
	~SceneLobbyC();
};