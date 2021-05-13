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

