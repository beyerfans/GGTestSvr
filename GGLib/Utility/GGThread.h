#pragma once

#include <thread>
#include <iostream>

class GGThread 
{
	public:

		template<class func, class... args>
		explicit GGThread(func&& f, args&&... arglist):m_ggthread(f, arglist...){}

		GGThread():m_ggthread(){  }

		virtual ~GGThread(){ if (m_ggthread.joinable()){ m_ggthread.join(); } }


		std::thread::native_handle_type Gethandle(){ return m_ggthread.native_handle(); }
	
		
		virtual void RunOnce()
		{
			m_ggthread = std::move(std::thread(&GGThread::Run, this));			
			
		}
		virtual void Run()
		{ 
			
		}

	private:

		std::thread m_ggthread;
};



