#include "GGTCPSocket.h"

#ifdef _WIN32

#else
#include <unistd.h>
#endif

GGTcpSocket::~GGTcpSocket()
{
	Close();
}


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
		
		Close();
		return false;
	}
	return true;
}
bool GGTcpSocket::Listen(int iBacklog)
{
	int iRet = listen(m_socket,iBacklog);

	if (iRet == SOCKET_ERROR)
	{
		Close();
		return false;
	}
	return true;
}
bool GGTcpSocket::Connect(GGNetAddr& rAddr)
{
	int iRet = connect(m_socket, (sockaddr*)(rAddr), sizeof(rAddr));
	if (iRet == SOCKET_ERROR)
	{
		Close();
		return false;
	}
	return true;
}
bool GGTcpSocket::Accept(GGTcpSocket& rSock)
{
	rSock.m_socket= accept(m_socket, NULL, NULL);
	if (rSock.m_socket == INVALID_SOCKET)
	{
		Close();
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

void GGTcpSocket::Close()
{
	#ifdef _WIN32
		closesocket(m_socket);
	#else
		close(m_socket);
	#endif
}

bool GGTcpSocket::SetBlock(bool bBlocking)
{
    #ifdef _WIN32

	u_long uFlag = (u_long)bBlocking;

	int iResult = ioctlsocket(m_socket, FIONBIO, (u_long*)&uFlag);
	if (iResult != 0)
	{
		//Todo: Add error message
		return false;
	}
	else
	{
		return true;
	}

    #else
    
    int iflags=fnctl(m_socket,F_GETFL);
    if(iflags<0)
    {
        return false;
    }    
    else
    {
        iflags=bBlocking?iflags&~O_NONBLOCK:iflags|O_NONBLOCK;
        return fnctl(m_socket,F_SETFL,iflags)==0?true:false;        
    }
    #endif    	
}
