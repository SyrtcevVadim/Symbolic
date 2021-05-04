#include"SymParser.h"
#include<string>
#include<iostream>
#include<sstream>
#include<regex>
#include<list>

using std::string;
using std::regex;
using std::stringstream;
using std::regex_replace;
using std::cout;

list<string> SymParser::delimiters({"(",")","[","]","{","}",		// Brackets
									"+","-","*","/","^",			// Operators
									",",";" });						// Delimiters

list<string> SymParser::Split(const string& str)
{
	list<string> result;
	string currentToken{ "" };
	stringstream ss{ str };
	while (ss >> currentToken)
	{
		if (!currentToken.empty())
		{
			result.push_back(currentToken);
		}
	}
	return result;
}

list<string> SymParser::CreateTokenList(string initialExpression)
{
	if (!initialExpression.empty())
	{
		for (string delimiter : delimiters)
		{
			initialExpression = regex_replace(initialExpression, regex("\\"+delimiter), " " + delimiter + " ");
			
		}
		return Split(initialExpression);
	}
	else
	{
		return list<string>();
	}
}