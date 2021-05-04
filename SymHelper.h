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
    /// 
    /// </summary>
    //static map<string, string> predefinedConstants;

    /// <summary>
    /// 
    /// </summary>
    //static map<string, string> userDefinedConstants;

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



    /// Checks, whether string contains constants or not

    // TODO class SymConstantManager
    //static bool HasConstants(const QString& expression);

    /*
    * //static bool IsConstant(const string &str);
    /// Create new user-defined constant with provided value
    static void AddConstant(const QString& constant, const QString& value);
    /// Removes constant from user-defined constants
    static void RemoveConstant(const QString& constant);
    /// Alters existing user-defined constant's value
    static void AlterConstantValue(const QString& constant, const QString& value);
    */

};

