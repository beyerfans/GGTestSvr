#pragma once

#include "NetDefine.h"
#ifdef _WIN32
//#include <string>
#include <ws2ipdef.h>
#else
//#include <string>
#include <netdb.h> 
#endif

#include <string>  
#include <string.h>
//using namespace std;

class GGNetAddr
{
	public:

		GGNetAddr();
		GGNetAddr(const std::string& rsIP,const std::string& rsPort);
		virtual ~GGNetAddr();

		void SetAddr(const std::string& rsIP, const std::string& rsPort);

		operator struct sockaddr_in* () const;
		operator struct sockaddr* () const;

	protected:

		void _InitAddr(){ memset(&m_sockaddr, 0, sizeof(m_sockaddr));}
		/*void _SetAddress(string sIP);
		void _SetPort(ggPort usPort);*/
		void _AssignAddr(const std::string& rsIP, const std::string& rsPort);

		//GGTO: add socket address

		sockaddr_in m_sockaddr;
		sockaddr_in6 m_sockaddrV6;
};


