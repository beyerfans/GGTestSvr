#include "GGIOCP.h"

GGIOCP::GGIOCP():m_IOCP(INVALID_HANDLE_VALUE)
{
	
}

bool GGIOCP::InitIOCP()
{
	return (m_IOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0)) == NULL ? false : true;
}


bool GGIOCP::CreateIOCP()
{
	
}

bool GGIOCP::CloseIOCP()
{

}

bool GGIOCP::CreateWorkThread()
{


}