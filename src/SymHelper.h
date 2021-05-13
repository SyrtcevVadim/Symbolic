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
#include<map>
#include<list>
#include<string>

using std::string;
using std::map;
using std::list;

class SymHelper
{
private:
    /// <summary>
    /// Stores the correct tokens for mathematical expressions
    /// </summary>
    static list<string> tokens;

    /// <summary>
    /// Stores correct operations
    /// </summary>
    static list<string> operations;

    /// <summary>
    /// stores correct function names
    /// </summary>
    static list<string> functions;

    /// <summary>
    /// Stores quantite of operands for every correct operation/function
    /// </summary>
    static map<string, int> operandQuantity;

    /// <summary>
    /// Stores parameters' names
    /// </summary>
    static list<string> parameters;

public:
    /// <summary>
    /// Checks whether provided string stores a decimal number or not
    /// </summary>
    static bool IsNumber(const string &str);

    /// <summary>
    /// Checks whether provided string stores a separator or not
    /// </summary>
    static bool IsSeparator(const string &str);

    /// <summary>
    /// Checks whether provided string stores a variable or not
    /// </summary>
    static bool IsVariable(const string &str);

    /// <summary>
    /// Cheks whether provided string stores a parameter or not
    /// </summary>
    static bool IsParameter(const string &str);
    
    /// <summary>
    /// Checks whether provided string stores an operation or not
    /// </summary>
    static bool IsOperation(const string &str);

    /// <summary>
    /// Checks whether provided string stores a function or not
    /// </summary>
    static bool IsFunction(const string &str);

    /// <summary>
    /// Checks whether provided string stores a correct token or not
    /// </summary>
    static bool IsCorrect(const string &str);

    /// <summary>
    /// Checks whether provided string stores an opening bracket or not
    /// </summary>
    static bool IsOpeningBracket(const string &str);

    /// <summary>
    /// Checks whether provided string stores a closing bracket or not
    /// </summary>
    static bool IsClosingBracket(const string &str);

    /// <summary>
    /// Returns the number of operands that operation/function 
    /// requires
    /// </summary>
    static int GetOperandQuantity(const string& op);
};

