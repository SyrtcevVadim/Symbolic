#pragma once
#include<string>
#include<list>
#include<map>
using std::string;
using std::list;
using std::map;

class SymConstantManager
{
private:
	static map<string, string> predefinedConstants;
	static map<string, string> userDefinedConstants;

public:
	/// <summary>
	/// Checks whether constant with provided name exists or not
	/// </summary>
	static bool IsConstant(const string& str);
	
	/// <summary>
	/// Checks whether provided list of tokens of mathematical expression
	/// in infix form contains constants
	/// </summary>
	/// <param name="infix">List of tokens of mathematical expression in infix form</param>
	static bool HasConstants(const list<string>& infix);
	/// <summary>
	/// Adds new constant with provided value. If constant with the same
	/// name have been already created it does nothing
	/// </summary>
	/// <param name="name">Name of the new constant</param>
	/// <param name="value">Value of the new constant</param>
	static void AddConstant(const string& name, const string& value);
	/// <summary>
	/// Removes an existing constant by it's name. 
	/// It's possible to remove constants which have been 
	/// added by user
	/// </summary>
	static void RemoveConstant(const string& name);
	/// <summary>
	/// Alters the value of an existing constant. 
	/// It's possible to alter value of constants which have been
	/// added by user
	/// </summary>
	/// <param name="name">Name of the constant</param>
	/// <param name="value">New value of the constant</param>
	static void AlterConstantValue(const string& name, const string& value);

	/// <summary>
	/// Returns the value of constant
	/// </summary>
	/// <param name="name">Name of constant</param>
	static string GetConstantValue(const string& name);


};

