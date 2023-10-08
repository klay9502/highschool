#pragma once

class CSystem
{
public: // public �Լ�
	CSystem(void);
	~CSystem(void);

	void Init(void);
	void MessageLoop(void);
	void Process(void);
	void Render(void);
	void Release(void);
};

