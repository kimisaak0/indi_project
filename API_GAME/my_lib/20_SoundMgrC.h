#pragma once

#pragma comment(lib, "fmod64_vc.lib")

#include "01_header.h"
#include "fmod.h"
#include "fmod.hpp"
#include "fmod_errors.h"

using namespace FMOD;
const int g_iMaxSound = 32;

class SoundMgrC : public SingleMgr<SoundMgrC>
{
	friend class SingleMgr<SoundMgrC>;

protected:
	System*   m_pSystem;
	Sound*    m_pSound[g_iMaxSound];
	Channel*  m_pChannel[g_iMaxSound];

	int       m_iSoundList;
	TCHAR     m_szBuffer[MAX_PATH];

public:
	bool	Init();
	bool	Frame();
	bool	Render();
	bool	Release();


public:
	int     Load(const char* pLoadName, bool bPlay);

	void    Play(int iIndex, bool bPlay = true, bool bLoop = false);
	void    PlayEffect(int iIndex);
	void    Stop(int iIndex);
	void    paused(int iIndex);

	void    Volume(int iIndex, float fVolume, bool bUp);


protected:
	SoundMgrC();
public:
	~SoundMgrC();
};

#define I_SoundMgr SoundMgrC::GetInstance()



