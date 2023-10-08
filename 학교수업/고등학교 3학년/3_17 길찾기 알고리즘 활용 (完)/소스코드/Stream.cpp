#include "stdafx.h"

CStream::CStream()
{
	m_BufferReadPoint = 0;
	m_BufferWritePoint = 0;
}


CStream::~CStream()
{
}

void CStream::SetBuffer(int iBufferSize)
{
	m_BufferSize = iBufferSize;

	m_RecvBuffer = new char[iBufferSize];
	m_SendBuffer = new char[iBufferSize];

	ZeroMemory(m_RecvBuffer, iBufferSize);
	ZeroMemory(m_SendBuffer, iBufferSize);
}

void CStream::ClearSendBuffer()
{
	ZeroMemory(m_SendBuffer, m_BufferSize);
}

void CStream::ClearRecvBuffer()
{
	ZeroMemory(m_RecvBuffer, m_BufferSize);
}

int CStream::GetBufferSize()
{
	return m_BufferSize;
}

void CStream::ReleaseBuffer()
{
	delete[] m_RecvBuffer;
	delete[] m_SendBuffer;
}

BOOL CStream::WriteChar(char Data)
{
	memcpy(m_SendBuffer + m_BufferWritePoint, &Data, sizeof(char));

	m_BufferWritePoint += sizeof(char);

	return TRUE;
}

BOOL CStream::WriteChars(char* Data, int ValueSize)
{
	memcpy(m_SendBuffer + m_BufferWritePoint, Data, ValueSize);

	m_BufferWritePoint += ValueSize;

	return TRUE;
}

BOOL CStream::WriteBool(bool Data)
{
	memcpy(m_SendBuffer + m_BufferWritePoint, &Data, sizeof(bool));

	m_BufferWritePoint += sizeof(bool);

	return TRUE;
}

BOOL CStream::WriteShort(short Data)
{
	memcpy(m_SendBuffer + m_BufferWritePoint, &Data, sizeof(short));

	m_BufferWritePoint += sizeof(short);

	return TRUE;
}

BOOL CStream::WriteInt(int Data)
{
	memcpy(m_SendBuffer + m_BufferWritePoint, &Data, sizeof(int));

	m_BufferWritePoint += sizeof(int);

	return TRUE;
}

BOOL CStream::WriteDWORD(DWORD Data)
{
	memcpy(m_SendBuffer + m_BufferWritePoint, &Data, sizeof(DWORD));

	m_BufferWritePoint += sizeof(DWORD);

	return TRUE;
}

BOOL CStream::WriteLong(long Data)
{
	memcpy(m_SendBuffer + m_BufferWritePoint, &Data, sizeof(long));

	m_BufferWritePoint += sizeof(long);

	return TRUE;
}

BOOL CStream::WriteFloat(float Data)
{
	memcpy(m_SendBuffer + m_BufferWritePoint, &Data, sizeof(float));

	m_BufferWritePoint += sizeof(float);

	return TRUE;
}

BOOL CStream::WriteDouble(double Data)
{
	memcpy(m_SendBuffer + m_BufferWritePoint, &Data, sizeof(double));

	m_BufferWritePoint += sizeof(double);

	return TRUE;
}

BOOL CStream::WriteProtocol(ePakcet_Protocol Data)
{
	memcpy(m_SendBuffer + m_BufferWritePoint, &Data, sizeof(ePakcet_Protocol));

	m_BufferWritePoint += sizeof(ePakcet_Protocol);

	return TRUE;
}

BOOL CStream::ReadChar(char* Data)
{
	memcpy(Data, m_RecvBuffer + m_BufferReadPoint, sizeof(char));

	m_BufferReadPoint += sizeof(char);

	return TRUE;
}

BOOL CStream::ReadChars(char* Data, int ValueSize)
{
	memcpy(Data, m_RecvBuffer + m_BufferReadPoint, ValueSize);

	m_BufferReadPoint += ValueSize;

	return TRUE;
}

BOOL CStream::ReadBool(bool* Data)
{
	memcpy(Data, m_RecvBuffer + m_BufferReadPoint, sizeof(bool));

	m_BufferReadPoint += sizeof(bool);

	return TRUE;
}

BOOL CStream::ReadShort(short* Data)
{
	memcpy(Data, m_RecvBuffer + m_BufferReadPoint, sizeof(short));

	m_BufferReadPoint += sizeof(short);

	return TRUE;
}

BOOL CStream::ReadInt(int* Data)
{
	memcpy(Data, m_RecvBuffer + m_BufferReadPoint, sizeof(int));

	m_BufferReadPoint += sizeof(int);

	return TRUE;
}

BOOL CStream::ReadDWORD(DWORD* Data)
{
	memcpy(Data, m_RecvBuffer + m_BufferReadPoint, sizeof(DWORD));

	m_BufferReadPoint += sizeof(DWORD);

	return TRUE;
}

BOOL CStream::ReadFloat(float* Data)
{
	memcpy(Data, m_RecvBuffer + m_BufferReadPoint, sizeof(float));

	m_BufferReadPoint += sizeof(float);

	return TRUE;
}

BOOL CStream::ReadLong(long* Data)
{
	memcpy(Data, m_RecvBuffer + m_BufferReadPoint, sizeof(long));

	m_BufferReadPoint += sizeof(long);

	return TRUE;
}

BOOL CStream::ReadDouble(double* Data)
{
	memcpy(Data, m_RecvBuffer + m_BufferReadPoint, sizeof(double));

	m_BufferReadPoint += sizeof(double);

	return TRUE;
}

BOOL CStream::ReadProtocol(ePakcet_Protocol* Data)
{
	memcpy(Data, m_RecvBuffer + m_BufferReadPoint, sizeof(ePakcet_Protocol));

	m_BufferReadPoint += sizeof(ePakcet_Protocol);

	return TRUE;
}

void CStream::ResetSendPoint()
{
	m_BufferWritePoint = 0;
}

void CStream::ResetRecvPoint()
{
	m_BufferReadPoint = 0;
}