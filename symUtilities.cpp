#include"symUtilities.h"
#include<string>

using std::string;
using std::to_string;

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

string numberToString(double number)
{
	string result{ to_string(number) };
	
	while (result.back() == '0' || result.back() == '.')
	{
		result.erase(result.length() - 1, 1);
	}

	return result;
}