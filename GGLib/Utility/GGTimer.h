#ifndef _GGTIMER_H
#define _GGTIMER_H

#include "CustomType.h"
#include <map>
#include <chrono>

using namespace std::chrono;

struct stTimer
{
	system_clock::time_point uTime;
	uint32 uIntervalms;
	bool bActive;
};


class GGTimer
{
	public:

		GGTimer(){};
		~GGTimer(){};

		bool AddTimer(uint32 uTimerID, uint32 uInterval);
		bool StopTimer(uint32 uTimerID);
		bool ResumeTimer(uint32 uTimerID);
		bool RemoveTimer(uint32 uTimerID);

		virtual bool OnTimer(uint32 uTimerID) = 0;

	protected:

		bool UpdateTimer();


		std::map<uint32, stTimer> m_TimerMap;


};



#endif