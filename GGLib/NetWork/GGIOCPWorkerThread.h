#ifndef _GGIOCP_WORKTHREAD_H
#define _GGIOCP_WORKTHREAD_H

#include "../Utility/GGThread.h"

class GGIOCPWorkThread :public GGThread
{
	public:
		GGIOCPWorkThread(){}
		~GGIOCPWorkThread(){}

		virtual void Run();

};


#endif
