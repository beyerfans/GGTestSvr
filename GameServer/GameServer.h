#ifndef _GAMESERVER_H
#define _GAMESERVER_H

#include "../GGLib/Platform/GGServer.h"

class GameServer :public GGServer
{
	public:	

		GameServer(){}
		~GameServer(){}

	protected:

		bool _ReadConfig(std::string& strConf);

};


#endif