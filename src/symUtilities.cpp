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
	if (isnan(number) || isinf(number))
	{
		throw "'" + to_string(number) + "' isn't a decimal number!";
	}
	stringstream ss;
	ss << number;
	string result;
	ss >> result;
	return result;
}

double stringToNumber(string str)
{
	// Checks the correctness of the number
	if (!SymHelper::IsNumber(str))
	{
		throw "'" + str +"' isn't a correct decimal number!";
	}
	stringstream ss{ str };
	double result;
	ss >> result;
	return result;
}