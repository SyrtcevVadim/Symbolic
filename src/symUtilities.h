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

using std::string;
/// Deletes begining and trailing spaces from a provided string
string trim(string str);

/// Deletes all spaces from the provided string
string removeSpaces(string str);

/// Converts the number into string represetation
string numberToString(double number);

/// Converts the string into the integer
double stringToNumber(string str);