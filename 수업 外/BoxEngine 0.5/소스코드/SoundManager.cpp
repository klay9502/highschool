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
	// ���ѹݺ�
	mciSendString("play A notify repeat", NULL, NULL, NULL);
}

void SoundManager::PlaySoundEF(const char* _filename)
{
	// ȿ���� ������ ����Ѵ�.
	sndPlaySound(_filename, SND_ASYNC);
}