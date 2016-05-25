#ifndef _GG_NET_DEFINE
#define _GG_NET_DEFINE


#ifdef _WIN32
#include <WinSock2.h>
typedef  u_short ggPort;
#else
typedef unsigned short ggPort;
#endif

#endif