#pragma once

typedef struct tagTimer
{
	int nCount;
	int nFPS;
	int nSec;
	int nTheta;
	double dStartTime;
	double dTime;
	double oldTime;
}Timer;

Timer* InitTimer();

void ProcessTimer(Timer* pT);

void ReleaseTimer(Timer* pT);