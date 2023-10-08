#include "stdafx.h"
#include "NetWork.h"



CNetWork::CNetWork()
{
	PacketLength = 0;
}


CNetWork::~CNetWork()
{
}

BOOL CNetWork::Initialize()
{
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		MessageBox(NULL, "NewWork Initialize Failed!\n\nError::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0", "ERROR", MB_ICONERROR);
		return FALSE;
	}

	hSocket = socket(PF_INET, SOCK_STREAM, 0);

	if (hSocket == INVALID_SOCKET)
	{
		MessageBox(NULL, "NewWork Initialize Failed!\n\nError::hSocket == INVALID_SOCKE", "ERROR", MB_ICONERROR);
		return FALSE;
	}

	ZeroMemory(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons(atoi("1237"));

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		MessageBox(NULL, "NewWork Initialize Failed!\n\nError::connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR", "ERROR", MB_ICONERROR);
		system("pause"); // 프로세스 동결
		return FALSE;
	}

	FD_ZERO(&fd_Recv);
	FD_ZERO(&cpyRecv);
	FD_ZERO(&fd_Send);
	FD_ZERO(&cpySend);

	FD_SET(hSocket, &fd_Recv);
	FD_SET(hSocket, &fd_Send);

	return TRUE;
}

void CNetWork::Loop()
{
	TimeOut.tv_sec = 0.1F;
	TimeOut.tv_usec = 0.1F;

	cpyRecv = fd_Recv;
	cpySend = fd_Send;

	int SockResult = select(0, &cpyRecv, &cpySend, 0, &TimeOut);

	if (0 < SockResult)
	{
		if (FD_ISSET(hSocket, &cpyRecv))
		{
			recv(hSocket, g_pBufferManager->m_RecvBuffer, BUF_SIZE, 0);

			g_pBufferManager->ReadProtocol(&PacketType);

			g_pBufferManager->ReadDWORD(&PacketLength);

			//switch (PacketType)
			//{
			//case ePakcet_Protocol::ePacket_PLAY:
			//	CRecvPacket::Packet_Player_Position_Recv(g_pBufferManager, &m_User[i]);
			//	break;
			//}
		}

		if (FD_ISSET(hSocket, &cpySend))
		{
			send(hSocket, g_pBufferManager->m_SendBuffer, BUF_SIZE, 0);

			g_pBufferManager->ClearSendBuffer();
			g_pBufferManager->ResetSendPoint();
		}
	}
}

void CNetWork::Send()
{

}
void CNetWork::Recv()
{

}

void CNetWork::Terminate()
{

}
