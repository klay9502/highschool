#pragma once

#include "Stream.h"
#include "Singleton.h"

#define MAX_CLIENT 2
#define BUF_SIZE 1024

#define g_pNetwork CNetWork::GetInstance()

typedef struct UserData
{
	float X;
	float Y;
	float Angle;
}USER;

class CNetWork :
	public ISingleton <CNetWork>
{
public :
	CNetWork();
	virtual ~CNetWork();

public :
	WSADATA wsaData;
	SOCKET	hSocket;
	SOCKADDR_IN servAddr;
	fd_set fd_Recv, fd_Send;
	fd_set cpyRecv, cpySend;
	TIMEVAL TimeOut;

public :
	DWORD PacketLength;
	ePakcet_Protocol PacketType;

public :
	USER m_User[2];

public :
	BOOL Initialize();
	void Loop();
	void Send();
	void Recv();
	void Terminate();

public :
	BOOL RoomPacket();
};

