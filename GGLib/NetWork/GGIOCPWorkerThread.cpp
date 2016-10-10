#include "GGIOCPWorkerThread.h"


void GGIOCPWorkThread::Run()
{
	DWORD dwnumofbytes=0;
	SOCKET sfd;
	LPOVERLAPPED *pOverlap = NULL;
	while (true)
	{
		if (GetQueuedCompletionStatus(m_hIOCP, &dwnumofbytes, (PULONG_PTR)&sfd, pOverlap, 0) == 0)
		{
			if (*pOverlap == NULL)
			{
				//Socket closed 

			}
			else
			{
				//Received failed packet

			}
		}
		else
		{
			if (*pOverlap != NULL)
			{
				//Received data packet
				std::cout << "Received data packet" << (char*)*pOverlap << std::endl;
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	
}