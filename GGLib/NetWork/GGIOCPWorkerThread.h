#ifndef _GGIOCP_WORKTHREAD_H
#define _GGIOCP_WORKTHREAD_H

#include "../Utility/GGThread.h"
#include "NetAddr.h"

class GGIOCPWorkThread :public GGThread
{
	public:
		GGIOCPWorkThread(HANDLE hIOCP):m_hIOCP(hIOCP){}
		~GGIOCPWorkThread(){}

		virtual void Run();

	protected:
		
		HANDLE m_hIOCP;
};


#endif
