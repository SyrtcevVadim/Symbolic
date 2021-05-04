#include"SymExpression.h"
#include<string>
#include<map>

SymExpression::SymExpression()
{
	// Sets 1 as an initial value of parameters
	

	initialExpression = "";
	infixExpression = "";
	postfixExpression = "";
}

SymExpression::SymExpression(string initialExpression)
{

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