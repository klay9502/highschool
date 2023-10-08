#pragma once

#include "PacketDefine.h"
#include "Singleton.h"

#define BUF_SIZE 1024

class CStream :
	public ISingleton<CStream>
{
public:
	CStream();
	virtual ~CStream();

public :
	int m_BufferReadPoint;
	int m_BufferWritePoint;
	int m_BufferSize;
	char* m_RecvBuffer;
	char* m_SendBuffer;
	
public :

	void SetBuffer(int iBufferSize);
	void ReleaseBuffer();

	BOOL WriteChar(char Data);
	BOOL WriteChars(char* Data, int ValueSize);
	BOOL WriteBool(bool Data);
	BOOL WriteShort(short Data);
	BOOL WriteInt(int Data);
	BOOL WriteDWORD(DWORD Data);
	BOOL WriteFloat(float Data);
	BOOL WriteLong(long Data);
	BOOL WriteDouble(double Data);
	BOOL WriteProtocol(ePakcet_Protocol Data);

	BOOL ReadChar(char* Data);
	BOOL ReadChars(char* Data, int ValueSize);
	BOOL ReadBool(bool* Data);
	BOOL ReadShort(short* Data);
	BOOL ReadInt(int* Data);
	BOOL ReadDWORD(DWORD* Data);
	BOOL ReadFloat(float* Data);
	BOOL ReadLong(long* Data);
	BOOL ReadDouble(double* Data);
	BOOL ReadProtocol(ePakcet_Protocol* Data);

	void ResetSendPoint();
	void ResetRecvPoint();
	void ClearSendBuffer();
	void ClearRecvBuffer();

	int GetBufferSize();
};

#define g_pBufferManager CStream::GetInstance()