#ifndef _GG_THREAD_H
#define _GG_THREAD_H

#include <thread>

class GGThread 
{
	public:

		template<class func, class... args>
		explicit GGThread(func&& f, args&&... arglist):_ggthread(f, arglist...){}
		virtual ~GGThread(){ if (_ggthread.joinable()){ _ggthread.join(); } }

		virtual void Run(){}


	private:

		std::thread _ggthread;
};



#endif