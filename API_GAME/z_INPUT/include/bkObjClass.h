#pragma once
#include "ObjClass.h"
class bkObjClass :	public objClass
{
public:
	bool Render() override;

public:
	bkObjClass();
	virtual ~bkObjClass();
};

