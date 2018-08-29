#pragma once
#include "12_3_MapObjC.h"

class StatueMOC : public MapObjC
{
private:
	int m_iHP;

public:
	int Hit();

public:
	bool Frame() override;
	bool Render() override;

public:
	StatueMOC();
};