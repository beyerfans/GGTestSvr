
//#include <ws2tcpip.h>
#include <string.h>
#include "NetAddr.h"

#pragma comment (lib,"ws2_32.lib")

GGNetAddr::GGNetAddr()
{
	_InitAddr();
}

GGNetAddr::GGNetAddr(const string& rsIP, const string& rsPort)
{
	_InitAddr();
	_AssignAddr(rsIP,rsPort);
}

GGNetAddr::~GGNetAddr()
{
	
}

void GGNetAddr::SetAddr(const string& rsIP, const string& rsPort)
{
	_InitAddr();
	_AssignAddr(rsIP,rsPort);
	return;
}

GGNetAddr::operator struct sockaddr_in* () const
{
	return const_cast<sockaddr_in*>(&m_sockaddr);
}

GGNetAddr::operator struct sockaddr* () const
{
	return const_cast<sockaddr*>((sockaddr*)&m_sockaddr);
}


void GGNetAddr::_AssignAddr(const string& rsIP, const string& rsPort)
{
	addrinfo *pResult,*pCurrent;

	int iRet = getaddrinfo(rsIP.c_str(), rsPort.c_str(), NULL, &pResult);
	if (iRet != 0)
	{
		//GGTO: add fail process here
	}

	pCurrent = pResult;
	//memcpy(&m_sockaddr, pCurrent->ai_addr, pCurrent->ai_addrlen);

	for (pCurrent = pResult; pCurrent != NULL; pCurrent = pCurrent->ai_next)
	{
		if (pCurrent->ai_family == AF_INET)
		{
			memcpy(&m_sockaddr, pCurrent->ai_addr, pCurrent->ai_addrlen);
		}
		else if (pCurrent->ai_family == AF_INET6)
		{
			memcpy(&m_sockaddrV6, pCurrent->ai_addr, pCurrent->ai_addrlen);
		}
	}

	freeaddrinfo(pResult);
}
