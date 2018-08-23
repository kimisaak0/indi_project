#pragma once
#include "08_ObjC.h"

class UIObjC : public ObjC 
{
public:
	void Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom);

	bool Frame() override;
	bool Render() override;

public:
	UIObjC();
	virtual ~UIObjC();
};