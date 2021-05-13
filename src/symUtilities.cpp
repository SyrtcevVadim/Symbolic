#include"symUtilities.h"
#include"SymHelper.h"
#include<sstream>
#include<string>

using std::string;
using std::stringstream;
using std::to_string;

string trim(string str)
{
	stringstream ss{ str };
	ss >> str;
	return str;
}

string numberToString(double number)
{
	stringstream ss;
	ss << number;
	string result;
	ss >> result;
	return result;
}

double stringToNumber(string str)
{
	stringstream ss{ str };
	double result;
	ss >> result;
	return result;
}