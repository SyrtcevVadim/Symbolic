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
#include"SymHelper.h"
#include<map>
#include<list>
#include<algorithm>
#include<string>
#include<regex>

using std::string;
using std::list;
using std::map;
using std::find;
using std::regex_match;
using std::regex;

list<string> SymHelper::tokens{"(",")","[","]","{","}",
								",",";",
								"+","-","*","/","^",
								"abs", "pow", "sqr","sqrt",
								"sin", "cos", "tg", "tan","ctg","cot",
								"arcsin","arccos","arctg","arctan","arcctg","arccot","arccotan",
								"ln", "lg", "log",
								"x", "X",
								"a", "b","c","d",
								"pi", "e"
							   };

list<string> SymHelper::operations{"un+","un-","+","-","*","/","^"};

list<string> SymHelper::functions{"abs","pow","sqr","sqrt",
								   "sin","cos","tg","tan","ctg","cot",
								   "arcsin","arccos","arctg","arctan","arcctg","arccot","arccotan",
								   "ln","lg","log",
								  };

map<string, int> SymHelper::operandQuantity{
    {"un-", 1},
    {"un+", 1},
    {"+", 2},
    {"-", 2},
    {"*", 2},
    {"/", 2},
    {"^", 2},
    {"abs", 1},
    {"pow", 2},
    {"sqr", 1},
    {"sqrt", 1},
    {"sin", 1},
    {"cos", 1},
    {"tg", 1},
    {"tan",1},
    {"ctg", 1},
    {"cot", 1},
    {"arcsin", 1},
    {"arccos", 1},
    {"arctg", 1},
    {"arctan", 1},
    {"arcctg", 1},
    {"arccot",1},
    {"arccotan", 1},
    {"lg", 1},
    {"ln", 1},
    {"log",2}
};

list<string> SymHelper::parameters{"a","b","c","d"};


bool SymHelper::IsNumber(const string &str)
{
    if (regex_match(str, regex(R"([\+-]?[\d]+(.[\d]+)?)")))
    {
        return true;
    }
    return false;
}

bool SymHelper::IsSeparator(const string &str)
{
    if (str == "," || str == ";")
    {
        return true;
    }
    return false;
}

bool SymHelper::IsVariable(const string &str)
{
    if (str == "x" || str == "X")
    {
        return true;
    }
    return false;
}

bool SymHelper::IsParameter(const string &str)
{
    list<string>& l = SymHelper::parameters;
    if (find(l.begin(), l.end(), str) != l.end())
    {
        return true;
    }
    return false;
}

bool SymHelper::IsCorrect(const string &str)
{
    list<string>& l = SymHelper::tokens;
    if (find(l.begin(), l.end(), str) != l.end())
    {
        return true;
    }
    return false;
}

bool SymHelper::IsOperation(const string &str)
{
    list<string>& l = SymHelper::operations;
    if (find(l.begin(), l.end(), str) != l.end())
    {
        return true;
    }
    return false;
}

bool SymHelper::IsFunction(const string &str)
{
    list<string>& l = SymHelper::functions;
    if (find(l.begin(), l.end(), str) != l.end())
    {
        return true;
    }
    return false;
}

bool SymHelper::IsOpeningBracket(const string& str)
{
    if (str == "(" || str == "[" || str == "{")
    {
        return true;
    }
    return false;
}

bool SymHelper::IsClosingBracket(const string& str)
{
    if (str == ")" || str == "]" || str == "}")
    {
        return true;
    }
    return false;
}

int SymHelper::GetOperandQuantity(const string& op)
{
    return operandQuantity[op];
}