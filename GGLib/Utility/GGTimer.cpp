#include <algorithm>
#include "GGTimer.h"

using namespace std::chrono;

bool GGTimer::AddTimer(uint32 uTimerID, uint32 uIntervalms)
{
	stTimer sttr;

	sttr.bActive = true;
	sttr.uIntervalms = uIntervalms;

	sttr.uTime = system_clock::now();
	sttr.uTime = sttr.uTime + milliseconds(sttr.uIntervalms);	


	m_TimerMap.insert(std::make_pair(uTimerID, sttr));

	return true;

}
bool GGTimer::StopTimer(uint32 uTimerID)
{
	std::map<uint32, stTimer>::iterator itTimer = m_TimerMap.find(uTimerID);
	if (itTimer != m_TimerMap.end())
	{
		itTimer->second.bActive = false;
	}
	return true;
}
bool GGTimer::ResumeTimer(uint32 uTimerID)
{
	std::map<uint32, stTimer>::iterator itTimer = m_TimerMap.find(uTimerID);
	if (itTimer != m_TimerMap.end())
	{
		itTimer->second.bActive = true;
		itTimer->second.uTime = system_clock::now();
	}
	return true;
}
bool GGTimer::RemoveTimer(uint32 uTimerID)
{
	std::map<uint32, stTimer>::iterator itTimer = m_TimerMap.find(uTimerID);
	if (itTimer != m_TimerMap.end())
	{
		m_TimerMap.erase(itTimer);
	}
	
	return true;
}

bool GGTimer::UpdateTimer()
{
	for (auto itTimer:m_TimerMap) 
	{
		if (itTimer.second.bActive&&itTimer.second.uTime<system_clock::now())
		{
			itTimer.second.uTime = system_clock::now()+milliseconds(itTimer.second.uIntervalms);
			OnTimer(itTimer.first);
		}
	}
	return true;
}