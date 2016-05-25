// TestServer.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include "stdafx.h"
#include "string"
#include "../GGLib/NetWork/NetAddr.h"
#include "../GGLib/NetWork/GGTCPSocket.h"
#include "../GGLib/NetWork/GGNetInit.h"
#include "../GGLib/Utility/GGSingleton.h"
#include "../GGLib/Utility/GGThread.h"

#pragma comment(lib,"../Debug/GGLib.lib")

using namespace std;

void threadtest()
{
	cout <<__FUNCTION__<< endl;
}


int _tmain(int argc, _TCHAR* argv[])
{

	GGSingleton<GGNetInit>::GetInstance();

	string sIP("localhost");
	string sPort("9999");
	GGNetAddr netaddr(sIP, sPort);

	GGTcpSocket sListenSock;
	if (sListenSock.Create() && sListenSock.Bind(netaddr))
	{
		sListenSock.Listen(5);
	}

	GGThread thread1(threadtest);
	


	std::unique_ptr<GGNetAddr> pTestAddr( new GGNetAddr(sIP, sPort));

	return 0;
}

