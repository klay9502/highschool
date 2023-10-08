#pragma once
class CSendPacket
{
public:
	CSendPacket();
	virtual ~CSendPacket();

public :
	static VOID Packet_Player_Position_Send(CStream* Buffer, float XPos, float YPos);
};

