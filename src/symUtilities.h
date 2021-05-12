#pragma once
#include<string>

using std::string;
/// Deletes begining and trailing spaces from a provided string
string trim(string str);

/// Converts the number into string represetation
string numberToString(double number);

/// Converts the string into the integer
double stringToNumber(string &str);