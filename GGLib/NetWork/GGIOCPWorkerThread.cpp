#include "GGIOCPWorkerThread.h"


void GGIOCPWorkThread::Run()
{
	while (true)
	{
		GetQueuedCompletionStatus(m_hIOCP,;

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	
}