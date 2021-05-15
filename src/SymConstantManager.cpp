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

#include"SymConstantManager.h"
#include"SymParser.h"
#include<string>
#include<list>
#include<map>

using std::list;
using std::string;
using std::map;


map<string, string> SymConstantManager::predefinedConstants{{"pi", "3.141592"},
															{"e", "2.718281828"}};

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

bool SymConstantManager::HasConstants(string infix)
{
	for (string& token : SymParser::CreateTokenList(infix))
	{
		if (IsConstant(token))
		{
			return true;
		}
	}
	return false;
}

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

string SymConstantManager::GetConstantValue(const string& name)
{
	if (predefinedConstants.find(name) != predefinedConstants.end())
	{
		return predefinedConstants[name];
	}
	else if (userDefinedConstants.find(name) != userDefinedConstants.end())
	{
		return userDefinedConstants[name];
	}
	else
	{
		throw "'" + name + "' doesn't exist! Add this constant firstly!";
	}
}