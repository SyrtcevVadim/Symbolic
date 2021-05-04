#include "SymHelper.h"
#include<map>
#include<list>
#include<algorithm>
#include<string>
#include<iostream>

using std::string;
using std::list;
using std::map;
using std::cout;
using std::find;

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
								   "sin","cos","tg","tan","ctg","cot"
								   "arcsin","arccos","arctg","arctan","arcctg","arccot","arccotan",
								   "ln","lg","log",
								  };

map<string, int> SymHelper::operandQuantity{{"un-", 1},
                                             {"un+", 1},
                                             {"+", 2},
                                             {"-", 2},
                                             {"*", 2},
                                             {"/", 2},
                                             {"^", 2},
                                             {"abs", 1},
                                             {"pow", 2},
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
                                             {"log",2},
                                            };

list<string> SymHelper::parameters{"a","b","c","d"};


bool SymHelper::IsNumber(const string &str)
{
    if (!str.empty())
    {
        for (char symbol : str)
        {
            if ((symbol == '-' || symbol == '+') && str.size() == 1)
            {
                return false;
            }
            if (symbol < '0' || symbol > '9')
            {
                return false;
            }
        }
        cout << str << " is a number!\n";
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
