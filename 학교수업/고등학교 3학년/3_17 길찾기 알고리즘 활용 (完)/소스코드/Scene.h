#pragma once

class CScene
{
public:
	CScene(void);
	~CScene(void);

	// ���� �����Լ�
	virtual void Init(void)		= 0;
	virtual void Process(void)	= 0;
	virtual void Render(void)	= 0;
	virtual void Release(void)	= 0;

	void PreRender(void);
	void PostRender(void);
};

