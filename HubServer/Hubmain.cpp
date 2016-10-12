#include "HubServer.h"
#include "../GGLib/Platform/GGServer.h"

#pragma comment(lib,"../Debug/GGLib.lib")

int main()
{
	GGServer server;
	server.Run();

	return 0;
}