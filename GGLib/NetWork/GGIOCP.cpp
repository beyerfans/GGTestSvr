#include "GGIOCP.h"

GGIOCP::GGIOCP():m_hIOCP(INVALID_HANDLE_VALUE)
{
	
}

bool GGIOCP::InitIOCP()
{
	return (m_hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0)) == NULL ? false : true;
}


bool GGIOCP::AssociateWithSocket(SOCKET sfd)
{
	return (m_hIOCP = CreateIoCompletionPort((HANDLE)sfd, m_hIOCP, sfd, 0)) == NULL ? false : true;
}

bool GGIOCP::CloseIOCP()
{
	return true;
}

bool GGIOCP::CreateWorkThread(HANDLE hIOCP)
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);

	for (auto i = 0; i < sysinfo.dwNumberOfProcessors; ++i)
	{
		GGIOCPWorkThread *pThread = new (std::nothrow) GGIOCPWorkThread(m_hIOCP);
		if (pThread != nullptr)
		{
			m_WorkerThreadList.push_back(pThread);
		}
		else
		{
			return false;
		}
	}

	return true;

}