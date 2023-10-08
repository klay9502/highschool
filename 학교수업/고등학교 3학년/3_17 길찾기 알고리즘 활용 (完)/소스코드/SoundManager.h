#pragma once

#define SoundMgr SoundManager::GetInstance()

#include "Singleton.h"

class SoundManager :
	public ISingleton <SoundManager>
{
public:
	SoundManager(void);
	~SoundManager(void);

	void PlaySoundBG(const char* _filename);
	void PlaySoundEF(const char* _filename);
};