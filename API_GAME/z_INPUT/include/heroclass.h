#pragma once
#include "ObjClass.h"
#include "shot1.h"

class heroClass :
	public objClass
{

public:
	bool Frame() override;
	bool Render() override;

public:
	heroClass();
	virtual ~heroClass();
};
