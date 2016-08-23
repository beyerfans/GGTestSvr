#pragma once


#ifdef _WIN32
#include <WinSock2.h>
typedef  u_short ggPort;
#else
typedef unsigned short ggPort;
typedef int SOCKET;
#endif

