#ifndef LS_TIME_H
#define LS_TIME_H

#include "time.h"
#include "string"

namespace ls
{
	namespace time
	{
		class API
		{
			public:
				std::string getStandardTime(int timeout = 0);
				std::string getServerTime(int timeout = 0);
				std::string getCookieTime(int timeout = 0);
				long long getCurrentMillionSecond();
				long long getCurrentMS();
			protected:
				struct tm getSeed(int timeout);
				
		};
		
		extern API api;
	}
}

#endif
