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
#include"symUtilities.h"
#include"SymHelper.h"
#include<sstream>
#include<string>

using std::string;
using std::stringstream;
using std::to_string;

string trim(string str)
{
	stringstream ss{ str };
	ss >> str;
	return str;
}

string numberToString(double number)
{
	stringstream ss;
	ss << number;
	string result;
	ss >> result;
	return result;
}

double stringToNumber(string str)
{
	stringstream ss{ str };
	double result;
	ss >> result;
	return result;
}