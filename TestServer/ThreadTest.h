#pragma once

#include<iostream>
#include "../GGLib/Utility/GGThread.h"


class GGTestThread : public GGThread
{
	public:

		GGTestThread(){}
		virtual ~GGTestThread(){}

		virtual void Run()
		{ 
			for (int i = 0; i < 10; ++i)
			{
				cout << __FUNCTION__ << endl;
			}
		}
};
