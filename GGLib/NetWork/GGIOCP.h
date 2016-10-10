#ifndef _GGIOCP_H
#define _GGIOCP_H

#include "NetDefine.h"
#include "GGIOCPWorkerThread.h"

#include <list>

class GGIOCP
{
	public:
		GGIOCP();
		~GGIOCP(){}

		bool InitIOCP();
		bool AssociateWithSocket(SOCKET sfd);
		bool CloseIOCP();

		bool CreateWorkThread(HANDLE hIOCP);

		HANDLE GetHandle() { return m_hIOCP; }

	private:
		HANDLE m_hIOCP;
		std::list<GGIOCPWorkThread*> m_WorkerThreadList;
};


#endif
