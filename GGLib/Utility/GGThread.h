#ifndef _GG_THREAD_H
#define _GG_THREAD_H

#include <thread>

class GGThread :public std::thread
{
	public:

		template<class func, class... args>
		explicit GGThread(func&& f, args&&... arglist):std::thread(f, arglist...){}
		virtual ~GGThread(){}

		virtual void Run(){}

};



#endif