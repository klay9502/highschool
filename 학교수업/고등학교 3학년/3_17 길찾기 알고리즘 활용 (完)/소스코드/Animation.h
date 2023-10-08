#pragma once

class CSprite;
class CAnimation
{
private: // private 변수
	float	m_fOldTime;		// 과거 시간
	float	m_fCurTime;		// 현재 시간
	float	m_fFrameTime;	// 프레임 간격
	int		m_nFrameSize;	// 프레임 크기
	bool	m_bIsFrameLoop;	// 프레임 무한반복 유무
public: // public 변수
	int		m_nFrameCount;	// 프레임 카운터
	vector<CSprite*> m_vFrame;
public: // public 함수
	CAnimation(void);
	~CAnimation(void);

	void Process(void);
	void Render(void);
	void Release(void);

	// 파일명 입력 시 확장명을 제외한다. (이미지 추가 시 F2를 눌러서 이름 통일을 시켜준다.)
	void CreateAnimation(const char* _filename, float _frameTime, int _frameSize, bool _loop);

	void SetPosition(D3DXVECTOR2 _pos);
	void SetPosition(int _x, int _y);

	void SetRotation(float _rotation);
};

