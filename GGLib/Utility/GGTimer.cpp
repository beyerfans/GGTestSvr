#include <chrono>
#include "GGTimer.h"

using namespace std::chrono;

bool GGTimer::AddTimer(uint32 uTimerID, uint32 uIntervalms)
{
	stTimer sttr;
	sttr.uInterval = uIntervalms;

	
	//sttr.uTime = system_clock::now();

	
	//sttr.uTime = nowms + uIntervalms;

	return true;

}
bool GGTimer::StopTimer(uint32 uTimerID)
{

	return true;
}
bool GGTimer::ResumeTimer(uint32 uTimerID)
{
	return true;
}
bool GGTimer::RemoveTimer(uint32 uTimerID)
{

	return true;
}

bool GGTimer::UpdateTimer()
{
	return true;
}