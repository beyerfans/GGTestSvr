#pragma once


#ifdef _WIN32
#include <WinSock2.h>
#include <ws2tcpip.h>
typedef  u_short ggPort;
#else
typedef unsigned short ggPort;
typedef int SOCKET;
typedef int HANDLE;
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1
#endif

