#pragma once

#include <list>
#include "../Utility/GGThread.h"
#include "../NetWork/GGTCPSocket.h"



class GGServer :public GGThread
{

	public:
		GGServer(){}
		virtual ~GGServer(){}

		virtual void Run();

		bool AddListen();



	protected:
	
		bool _Accept();

		std::list<GGTcpSocket> m_ListenSock;
		std::list<GGTcpSocket> m_AcceptSock;	
		
};