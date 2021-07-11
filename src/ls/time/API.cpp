#include "ls/time/API.h"

using namespace std;

namespace ls
{
	namespace time
	{
		struct tm API::getSeed(int timeout)
		{
			time_t t = ::time(NULL) + timeout;
			struct tm lt;
			localtime_r(&t, &lt);
			return lt;
		}

		string API::getStandardTime(int timeout)
		{
			char buffer[64];
			struct tm lt = getSeed(timeout);
			strftime(buffer, sizeof(buffer), "%F %T", &lt);
			return buffer;
		}

		string API::getServerTime(int timeout)
		{
			char buffer[64] = {};
			struct tm lt = getSeed(timeout);
			strftime(buffer, sizeof(buffer), "%a, %d %b %Y %T GMT", &lt);
			return buffer;
		}

		string API::getCookieTime(int timeout)
		{
			char buffer[64] = {};
			struct tm lt = getSeed(timeout);
			strftime(buffer, sizeof(buffer), "%a, %d-%b-%Y %T GMT", &lt);
			return buffer;
		}

		long long API::getCurrentMillionSecond()
		{
			struct timespec tm;
			clock_gettime(CLOCK_MONOTONIC, &tm);
			return tm.tv_nsec + tm.tv_sec * 1000000000;
		}

		API api;
	}
}
