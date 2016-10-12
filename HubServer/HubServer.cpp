#include "HubServer.h"
#include "../pugixml-1.7/src/pugixml.hpp"

GGHubServer::GGHubServer()
{
}

GGHubServer::~GGHubServer()
{
}

bool GGHubServer::_ReadConfig(std::string & strConf)
{
	pugi::xml_document doc;
	pugi::xml_parse_result ret = doc.load_file(strConf.c_str());

	if (ret.status != pugi::xml_parse_status::status_ok)
	{
		//parse failed
		return false;
	}
	else
	{
		pugi::xml_node ipnode = doc.child("Gameserver").child("ListenIP");
		pugi::xml_node portnode = doc.child("Gameserver").child("ListenPort");
		std::string strIP(ipnode.text().as_string());
		std::string strPort(portnode.text().as_string());

		m_ListenAddr.SetAddr(strIP, strPort);

		return true;

	}	
}
