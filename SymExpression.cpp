#include"SymExpression.h"
#include"SymHelper.h"
#include"SymParser.h"
#include"SymFormConverter.h"
#include"SymConstantManager.h"
#include"symUtilities.h"
#include<string>
#include<list>
#include<map>
#include<math.h>

using std::list;
using std::to_string;
using std::string;

SymExpression::SymExpression()
{
	// Initialize parameters by their standart values
	setParameterValues();
	initial = "";
}

SymExpression::SymExpression(string mathematicalExpression)
{
	// Initialize parameters by their standart values
	setParameterValues();
	setExpression(mathematicalExpression);
}

SymExpression::SymExpression(const char* mathematicalExpression)
{
	setParameterValues();
	setExpression(mathematicalExpression);
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

list<string> SymExpression::subsituteParameterValues(const list<string> &postfix)
{
	list<string> result;
	for (string token : postfix)
	{
		if (SymHelper::IsParameter(token))
		{
			result.push_back(numberToString(parameters[token]));
		}
		else
		{
			result.push_back(token);
		}
	}
	return result;
}

list<string> SymExpression::substituteVariableValue(double value)
{
	if (isnan(value) || isinf(value))
	{
		throw "'" + to_string(value) + "' isn't a decimal number! Function substituteVariableValue() accepts only decimal numbers";
	}

	list<string> result;

	for (string token : postfix)
	{
		if (SymHelper::IsVariable(token))
		{
			result.push_back(numberToString(value));
		}
		else
		{
			result.push_back(token);
		}
	}
	return result;
}

void SymExpression::setExpression(string mathematicalExpression)
{
	list<string> infixList = SymParser::CreateTokenList(mathematicalExpression);
	initial = "";
	// Brings the initial and infix expression to the standart view(space between every pair of tokens without any excess spaces)
	for (string token : infixList)
	{
		initial += token;
	}
	// Substitutes constants' values in mathematical expression in infix form
	infix = substituteConstantValues(infixList);
	// Creates the postfix form of mathematical expression and substitutes 
	// the parameters' values
	postfix = subsituteParameterValues(SymFormConverter::InfixToPostfix(infix));
}

void SymExpression::setParameterValue(const string &name, double value)
{
	if (!SymHelper::IsParameter(name))
	{
		throw "'" + name + "' isn't a parameter! There're only four parameters: 'a','b','c','d'";
	}
	else
	{
		if (isinf(value) || isnan(value))
		{
			throw "'" + numberToString(value) + "' isn't a decimal number!";
			
		}
		parameters[name] = value;
	}
}

double SymExpression::getParameterValue(const string& name)
{
	if (!SymHelper::IsParameter(name))
	{
		throw "'" + name + "' isn't a parameter! There're only four parameters: 'a','b','c','d'";
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

string SymExpression::getExpression()const
{
	return initial;
}

list<string> SymExpression::getInfix()const
{
	return infix;
}

list<string> SymExpression::getPostfix()const
{
	return postfix;
}