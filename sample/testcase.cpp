#include "ls/time/API.h"
#include "iostream"

using namespace std;

int main()
{
	cout << "getStandardTime(): " <<  ls::time::api.getStandardTime() << endl;
	cout << "getServerTime(): " << ls::time::api.getServerTime() << endl;
	cout << "getCurrentMillionSecond(): " << ls::time::api.getCurrentMillionSecond() << endl;
	cout << "getCookieTime(): " << ls::time::api.getCookieTime() << endl;

	return 0;
}
