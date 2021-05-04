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

map<string, int> SymFormConverter::precedence{ { {"abs", 1},
                                                 {"pow", 1},
                                                 {"sqrt", 1},
                                                 {"sin", 1},
                                                 {"cos", 1},
                                                 {"arcsin", 1},
                                                 {"arccos", 1},
                                                 {"arctg", 1},
                                                 {"arcctg", 1},
                                                 {"tg", 1},
                                                 {"ctg", 1},
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


string SymFormConverter::InfixToPostfix(const list<string> &tokens)
{
    // Creates a stack for storing intermediate values
    stack<string> stack;
    string result{ "" };
    // Stores previous token
    string previous{ "" };
    string input{ "" };
    for (string s : tokens)
    {
        input += s;
    }
    cout <<"\n\n\texpression: "<< input << '\n';
    // Iterates through the list of tokens
    for (string token : tokens)
    {
        cout << "token: " << token <<'\n';
        // Processing unary plus and unary minus operation
        if ((token == "+" || token == "-") && (previous.empty() || SymHelper::IsOpeningBracket(previous) || SymHelper::IsSeparator(previous) ||
            SymHelper::IsOperation(previous)))
        {
            token = "un" + token;
            cout << "is an unary: " << token << "\n";
            // Check the precedence of the function at the stack's top
            if (!stack.empty() && (SymHelper::IsFunction(stack.top()) || SymHelper::IsOperation(stack.top())) && (precedence[stack.top()] < precedence[token] ||
                (precedence[stack.top()] == precedence[token] && token != "^"&&stack.top() != "^")))
            {
                cout << stack.top() << " was poped from the stack's top\n";
                result += stack.top() + " ";
                stack.pop();
            }
            stack.push(token); // un+ or un-
        }
        // If token is a decimal number, we push it to the result string
        else if (SymHelper::IsNumber(token))
        {
            cout << "is a number\n";
            result += token + " ";
        }
        else if (SymHelper::IsVariable(token))
        {
            cout << "is a variable\n";
            result += token + " ";
        }
        else if (SymHelper::IsParameter(token))
        {
            cout << "is a parameter\n";
            result += token + " ";
        }
        else if (SymConstantManager::IsConstant(token))
        {
            cout << "is a constant\n";
            result += token + " ";
        }
        // Process opening brackets
        else if (SymHelper::IsOpeningBracket(token))
        {
            cout << "is an opening bracket\n";
            stack.push(token);
        }
        // Process closing parathesis
        else if (token == ")")
        {
            cout << "is a closing parenthesis\n";
            // Pops everything from stack until we reach opening parenthesis
            while (!stack.empty() && stack.top() != "(")
            {
                result += stack.top() + " ";
                stack.pop();
            }
            if (!stack.empty() && stack.top() == "(")
            {
                // Get rid of opening paranthesis
                stack.pop();
            }
        }
        else if (token == "]")
        {
            cout << "is a closing square bracket\n";
            // Pops everything from stack until we reach opening square bracket
            while (!stack.empty() && stack.top() != "[")
            {
                result += stack.top() + " ";
                stack.pop();
            }
            if (!stack.empty() && stack.top() == "[")
            {
                // Get rid of opening paranthesis
                stack.pop();
            }
        }
        else if (token == "}")
        {
            cout << "is a closing curly bracket\n";
            // Pops everything from stack until we reach opening parenthesis
            while (!stack.empty() && stack.top() != "{")
            {
                result += stack.top() + " ";
                stack.pop();
            }
            if (!stack.empty() && stack.top() == "{")
            {
                // Get rid of opening paranthesis
                stack.pop();
            }
        }
        else if (SymHelper::IsSeparator(token))
        {
            cout << "is a separator\n";
            // Pops everything from the stack until we face with opening bracket
            while (!stack.empty() && !SymHelper::IsOpeningBracket(stack.top()))
            {
                result += stack.top() + " ";
                stack.pop();
            }
            if (stack.empty())
            {
                throw "Opening bracket inside the provided mathematical expression is missed";
            }
        }
        else if (SymHelper::IsFunction(token) || SymHelper::IsOperation(token))
        {
            cout << "is an operation/function\n";
            // every function is pushed to the stack
            // Check the precedence of the function at the stack's top
            if (!stack.empty() && (SymHelper::IsFunction(stack.top()) || SymHelper::IsOperation(stack.top())) && (precedence[stack.top()] < precedence[token] ||
                (precedence[stack.top()] == precedence[token] && token != "^")))
            {
                cout << stack.top() << " was poped from the stack's top\n";
                result += stack.top() + " ";
                stack.pop();
                
            }
            stack.push(token);
        }
        cout << "\tExp: " << result << "\n";
        previous = token;
    }
    // If stack isn't empty, we pop everything from it to result
    while (!stack.empty())
    {
        result += stack.top() + " ";
        stack.pop();
    }
    // Trims the result string
    result = trim(result);
    cout << "\tResult: " << result << '\n';
    return result;
}
