#include "stdafx.h"
#include "SoundManager.h"


SoundManager::SoundManager(void)
{
	// empty...
}

SoundManager::~SoundManager(void)
{
	// empty...
}

void SoundManager::PlaySoundBG(const char* _filename)
{
	char buf[256];

	sprintf(buf, "open %s type mpegvideo alias A", _filename);

	mciSendString(buf, NULL, NULL, NULL);
	// 무한반복
	mciSendString("play A notify repeat", NULL, NULL, NULL);
}

void SoundManager::PlaySoundEF(const char* _filename)
{
	// 효과음 파일을 재생한다.
	sndPlaySound(_filename, SND_ASYNC);
}