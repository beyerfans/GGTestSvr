#pragma once

#include <list>
#include <unordered_map>
#include "../NetWork/GGTCPSocket.h"
#include "../Utility/GGThread.h"
#include "../NetWork/NetAddr.h"
#include "../Utility/GGTimer.h"

#define REG_CMD_HANDLER(cmd,funHandle)\
	m_CmdMap.insert(std::make_pair(#cmd,&GGServer::funHandle));

class GGServer;
typedef void (GGServer::*pFunHandleCmd)();


class GGServer :public GGTimer
{

	
	//typedef pFunHandleCmd FunHandle;

	public:
		
		GGServer();		
		virtual ~GGServer();
		virtual void Run();
		bool AddListen(GGNetAddr& rAddr);
		

	protected:      

		bool _Init(); //Initialization
		bool _Release();//release resource
		void ReadInput();
		virtual void _Close(int iSec);
		virtual bool _Accept();

		//Command handling functions
		void CloseServer();

		//TODO: Add console input handling      
		virtual void _OnConsoleCmd(const std::string& cmdstr);

		virtual bool OnTimer(uint32 uTimerID);


		std::list<GGTcpSocket*> m_ListenSock;
		std::list<GGTcpSocket*> m_AcceptSock;	
		std::unordered_map < std::string, pFunHandleCmd> m_CmdMap;
		GGThread* m_pInput;

		bool m_bClose;
};
