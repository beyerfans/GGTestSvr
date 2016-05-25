#include "GGTCPSocket.h"

bool GGTcpSocket::Create()
{
	m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (m_socket == INVALID_SOCKET)
	{
		return false;
	}

	return true;
}
bool GGTcpSocket::Bind(GGNetAddr& rAddr)
{
	int iRet = bind(m_socket, (sockaddr*)rAddr, sizeof(rAddr));
	if (iRet == SOCKET_ERROR)
	{
		closesocket(m_socket);
		return false;
	}
	return true;
}
bool GGTcpSocket::Listen(int iBacklog)
{
	int iRet = listen(m_socket,iBacklog);

	if (iRet == SOCKET_ERROR)
	{
		closesocket(m_socket);
		return false;
	}
	return true;
}
bool GGTcpSocket::Connect(GGNetAddr& rAddr)
{
	int iRet = connect(m_socket, (sockaddr*)(rAddr), sizeof(rAddr));
	if (iRet == SOCKET_ERROR)
	{
		closesocket(m_socket);
		return false;
	}
	return true;
}
bool GGTcpSocket::Accept(GGTcpSocket& rSock)
{
	rSock.m_socket= accept(m_socket, NULL, NULL);
	if (rSock.m_socket == INVALID_SOCKET)
	{
		closesocket(m_socket);
		return false;
	}
	return true;
}
bool GGTcpSocket::Send()
{
	return true;
}
bool GGTcpSocket::Recv()
{
	return true;
}