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
#include "SymVerifier.h"
#include "SymParser.h"
#include "SymFormConverter.h"
#include "SymConstantManager.h"
#include<string>
#include<stack>
#include<list>

using std::stack;
using std::list;
using std::string;

SymVerifier::SymVerifier(const string& expression)
{
	tokens = SymParser::CreateTokenList(expression);
	clearError();
}

void SymVerifier::clearError()
{
	errorMessage.clear();
	incorrectPlace.clear();
	errorType = SymError::NO_ERROR;
}

bool SymVerifier::areAllTokensCorrect()
{
	clearError();
	for (string& token : tokens)
	{
		if (!SymHelper::IsCorrect(token) && !SymHelper::IsNumber(token))
		{
			incorrectPlace = token;
			errorType = SymError::INCORRECT_TOKEN;
			errorMessage = "Unknown token \"" + token + "\" was received";
			return false;
		}
	}
	return true;
}

bool SymVerifier::areBracketsCorrespond()
{
	clearError();
	stack<string> stack;
	for (string& token : tokens)
	{
		if (!SymHelper::IsClosingBracket(token) && !SymHelper::IsOpeningBracket(token))
		{
			continue;
		}
		if (SymHelper::IsOpeningBracket(token))
		{
			stack.push(token);
		}
		else if (SymHelper::IsClosingBracket(token))
		{
			if (stack.empty() || (token == ")" && stack.top() != "(") ||
				(token == "]" && stack.top() != "[") ||
				(token == "}" && stack.top() != "{"))
			{
				incorrectPlace = token;
				errorType = SymError::INCORRECT_BRACKETS;
				if (token == ")")
				{
					errorMessage = "Opening round bracket was missed";
				}
				else if (token == "]")
				{
					errorMessage = "Opening square bracket was missed";
				}
				else if (token == "}")
				{
					errorMessage = "Opening curly bracket was missed";
				}
				return false;
			}
			stack.pop();
		}
	}
	if (!stack.empty())
	{
		incorrectPlace = stack.top();
		errorType = SymError::INCORRECT_BRACKETS;
		if (stack.top() == "(")
		{
			errorMessage = "Closing round bracket was missed";
		}
		else if (stack.top() == "[")
		{
			errorMessage = "Closing square bracket was missed";
		}
		else if (stack.top() == "{")
		{
			errorMessage = "Closing curly bracket was missed";
		}
		return false;
	}
	return true;
}

bool SymVerifier::hasEmptyBrackets()
{
	clearError();
	string prevToken{ "" };
	for (string& currToken : tokens)
	{
		if (SymHelper::IsOpeningBracket(prevToken) &&
			SymHelper::IsClosingBracket(currToken))
		{
			incorrectPlace = prevToken + " " + currToken;
			errorType = SymError::EMPTY_BRACKETS;
			errorMessage = "Missed expression between " + incorrectPlace;
			return true;
		}
		prevToken = currToken;
	}
	return false;
}

bool SymVerifier::hasMissedOperations()
{
	clearError();
	string prevToken{ "" };
	for (string& currToken : tokens)
	{
		if ((SymHelper::IsNumber(prevToken) ||
			SymHelper::IsParameter(prevToken) ||
			SymHelper::IsVariable(prevToken)||
			SymConstantManager::IsConstant(prevToken)||
			SymHelper::IsOpeningBracket(prevToken)) &&
			!SymHelper::IsOperation(currToken))
		{
			incorrectPlace = prevToken + " " + currToken;
			errorType = SymError::MISSED_OPERATION;
			errorMessage = "Missed operation between " + incorrectPlace;
			return true;
		}
		prevToken = currToken;
	}
	return false;
}

bool SymVerifier::hasMissedOperands()
{
	clearError();
	list<string> postfix = SymFormConverter::InfixToPostfix(tokens);
	// Stores intermediate values
	stack<double> stack;

	// Iterate through the expression in postfix form
	for (string& token : postfix)
	{
		if (SymHelper::IsNumber(token) ||
			SymHelper::IsParameter(token)||
			SymHelper::IsVariable(token) ||
			SymConstantManager::IsConstant(token))
		{
			stack.push(1);
		}
		else if (SymHelper::IsFunction(token) || 
				SymHelper::IsOperation(token))
		{
			// Checks how many operands does this operation/function
			// requires
			int operandQuantity = SymHelper::GetOperandQuantity(token);
			
			if (stack.size() < operandQuantity)
			{
				incorrectPlace = token;
				errorType = SymError::MISSED_OPERANDS;
				if (SymHelper::IsOperation(token))
				{
					errorMessage = "Operation \"" + token + "\" requires " +
						"12"[operandQuantity] + " operands";
				}
				else
				{
					errorMessage = "Function \"" + token + "\" requires " +
						"12"[operandQuantity] + " operands";
				}
				return true;
			}

			else if (operandQuantity == 2)
			{
				stack.pop();
				stack.pop();
				stack.push(1);
			}
		}
	}
	return false;
}

bool SymVerifier::isCorrect()
{
	clearError();
	if (
		areAllTokensCorrect() &&
		areBracketsCorrespond() &&
		!hasEmptyBrackets() &&
		!hasMissedOperands() &&
		!hasMissedOperations())
	{
		return true;
	}
	return false;
}

string SymVerifier::getErrorMessage()
{
	return errorMessage;
}

string SymVerifier::getIncorrectPlace()
{
	return incorrectPlace;
}

SymError SymVerifier::getErrorType()
{
	return errorType;
}