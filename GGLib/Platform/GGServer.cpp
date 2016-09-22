#include <string>
#include "GGServer.h"
#include "../CommonDef.h"


GGServer::GGServer() :m_pInput(nullptr), m_bClose(false)
{	
	_Init();
}

GGServer::~GGServer()
{
	_Release();
}

bool GGServer::_Init()
{
	//register cmd handling function
	REG_CMD_HANDLER(close, CloseServer);	

	m_pInput = new GGThread(&GGServer::ReadInput,this);

	AddTimer(TIMERID_LISTEN_CHECK, cuListenCheck);
	AddTimer(TIMERID_ACCEPT_CHECK, cuAcceptCheck);

	return true;
}

bool GGServer::_Release()
{
	if (m_pInput != nullptr)
	{
		delete m_pInput;
	}

	for (std::list<GGTcpSocket*>::iterator itSock = m_ListenSock.begin(); itSock != m_ListenSock.end(); )
	{
		GGTcpSocket* pSocket = *itSock;

		if (pSocket != nullptr)
		{
			delete pSocket;			
		}

		m_ListenSock.erase(itSock++);
	}

	for (std::list<GGTcpSocket*>::iterator itSock = m_AcceptSock.begin(); itSock != m_AcceptSock.end();)
	{
		GGTcpSocket* pSocket = *itSock;

		if (pSocket != nullptr)
		{
			delete pSocket;			
		}

		m_AcceptSock.erase(itSock++);
		
	}

	return true;
}

void GGServer::Run()
{	
	while (!m_bClose)
	{
		
	}	
}

bool GGServer::AddListen(GGNetAddr& rAddr)
{

	GGTcpSocket* pSock = new GGTcpSocket;
	if (pSock->Create()&&pSock->Bind(rAddr))
	{
		pSock->Listen(10);
		m_ListenSock.push_back(pSock);
		return true;
	}

	else
	{
		delete pSock;
		return false;
	}

}
	

bool GGServer::_Accept()
{
	

	return true;
}


void GGServer::ReadInput()
{
	std::string instr;

	std::getline(std::cin, instr);

	if (instr.size() != 0)
	{
		std::unordered_map < std::string, pFunHandleCmd>::iterator itFun = m_CmdMap.find(instr);
		if (itFun != m_CmdMap.end())
		{
			pFunHandleCmd pFunHandle = itFun->second;
			(this->*pFunHandle)();			
		}

	}

}

void GGServer::CloseServer()
{
	m_bClose = true;
}

void GGServer::_OnConsoleCmd(const std::string& strcmd)
{
	
}

void GGServer::_Close(int iSec)
{


}

bool GGServer::OnTimer(uint32 uTimerID)
{
	switch (uTimerID)
	{

	case TIMERID_LISTEN_CHECK:
	{


	}
	break;

	case TIMERID_ACCEPT_CHECK:
	{


	}
	break;
	}

	return true;

}