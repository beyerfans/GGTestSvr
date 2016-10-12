#include <string>
#include "GGServer.h"
#include "../CommonDef.h"
#include "../NetWork/GGNetInit.h"
#include "../Utility/GGSingleton.h"

#include "../../pugixml-1.7/src/pugixml.hpp"

std::string g_strConfxml = "serverconf.xml";


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
	//
	GGSingleton<GGNetInit>::GetInstance();

	//register cmd handling function
	REG_CMD_HANDLER(close, CloseServer);	

	m_pInput = new GGThread(&GGServer::ReadInput,this);

	AddTimer(TIMERID_LISTEN_CHECK, cuListenCheck);
	AddTimer(TIMERID_ACCEPT_CHECK, cuAcceptCheck);

	_ReadConfig(g_strConfxml);

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
	int iCount = 0;
	fd_set sockset;

	FD_ZERO(&sockset);

	for (auto itListen = m_ListenSock.begin(); itListen != m_ListenSock.end(); ++itListen)
	{
		FD_SET(((*itListen)->GetSocket()), &sockset);
	}

	iCount=(m_ListenSock.size(), &sockset, nullptr, nullptr, 0);

	for (auto itListen=m_ListenSock.begin(); itListen!=m_ListenSock.end(); ++itListen)
	{
		if (FD_ISSET(((*itListen)->GetSocket()), &sockset))
		{
			sockaddr saddr;
			int addrlen=0;
			SOCKET accsock=accept((*itListen)->GetSocket(), &saddr, &addrlen);

			//push accepted socket to map

			GGTcpSocket *pSocket =  new (std::nothrow) GGTcpSocket(accsock);
			if (pSocket == nullptr)
			{
				return false;
			}
			else
			{
				m_AcceptSock.push_back(pSocket);
			}
		}
	}
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
		_Accept();
	}
	break;
	}

	return true;

}

bool GGServer::_ReadConfig(std::string& strConf)
{
	pugi::xml_document doc;
	pugi::xml_parse_result ret=doc.load_file(strConf.c_str());

	if (ret.status != pugi::xml_parse_status::status_ok)
	{
		//parse failed
		return false;
	}
	else
	{
		pugi::xml_node ipnode= doc.child("Gameserver").child("ListenIP");
		pugi::xml_node portnode = doc.child("Gameserver").child("ListenPort");
		std::string strIP(ipnode.text().as_string());
		std::string strPort(portnode.text().as_string());

		m_ListenAddr.SetAddr(strIP,  strPort);

		return true;

	}
}