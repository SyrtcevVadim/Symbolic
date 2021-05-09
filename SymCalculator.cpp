#include "SymCalculator.h"
#include "SymHelper.h"
#include "symUtilities.h"
#include<cmath>
#include<iostream>
#include<stack>
#include<string>

using std::cout;
using std::stack;
using std::string;

map<string, function<double(double, double)>> SymCalculator::functionHandlers{ 
	{"un+", nothing},
	{"un-", negate},
	{"+", sum},
	{"-", difference},
	{"*", product},
	{"/", quotient},
	{"^", power},
	{"abs", absolute},
	{"pow", power},
	{"sqr", square},
	{"sqrt",squareRoot},
	{"sin", sinus},
	{"cos", cosine},
	{"tg", tangent},
	{"tan", tangent},
	{"ctg", cotangent},
	{"cot", cotangent},
	{"arcsin", arcsinus},
	{"arccos", arccosine},
	{"arctg", arctangent},
	{"arctan", arctangent},
	{"arcctg", arccotangent},
	{"arccot", arccotangent},
	{"arccotan", arccotangent},
	{"ln", naturalLogarithm},
	{"lg", decimalLogarithm},
	{"log", logarithm}};

SymCalculator::SymCalculator(SymExpression* mathematicalExpression) :mathExpression(mathematicalExpression)
{}

void SymCalculator::setExpression(SymExpression* mathematicalExpression)
{
	mathExpression = mathematicalExpression;
}

double SymCalculator::nothing(double value, double)
{
	return value;
}

double SymCalculator::negate(double value, double)
{
	return -value;
}

double SymCalculator::absolute(double value, double)
{
	return abs(value);
}

double SymCalculator::sum(double lValue, double rValue)
{
	return lValue + rValue;
}

double SymCalculator::difference(double lValue, double rValue)
{
	return lValue - rValue;
}

double SymCalculator::product(double lValue, double rValue)
{
	return lValue * rValue;
}

double SymCalculator::quotient(double dividend, double divisor)
{
	return dividend / divisor;
}

double SymCalculator::power(double base, double power)
{
	return pow(base, power);
}

double SymCalculator::square(double value, double)
{
	return value * value;
}

double SymCalculator::squareRoot(double value, double)
{
	return sqrt(value);
}

double SymCalculator::sinus(double rad, double)
{
	return sin(rad);
}

double SymCalculator::cosine(double rad, double)
{
	return cos(rad);
}

double SymCalculator::tangent(double rad, double)
{
	return tan(rad);
}

double SymCalculator::cotangent(double rad, double)
{
	return 1.0 / tan(rad);
}

double SymCalculator::arcsinus(double value, double)
{
	return asin(value);
}

double SymCalculator::arccosine(double value, double)
{
	return acos(value);
}

double SymCalculator::arctangent(double value, double)
{
	return atan(value);
}

double SymCalculator::arccotangent(double value, double)
{
	// Pi/2 - arctangent(value) == arccotangent
	return 1.570796 - atan(value);
}

double SymCalculator::naturalLogarithm(double value, double)
{
	return log(value);
}

double SymCalculator::decimalLogarithm(double value, double)
{
	return  log10(value);
}

double SymCalculator::logarithm(double base, double value)
{
	return log(value) / log(base);
}

double SymCalculator::compute(double variableValue)
{
	list<string> postfix = mathExpression->substituteVariableValue(variableValue);
	stack<string> stack;
	//for (string token : postfix)
	//{
	//	cout << token << " ";
	//}
	//cout << '\n';

	for (string token : postfix)
	{
		//cout << "\nCurrent token: " << token << "\n";
		// Pushs every number to stack of intermediate values
		if (SymHelper::IsNumber(token))
		{
			//cout << "Is a number!\n";
			stack.push(token);
		}
		else if (SymHelper::IsOperation(token) ||
			SymHelper::IsFunction(token))
		{
			//cout << "Is an operation/function\n";


			// Checks how many operands does this operation/function
			// require
			int operandQuantity = SymHelper::GetOperandQuantity(token);
			//cout << "It requires " << operandQuantity << " operands!\n";

			if (stack.size() < operandQuantity)
			{
				throw "Wrong number of operands for '" + token + "'";
			}
			// Fetchs operands from the stack
			
			if (operandQuantity == 1)
			{
				double secondOperand = stringToNumber(stack.top());
				stack.pop();
				stack.push(numberToString(functionHandlers[token](secondOperand, 0.0)));
			}
			else if (operandQuantity == 2)
			{
				double secondOperand = stringToNumber(stack.top());
				stack.pop();
				double firstOperand = stringToNumber(stack.top());
				stack.pop();
				stack.push(numberToString(functionHandlers[token](firstOperand, secondOperand)));
				
			}
		}
	}

	// Fetching the result;
	//cout << "result is: " << stack.top() << '\n';
	return stringToNumber(stack.top());
}