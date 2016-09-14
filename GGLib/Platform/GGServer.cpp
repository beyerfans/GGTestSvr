#include <string>
#include "GGServer.h"


GGServer::GGServer()
{
	REG_CMD_HANDLER(close, CloseServer);

}

void GGServer::Run()
{
	ReadInput();

}

bool GGServer::AddListen()
{

	return true;
}

bool GGServer::_Accept()
{


	return true;
}


void GGServer::ReadInput()
{
	std::string instr;

	std::getline(std::cin, instr);

	if (instr.size() != 0)
	{
		_OnConsoleCmd(instr);
	}

}

void GGServer::CloseServer()
{



}

void GGServer::_OnConsoleCmd(const std::string& strcmd)
{
	
}

void GGServer::_Close(int iSec)
{


}