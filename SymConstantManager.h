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
	/// 
	/// </summary>
	/// <param name="str"></param>
	/// <returns></returns>
	static bool IsConstant(const string& str);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="infix"></param>
	/// <returns></returns>	
	static bool HasConstants(const list<string>& infix);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="name"></param>
	/// <param name="value"></param>
	static void AddConstant(const string& name, const string& value);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="name"></param>
	static void RemoveConstant(const string& name);
	/// <summary>
	///
	/// </summary>
	/// <param name="name"></param>
	/// <param name="value"></param>
	static void AlterConstantValue(const string& name, const string& value);

	static string GetConstantValue(const string& name);


};

