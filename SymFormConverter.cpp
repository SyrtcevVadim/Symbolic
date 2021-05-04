#include "SymFormConverter.h"
#include"SymFormConverter.h"
#include"SymParser.h"
#include"SymHelper.h"
#include"SymConstantManager.h"
#include<string>
#include<stack>

using std::string;
using std::stack;

map<string, int> SymFormConverter::precedence{ {  {"abs", 1},
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
                                                 {"^", 1},
                                                 {"*", 3},
                                                 {"/", 3},
                                                 {"+", 4},
                                                 {"-", 4}
                                                 }};


/*string SymFormConverter::InfixToPostfix(const string& infixExpression)
{
    // Creates a stack for storing intermediate values
    stack<string> stack;
    string resultExpression{ " " };
    string previousToken{ "" };

    // Iterates through the expression
    /*for (string token : )
    {
        // Processing unary plus and unary minus operation
        if ((token == "+" || token == "-") && (previousToken.empty() || SymHelper::IsOpeningBracket(previousToken) || SymHelper::IsSeparator(previousToken) ||
            SymHelper::IsOperation(previousToken)))
        {
            // Check the precedence of the function at the stack's top
            if (!stack.empty() && (SymHelper::IsFunction(stack.top()) || SymHelper::IsOperation(stack.top())) && (precedence[stack.top()] < precedence["un" + token] ||
                (precedence[stack.top()] == precedence[token] && token != "^")))
            {
                resultExpression += stack.top() + " ";
                stack.pop();
            }
            stack.push("un" + token); // un+ or un-
        }
        // If token is a decimal number, we push it to the result string
        else if (SymHelper::IsNumber(token))
        {
            resultExpression += token + " ";
        }
        else if (SymHelper::IsVariable(token))
        {
            resultExpression += token + " ";
        }
        else if (SymHelper::IsParameter(token))
        {
            resultExpression += token + " ";
        }
        else if (SymConstantManager::IsConstant(token))
        {
            resultExpression += token + " ";
        }
        // Process opening brackets
        else if (SymHelper::IsOpeningBracket(token))
        {
            stack.push(token);
        }
        // Process closing parathesis
        else if (token == ")")
        {
            // Pops everything from stack until we reach opening parenthesis
            while (!stack.empty() && stack.top() != "(")
            {
                resultExpression += stack.top() + " ";
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
            // Pops everything from stack until we reach opening square bracket
            while (!stack.empty() && stack.top() != "[")
            {
                resultExpression += stack.top() + " ";
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
            // Pops everything from stack until we reach opening parenthesis
            while (!stack.empty() && stack.top() != "{")
            {
                resultExpression += stack.top() + " ";
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
            // Pops everything from the stack until we face with opening bracket
            while (!stack.empty() && !SymHelper::IsOpeningBracket(stack.top()))
            {
                resultExpression += stack.top() + " ";
                stack.pop();
            }
            if (stack.empty())
            {
                throw "Opening bracket inside the provided mathematical expression is missed";
            }
        }
        else if (SymHelper::IsFunction(token) || SymHelper::IsOperation(token))
        {
            // every function is pushed to the stack
            // Check the precedence of the function at the stack's top
            if (!stack.empty() && (SymHelper::IsFunction(stack.top()) || SymHelper::IsOperation(stack.top())) && (precedence[stack.top()] < precedence[token] ||
                (precedence[stack.top()] == precedence[token] && token != "^")))
            {
                resultExpression += stack.top() + " ";
                stack.pop();
            }
            stack.push(token);
        }
        previousToken = token;
    }
    // If stack isn't empty, we pop everything from it to result
    while (!stack.empty())
    {
        resultExpression += stack.top() + " ";
        stack.pop();
    }
    return resultExpression;

}*/
