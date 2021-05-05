#pragma once
#include<string>
#include<list>
#include<map>

using std::string;
using std::list;
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
	/// Makes mathematical expression in postfix form from the list of tokens of mathematical expression in infix form
	/// </summary>
	/// <param name="tokens">List of tokens of mathematical expression in infix form</param>
	/// <returns>List of tokens of mathematical expression in postfix form</returns>
	static list<string> InfixToPostfix(const list<string> &tokens);
};

