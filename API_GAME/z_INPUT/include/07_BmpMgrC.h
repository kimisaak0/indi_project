#pragma once
#include "06_BmpC.h"

struct BmpNameTag
{
	//int      iBmpKey;
	T_STR    szBmpName;
	BmpC*    pBmpData;
};

class BmpMgrC : public SingleMgr<BmpMgrC>
{
	friend class SingleMgr<BmpMgrC>;

private:
	//int            m_iIndex;

	list<BmpNameTag> m_BmpList;

public:

	void     addBmp(T_STR szName, BmpC* pData);
	
	//BmpC*    getBmp(int iKey);
	BmpC*    getBmp(T_STR szName);

protected:
	BmpMgrC();

public:
	virtual ~BmpMgrC();

};

#define I_Bmp BmpMgrC::GetInstance()