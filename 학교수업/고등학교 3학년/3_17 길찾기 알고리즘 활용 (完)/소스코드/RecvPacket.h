#pragma once
class CRecvPacket
{
public:
	CRecvPacket();
	virtual ~CRecvPacket();

public :
	static VOID Packet_Player_Position_Recv(CStream* Buffer, int* MyClientNum, float X[2], float Y[2]);
};

