// TestServer.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

#ifdef _WIN32
#include "stdafx.h"
#endif

#include "string"
#include "../GGLib/NetWork/NetAddr.h"
#include "../GGLib/NetWork/GGTCPSocket.h"
#include "../GGLib/NetWork/GGNetInit.h"
#include "../GGLib/Utility/GGSingleton.h"
#include "../GGLib/Utility/GGThread.h"
#include "../GGLib/NetWork/NetDefine.h"
#include "../GGLib/Platform/GGServer.h"
#include "ThreadTest.h"

#pragma comment(lib,"../Debug/GGLib.lib")

//std::string g_strConfFile = "./Config/Server.ini";


//using namespace std;


int main( )

{
	GGSingleton<GGNetInit>::GetInstance();

	char cListenIP[20] = { 0 };
	char cListenPort[8] = { 0 };
	

	/*int count = GetPrivateProfileString("ServerConf", "ListenIP", "", cListenIP, 20, g_strConfFile.c_str());
	count = GetPrivateProfileString("ServerConf", "ListenPort", "", cListenPort, 8, g_strConfFile.c_str());

	int ierrno = GetLastError();

	std::string sIP=cListenIP;
	std::string sPort=cListenPort;

	GGNetAddr netaddr(sIP, sPort);*/

	GGServer oserver;
	//oserver.AddListen(netaddr);
	oserver.Run();



	//GGTcpSocket sListenSock;
	//if (sListenSock.Create() && sListenSock.Bind(netaddr))
	//{
	//	sListenSock.Listen(5);
	//}

	//GGTestThread ggtt;	
	//ggtt.RunOnce();

	//HANDLE hThread = ggtt.Gethandle();	

	return 0;
}

