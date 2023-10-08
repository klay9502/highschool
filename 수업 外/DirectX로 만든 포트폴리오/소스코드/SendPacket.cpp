#include "stdafx.h"
#include "SendPacket.h"


CSendPacket::CSendPacket()
{
}


CSendPacket::~CSendPacket()
{
}

VOID CSendPacket::Packet_Player_Position_Send(CStream* Buffer, float XPos, float YPos)
{
	DWORD PacketLength = sizeof(ePakcet_Protocol) + sizeof(DWORD) + sizeof(float) + sizeof(float);

	Buffer->WriteProtocol(ePakcet_Protocol::ePacket_PLAY);
	Buffer->WriteDWORD(PacketLength);
	Buffer->WriteFloat(XPos);
	Buffer->WriteFloat(YPos);
}
