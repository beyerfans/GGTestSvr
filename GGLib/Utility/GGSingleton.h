#ifndef _GG_SINGLETON_H
#define _GG_SINGLETON_H

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


#endif