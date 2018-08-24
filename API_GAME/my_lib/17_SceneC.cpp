#pragma once
#include "17_SceneC.h"

SceneC::SceneC()
{
	m_bNextScene = false;
}

int SceneC::getSceneID()
{
	return m_iSceneID;
}

bool SceneC::getNextScene()
{
	return m_bNextScene;
}


SceneC::~SceneC()
{

}