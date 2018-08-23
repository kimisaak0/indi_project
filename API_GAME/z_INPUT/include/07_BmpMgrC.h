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
	//list<HBITMAP>    m_ReleaseList;

private:
	BmpC*    addBmp(T_STR szName);
	BmpC*    getBmp(T_STR szName);
	//BmpC*    getBmp(int iKey);

public:
	BmpC*     loadBmp(T_STR szName);

protected:
	BmpMgrC();

public:
	virtual ~BmpMgrC();

};

#define I_Bmp BmpMgrC::GetInstance()