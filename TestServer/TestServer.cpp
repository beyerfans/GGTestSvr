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

using namespace std;

void threadtest()
{
	cout <<__FUNCTION__<< endl;
}


int main( )

{
	GGSingleton<GGNetInit>::GetInstance();

	string sIP("localhost");
	string sPort("9999");
	GGNetAddr netaddr(sIP, sPort);

	GGServer oserver;
	oserver.AddListen(netaddr);
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

