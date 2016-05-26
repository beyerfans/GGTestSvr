#pragma once

#include "NetDefine.h"
#include <string>

#ifdef _WIN32
//#include <WinSock2.h>
#include <ws2ipdef.h>
#else
#include <netdb.h>
#endif

using namespace std;

class GGNetAddr
{
	public:

		GGNetAddr();
		GGNetAddr(const string& rsIP,const string& rsPort);
		virtual ~GGNetAddr();

		void SetAddr(const string& rsIP, const string& rsPort);

		operator struct sockaddr_in* () const;
		operator struct sockaddr* () const;

	protected:

		void _InitAddr(){ memset(&m_sockaddr, 0, sizeof(m_sockaddr));}
		/*void _SetAddress(string sIP);
		void _SetPort(ggPort usPort);*/
		void _AssignAddr(const string& rsIP, const string& rsPort);

		//GGTO: add socket address

		sockaddr_in m_sockaddr;
		sockaddr_in6 m_sockaddrV6;
};


