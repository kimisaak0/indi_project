#pragma once
#include "08_ObjC.h"

class BgObjC : public ObjC
{
protected:
	double m_dAlpha;

public:

	int    m_iID;


	bool FadeIn();
	bool FadeOut();

	bool Render() override;

public:
	BgObjC();
	virtual ~BgObjC();
};

