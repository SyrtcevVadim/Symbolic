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

