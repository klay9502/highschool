#pragma once

#include "Scene.h"

class S_NULL :
	public CScene
{
public:
	S_NULL(void);
	~S_NULL(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;
};

