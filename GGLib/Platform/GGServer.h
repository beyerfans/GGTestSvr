#pragma once

#include <list>
#include <unordered_map>
#include "../Utility/GGThread.h"
#include "../NetWork/GGTCPSocket.h"

#define REG_CMD_HANDLER(cmd,funHandle)\
	m_CmdMap.insert(std::make_pair<std::string,GGServer::pFunHandleCmd>(#cmd,GGServer::##funHandle()));


class GGServer :public GGThread
{

	typedef void (*GGServer::pFunHandleCmd) ();
	

	public:
		
		GGServer();
		virtual ~GGServer(){}

		virtual void Run();

		bool AddListen();

		

	protected:      

		void ReadInput();
		virtual void _Close(int iSec);
		virtual bool _Accept();

		//Command handling functions
		void CloseServer();

		//TODO: Add console input handling      
		virtual void _OnConsoleCmd(const std::string& cmdstr);


		std::list<GGTcpSocket> m_ListenSock;
		std::list<GGTcpSocket> m_AcceptSock;	
		std::unordered_map < std::string, GGServer::pFunHandleCmd> m_CmdMap;
};
