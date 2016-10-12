#ifndef _HUB_SERVER_H
#define _HUB_SERVER_H

#include "../GGLib/Platform/GGServer.h"

//class GGServer;

class GGHubServer : public GGServer
{
	public:
		GGHubServer();
		~GGHubServer();

	protected:
		virtual bool _ReadConfig(std::string& strConf);
};


#endif