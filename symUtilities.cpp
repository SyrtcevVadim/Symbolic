#include"symUtilities.h"
#include<string>

using std::string;

string trim(string str)
{
	// Deletes spaces from the end of the string
	while (str.back() == ' ')
	{
		str.erase(str.size() - 1, 1);
	}
	// Deletes spaces from the begining of the string
	while (str.front() == ' ')
	{
		str.erase(0, 1);
	}
	return str;
}