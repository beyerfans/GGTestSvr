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

#include "ThreadTest.h"

#pragma comment(lib,"../Debug/GGLib.lib")

using namespace std;

void threadtest()
{
	cout <<__FUNCTION__<< endl;
}


int _tmain(int argc, char* argv[])

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

	/*GGThread thread1(threadtest);
	
	HANDLE hThread = thread1.Gethandle();*/


	GGTestThread ggtt;

	GGTestThread* pthread = &ggtt;

	ggtt.RunOnce();
	
	typedef int HANDLE;

	HANDLE hThread = ggtt.Gethandle();

	//std::unique_ptr<GGNetAddr> pTestAddr( new GGNetAddr(sIP, sPort));

	return 0;
}

