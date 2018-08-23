#pragma once
#include "08_ObjC.h"

class MouseObjC : public ObjC
{
private:
	POINT m_MousePos;

public:
	void Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom) override;

	bool Frame() override;
	bool Render() override;


public:
	MouseObjC();
	virtual ~MouseObjC();
};