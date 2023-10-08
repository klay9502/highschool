#include "stdafx.h"
#include "RecvPacket.h"


CRecvPacket::CRecvPacket()
{
}


CRecvPacket::~CRecvPacket()
{
}

VOID CRecvPacket::Packet_Player_Position_Recv(CStream* Buffer, int* MyClientNum, float X[2], float Y[2])
{
	Buffer->ReadInt(MyClientNum);
	Buffer->ReadFloat(&X[0]);
	Buffer->ReadFloat(&Y[0]);
	Buffer->ReadFloat(&X[1]);
	Buffer->ReadFloat(&Y[1]);

	g_pBufferManager->ClearRecvBuffer();
	g_pBufferManager->ResetRecvPoint();
}