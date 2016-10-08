#ifndef _GGIOCP_H
#define _GGIOCP_H

#include "NetDefine.h"


class GGIOCP
{
	public:
		GGIOCP();
		~GGIOCP(){}

		bool InitIOCP();
		bool CreateIOCP();
		bool CloseIOCP();

		bool CreateWorkThread();

	private:
		HANDLE m_IOCP;
};


#endif
