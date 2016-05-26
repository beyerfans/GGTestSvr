#pragma once

template <class T>
class GGSingleton
{
	public:
		GGSingleton(){}
		virtual ~GGSingleton(){}

		static T& GetInstance()
		{
			static T stobj;
			return stobj;
		}	
};


