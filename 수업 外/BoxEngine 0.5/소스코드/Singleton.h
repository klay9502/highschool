#pragma once

template <class T>

class ISingleton
{
private:
	static T* m_Instance;
public:
	ISingleton(void) { /* empty */ };
	~ISingleton(void) { delete m_Instance; };

	static T* GetInstance(void)
	{
		if (m_Instance == NULL)
		{
			m_Instance = new T();
		}
		return m_Instance;
	}
};

template <class T> T* ISingleton<T>::m_Instance = 0;