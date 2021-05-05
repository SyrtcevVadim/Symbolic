#pragma once
#include<string>
#include<list>
using namespace std;

class SymParser
{
private:
	/// <summary>
	/// Stores the delimiters for parsing the mathematical expression
	/// </summary>
	static list<string> delimiters;

	/// <summary>
	/// Converts provided mathematical expression into list of tokens
	/// </summary>
	/// <returns>List of tokens of provided mathematical expression</returns>
	static list<string> Split(const string& str);
	
public:
	/// <summary>
	/// Creates a token list of the provided mathematical expression
	/// </summary>
	/// <param name="initialExpression">User-provided mathematical expression</param>
	/// <returns></returns>
	static list<string> CreateTokenList(string initialExpression);
};

