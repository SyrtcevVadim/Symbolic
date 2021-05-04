#pragma once
#include<string>
#include<map>

using std::string;
using std::map;

class SymFormConverter
{
private:
	/// <summary>
	/// Stores the precedence for every supported operation and function
	/// </summary>
	static map<string, int> precedence;

public: 
	/// <summary>
	/// Converts mathematical expression from infix form to postfix one
	/// </summary>
	/// <param name="infixExpression">Mathematical expression in infix form</param>
	/// <returns>Mathematical expression in postfix form</returns>
	static string InfixToPostfix(const string& infixExpression);
};

