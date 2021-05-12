#include"SymFormConverter.h"
#include"symUtilities.h"
#include"SymHelper.h"
#include"SymConstantManager.h"
#include<iostream>
#include<string>
#include<list>
#include<stack>

using std::string;
using std::list;
using std::stack;
using std::cout;

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

   /* string str = "";
    for (string i : tokens)
    {
        str += i;
    }*/
    //cout << "\t\t\tExpression: " << str << '\n';

    // Iterates through the list of tokens
    for (string token : tokens)
    {
        //cout << "token: " << token <<'\n';
        // Processing unary plus and unary minus operation
        if ((token == "+" || token == "-") && (previous.empty() || SymHelper::IsOpeningBracket(previous) || SymHelper::IsSeparator(previous) ||
            SymHelper::IsOperation(previous)))
        {
            token = "un" + token;
            //cout << "is an unary: " << token << "\n";
            // Check the precedence of the function at the stack's top
            if (!stack.empty() && (SymHelper::IsFunction(stack.top()) || SymHelper::IsOperation(stack.top())) && (precedence[stack.top()] < precedence[token] ||
                (precedence[stack.top()] == precedence[token] && token != "^"&&stack.top() != "^")))
            {
                //cout << stack.top() << " was poped from the stack's top\n";
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
            //cout << "is an opening bracket\n";
            stack.push(token);
        }
        // Process closing parathesis
        else if (token == ")")
        {
            //cout << "is a closing round bracket\n";
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
            //cout << "is a closing square bracket\n";
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
            //cout << "is a closing curly bracket\n";
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
            //cout << "is a separator\n";
            // Pops everything from the stack until we face with opening parenthesis
            while (!stack.empty() && !SymHelper::IsOpeningBracket(stack.top()))
            {
                result.push_back(stack.top());
                stack.pop();
            }
            if (stack.empty())
            {
                throw "Opening bracket inside the provided mathematical expression is missed";
            }
        }
        else if (SymHelper::IsFunction(token) || SymHelper::IsOperation(token))
        {
            //cout << "is an operation/function\n";
            // every function is pushed to the stack
            // Check the precedence of the function at the stack's top
            if (!stack.empty() && (SymHelper::IsFunction(stack.top()) || SymHelper::IsOperation(stack.top())) && (precedence[stack.top()] < precedence[token] ||
                (precedence[stack.top()] == precedence[token] && token != "^")))
            {
                //cout << stack.top() << " was poped from the stack's top\n";
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
    //str = "";
    //for (string i : result)
    //{
    //    str += i+" ";
    //}
    ////cout << "\t\tResult: " << str << '\n';

    return result;
}
