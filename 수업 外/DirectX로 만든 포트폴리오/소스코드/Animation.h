#pragma once

class CSprite;
class CAnimation
{
private: // private ����
	float	m_fOldTime;		// ���� �ð�
	float	m_fCurTime;		// ���� �ð�
	float	m_fFrameTime;	// ������ ����
	int		m_nFrameSize;	// ������ ũ��
	bool	m_bIsFrameLoop;	// ������ ���ѹݺ� ����
public: // public ����
	int		m_nFrameCount;	// ������ ī����
	vector<CSprite*> m_vFrame;
public: // public �Լ�
	CAnimation(void);
	~CAnimation(void);

	void Process(void);
	void Render(void);
	void Release(void);

	// ���ϸ� �Է� �� Ȯ����� �����Ѵ�. (�̹��� �߰� �� F2�� ������ �̸� ������ �����ش�.)
	void CreateAnimation(const char* _filename, float _frameTime, int _frameSize, bool _loop);

	void SetPosition(D3DXVECTOR2 _pos);
	void SetPosition(int _x, int _y);

	void SetRotation(float _rotation);
};

