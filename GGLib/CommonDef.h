#ifndef _COMMONDEF_H
#define _COMMONDEF_H

#include "..\Utility\CustomType.h"

enum eTimerID
{
	TIMERID_LISTEN_CHECK,
	TIMERID_ACCEPT_CHECK,
};

const uint32 cuListenCheck = 1000;
const uint32 cuAcceptCheck = 1000;

#endif