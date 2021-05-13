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

#include"SymFormConverter.h"
#include"symUtilities.h"
#include"SymHelper.h"
#include"SymConstantManager.h"
#include<string>
#include<list>
#include<stack>

using std::string;
using std::list;
using std::stack;

map<string, int> SymFormConverter::precedence{ {
    {"abs", 1},
    {"pow", 1},
    {"sqrt", 1},
    {"sin", 1},
    {"cos", 1},
    {"arcsin", 1},
    {"arccos", 1},
    {"arctg", 1},
    {"arctan", 1},
    {"arcctg", 1},
    {"arccot", 1},
    {"arccotan", 1},
    {"tg", 1},
    {"tan", 1},
    {"ctg", 1},
    {"cot", 1},
    {"lg", 1},                                      
    {"ln", 1},                               
    {"log", 1},                              
    {"un-", 2},                                 
    {"un+", 2},
    {"^", 2},
    {"*", 3},
    {"/", 3},
    {"+", 4},  
    {"-", 4}                                             
    }};

list<string> SymFormConverter::InfixToPostfix(const list<string> &tokens)
{
    // Creates a stack for storing intermediate values
    stack<string> stack;
    // List of tokens of result expression in postfix form
    list<string> result;
    // Stores previous token
    string previous{ "" };

    // Iterates through the list of tokens
    for (string token : tokens)
    {
        // Processing unary plus and unary minus operation
        if ((token == "+" || token == "-") && (previous.empty() || SymHelper::IsOpeningBracket(previous) || SymHelper::IsSeparator(previous) ||
            SymHelper::IsOperation(previous)))
        {
            token = "un" + token;
            // Check the precedence of the function at the stack's top
            if (!stack.empty() && (SymHelper::IsFunction(stack.top()) || SymHelper::IsOperation(stack.top())) && (precedence[stack.top()] < precedence[token] ||
                (precedence[stack.top()] == precedence[token] && token != "^"&&stack.top() != "^")))
            {
                result.push_back(stack.top());
                stack.pop();
            }
            stack.push(token); // un+ or un-
        }
        // If token is a decimal number, variable, parameter or constant, we simply add it to the result list of tokens
        else if (SymHelper::IsNumber(token) || SymHelper::IsVariable(token) || SymHelper::IsParameter(token) || 
                 SymConstantManager::IsConstant(token))
        {
            result.push_back(token);
        }
        // Process opening brackets
        else if (SymHelper::IsOpeningBracket(token))
        {
            stack.push(token);
        }
        // Process closing parathesis
        else if (token == ")")
        {
            // Pops everything from stack until we reach opening round bracket
            while (!stack.empty() && stack.top() != "(")
            {
                result.push_back(stack.top());
                stack.pop();
            }
            if (!stack.empty() && stack.top() == "(")
            {
                // Get rid of opening round bracket
                stack.pop();
            }
        }
        else if (token == "]")
        {
            // Pops everything from stack until we reach opening square bracket
            while (!stack.empty() && stack.top() != "[")
            {
                result.push_back(stack.top());
                stack.pop();
            }
            if (!stack.empty() && stack.top() == "[")
            {
                // Get rid of opening square bracket
                stack.pop();
            }
        }
        else if (token == "}")
        {
            // Pops everything from stack until we reach opening curly bracket
            while (!stack.empty() && stack.top() != "{")
            {
                result.push_back(stack.top());
                stack.pop();
            }
            if (!stack.empty() && stack.top() == "{")
            {
                // Get rid of opening curly bracket
                stack.pop();
            }
        }
        else if (SymHelper::IsSeparator(token))
        {
            // Pops everything from the stack until we face with opening parenthesis
            while (!stack.empty() && !SymHelper::IsOpeningBracket(stack.top()))
            {
                result.push_back(stack.top());
                stack.pop();
            }
            if (stack.empty())
            {
                throw "Opening bracket is missed";
            }
        }
        else if (SymHelper::IsFunction(token) || SymHelper::IsOperation(token))
        {
            // every function is pushed to the stack
            // Check the precedence of the function at the stack's top
            if (!stack.empty() && (SymHelper::IsFunction(stack.top()) || SymHelper::IsOperation(stack.top())) && (precedence[stack.top()] < precedence[token] ||
                (precedence[stack.top()] == precedence[token] && token != "^")))
            {
                result.push_back(stack.top());
                stack.pop();
                
            }
            stack.push(token);
        }
        previous = token;
    }
    // If stack isn't empty, we add everything from it to the result
    while (!stack.empty())
    {
        result.push_back(stack.top());
        stack.pop();
    }
    return result;
}
