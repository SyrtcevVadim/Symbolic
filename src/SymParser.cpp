/*
Copyright 2021 Syrtcev Vadim Igorevich

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include"SymParser.h"
#include<string>
#include<sstream>
#include<regex>
#include<list>

using std::string;
using std::regex;
using std::stringstream;
using std::regex_replace;

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