#include"SymConstantManager.h"
#include"SymParser.h"
#include<string>
#include<list>
#include<map>

using std::list;
using std::string;
using std::map;


map<string, string> SymConstantManager::predefinedConstants{
															{"pi", "3.141592"},
															{"e", "2.718281828"}
														   };

map<string, string> SymConstantManager::userDefinedConstants;

bool SymConstantManager::IsConstant(const string& str)
{
	if (predefinedConstants.find(str) != predefinedConstants.end() ||
		userDefinedConstants.find(str) != userDefinedConstants.end())
	{
		return true;
	}
	return false;
}

/*bool SymConstantManager::HasConstants(const string& infixExpression)
{
	list<string> tokens = SymParser::Split(infixExpression);
	for (string token : tokens)
	{
		if (IsConstant(token))
		{
			return true;
		}
	}
	return false;
}*/

void SymConstantManager::AddConstant(const string& name, const string& value)
{
	// Checks for double entries of constant
	if (!IsConstant(name))
	{
		userDefinedConstants[name] = value;
	}
}

void SymConstantManager::RemoveConstant(const string& name)
{
	userDefinedConstants.erase(name);
}


void SymConstantManager::AlterConstantValue(const string& name, const string& value)
{
	if (IsConstant(name))
	{
		userDefinedConstants[name] = value;
	}
	else
	{
		throw "Constant " + name + " doen't exist! Use AddConstant method!";
	}
}