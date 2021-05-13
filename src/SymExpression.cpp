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

#include"SymExpression.h"
#include"SymHelper.h"
#include"SymParser.h"
#include"SymFormConverter.h"
#include"SymConstantManager.h"
#include"symUtilities.h"
#include<string>
#include<list>
#include<map>
#include<cmath>

using std::list;
using std::to_string;
using std::string;

SymExpression::SymExpression()
{
	// Initialize parameters by their standart values
	setParameterValues();
	set("");
}

SymExpression::SymExpression(string mathematicalExpression)
{
	// Initialize parameters by their standart values
	setParameterValues();
	set(mathematicalExpression);
}

SymExpression::SymExpression(const char* mathematicalExpression)
{
	setParameterValues();
	set(mathematicalExpression);
}

list<string> SymExpression::substituteConstantValues(const list<string> &infix)
{
	list<string> temp = infix;
	while(SymConstantManager::HasConstants(temp))
	{
		list<string> result;
		for (string token : temp)
		{
			if (SymConstantManager::IsConstant(token))
			{
				result.push_back(SymConstantManager::GetConstantValue(token));
			}
			else
			{
				result.push_back(token);
			}
		}
		temp = result;
	}
	return temp;
}

void SymExpression::set(string mathematicalExpression)
{
	list<string> infixList = SymParser::CreateTokenList(mathematicalExpression);
	initial = "";
	// Brings the initial expression to the standart view(expression without any spaces)
	for (string token : infixList)
	{
		initial += token;
	}
	// Substitutes constants' values in mathematical expression in infix form
	infix = substituteConstantValues(infixList);
	// Creates the postfix form of mathematical expression
	postfix = SymFormConverter::InfixToPostfix(infix);
}

void SymExpression::setParameterValue(const string &name, double value)
{
	if (!SymHelper::IsParameter(name))
	{
		throw "'" + name + "' isn't a parameter! There're only four parameters: 'a','b','c','d'. In setParameterValue() function";
	}
	else
	{
		if (isinf(value) || isnan(value))
		{
			throw "'" + numberToString(value) + "' isn't a decimal number! In setParameterValue() function";
			
		}
		parameters[name] = value;
	}
}

double SymExpression::getParameterValue(const string& name)
{
	if (!SymHelper::IsParameter(name))
	{
		throw "'" + name + "' isn't a parameter! There're only four parameters: 'a','b','c','d'. In getParameterValue() function";
	}
	return parameters[name];
}

void SymExpression::setParameterValues(double aValue, double bValue, double cValue, double dValue)
{
	setParameterValue("a", aValue);
	setParameterValue("b", bValue);
	setParameterValue("c", cValue);
	setParameterValue("d", dValue);
}

string SymExpression::get()const
{
	return initial;
}

list<string>& SymExpression::getInfix()
{
	return infix;
}

list<string>& SymExpression::getPostfix()
{
	return postfix;
}