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

