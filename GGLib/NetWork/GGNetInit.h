#pragma once

#include <iostream>

class GGNetInit
{
	public:
		GGNetInit(){ _Initialize(); }
		virtual ~GGNetInit(){ _CleanUp(); }
	protected:
		bool _Initialize()
		{
			
#ifdef _DEBUG
			std::cout<<__FUNCTION__<<std::endl;
#endif

			#ifdef _WIN32

				WORD wVersionReq = MAKEWORD(2, 2);
				WSADATA wData;
				int errCode;

				errCode = WSAStartup(wVersionReq, &wData);

				if (errCode != 0)
				{
					//GGTO: Add failure handling here
					return false;
				}

				if (LOBYTE(wData.wVersion) != 2 || HIBYTE(wData.wVersion) != 2)
				{
					//GGTO: Add failure handling here
					WSACleanup(); //Initialized but not 2,2 , gotta release
					return false;
				}
			#else

			#endif
			return true;
		}

		bool _CleanUp()
		{
#ifdef _DEBUG
			std::cout << __FUNCTION__ <<std::endl;
#endif
			#ifdef _WIN32

			int iErrCode=WSACleanup();
			if(iErrCode!=0)
			{
				return false;
			}
			#else

			#endif


			return true;
		}
};


