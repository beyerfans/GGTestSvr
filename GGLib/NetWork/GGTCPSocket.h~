#pragma once

#include "GGSocket.h"
#include "NetAddr.h"

class GGTcpSocket :public GGSocket
{
public:

	GGTcpSocket(){}
	virtual ~GGTcpSocket(){}

	virtual bool Initialize(){ return true; }
	virtual bool Create();

	virtual bool Bind() { return true; }
	virtual bool Listen(){ return true; }
	virtual bool Connect() { return true; }



	virtual bool Bind(GGNetAddr& rAddr);
	virtual bool Listen(int iBacklog);
	virtual bool Connect(GGNetAddr& rAddr);
	bool Accept(GGTcpSocket& rSock);
	bool Send();
	bool Recv();

protected:

	void Close(SOCKET sockfd);

	
};

