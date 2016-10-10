#pragma once

#include "NetDefine.h"

class GGSocket
{
	public:

		GGSocket(){}
		GGSocket(SOCKET sfd):m_socket(sfd){}
		virtual ~GGSocket(){}

		virtual bool Initialize()=0;
		virtual bool Create()=0;
		virtual bool Bind() = 0;
		virtual bool Listen() = 0;
		virtual bool Connect() = 0;

		SOCKET GetSocket() { return m_socket; }
	

	protected:

		SOCKET m_socket;
};

