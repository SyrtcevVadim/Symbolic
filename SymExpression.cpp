#include"SymExpression.h"
#include"SymParser.h"
#include"SymFormConverter.h"
#include"symUtilities.h"
#include<string>
#include<list>
#include<map>

using std::list;
using std::string;

SymExpression::SymExpression()
{
	// Sets 1 as an initial value of parameters
	parameters["a"] = parameters["b"] = parameters["c"] = parameters["d"] = 1.0;
	initial = "";
	infix = "";
	postfix = "";
}

SymExpression::SymExpression(string initialExpression) :SymExpression()
{
	list<string> tokens = SymParser::CreateTokenList(initialExpression);
	// Brings the initial and infix expression to the standart view(space between every pair of tokens without any excess spaces)
	for (string token : tokens)
	{
		initial += token + " ";
		infix += token + " ";
	}
	initial = trim(initial);
	infix = trim(infix);

	// Creates the postfix form of mathematical expression
	postfix = SymFormConverter::InfixToPostfix(tokens);
}

void SymExpression::setExpression(string initialExpression)
{

}

void SymExpression::setParameterValue(string name, double value)
{

}

void SymExpression::setParameterValues(double aValue, double bValue, double cValue, double dValue)
{
	parameters["a"] = aValue;
	parameters["b"] = bValue;
	parameters["c"] = cValue;
	parameters["d"] = dValue;
}