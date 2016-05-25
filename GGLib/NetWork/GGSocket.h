#ifndef _GG_SOCKET_H
#define _GG_SOCKET_H

#include "NetDefine.h"

class GGSocket
{
	public:

		GGSocket(){}
		virtual ~GGSocket(){}

		virtual bool Initialize()=0;
		virtual bool Create()=0;
		virtual bool Bind() = 0;
		virtual bool Listen() = 0;
		virtual bool Connect() = 0;

	protected:

		SOCKET m_socket;
};


#endif