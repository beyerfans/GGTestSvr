#pragma once

#include "GGSocket.h"
#include "NetAddr.h"

class GGTcpSocket :public GGSocket
{
public:

	GGTcpSocket(){}
	GGTcpSocket(SOCKET sfd):GGSocket(sfd){}
	virtual ~GGTcpSocket();

	virtual bool Initialize(){ return true; }
	virtual bool Create();

	virtual bool Bind() { return true; }
	virtual bool Listen(){ return true; }
	virtual bool Connect() { return true; }

    bool SetBlock(bool bBlocking);

	virtual bool Bind(GGNetAddr& rAddr);
	virtual bool Listen(int iBacklog);
	virtual bool Connect(GGNetAddr& rAddr);
	bool Accept(GGTcpSocket& rSock);
	bool Send();
	bool Recv();
	void Close();

	
};

