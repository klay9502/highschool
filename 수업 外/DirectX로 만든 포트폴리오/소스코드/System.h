#pragma once

class CSystem
{
public: // public ÇÔ¼ö
	CSystem(void);
	~CSystem(void);

	void Init(void);
	void MessageLoop(void);
	void Process(void);
	void Render(void);
	void Release(void);
};

