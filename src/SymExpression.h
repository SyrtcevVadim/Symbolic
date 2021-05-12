#pragma once
#include<string>
#include<list>
#include<map>

using std::string;
using std::list;
using std::map;

class SymExpression
{
private:
    /// <summary>
    /// Initial user-provided mathematical expression
    /// </summary>
    string initial;

    /// <summary>
    /// List of tokens of a mathematical expression written in infix form. Every constant inside it is replaced by it's value
    /// </summary>
    list<string> infix;
    /// <summary>
    /// List of tokens of a mathematical expression written in postfix form. Every constant inside it is replaced by it's value
    /// </summary>
    list<string> postfix;

    /// <summary>
    /// Stores parameters' values. There're only 4 parameters: a, b, c, d
    /// </summary>
    map<string, double> parameters;

    /// <summary>
    /// Substitutes constants' values in mathematical expression in infix form
    /// </summary>
    /// <param name="infix">List of tokens of mathematical expression in infix form</param>
    /// <returns>List of tokens of mathematical expression in infix form with substituted constants' values</returns>
    list<string> substituteConstantValues(const list<string> &infix);

public:
    SymExpression();
    SymExpression(const char* mathematicalExpression);  
    SymExpression(string mathematicalExpression);

    /// <summary>
    /// Sets the value of the mathematical expression
    /// </summary>
    void set(string mathematicalExpression);

    /// <summary>
    /// Sets parameter's value
    /// </summary>
    /// <param name="name">Name of the parameter(a, b, c, d)</param>
    /// <param name="value">Value of the parameter</param>
    void setParameterValue(const string &name, double value);

    /// <summary>
    /// Returns the value of the parameter by it's name
    /// </summary>
    double getParameterValue(const string& name);

    /// <summary>
    /// Sets the parameter's values
    /// </summary>
    /// <param name="aValue">Value of the parameter a</param>
    /// <param name="bValue">Value of the parameter b</param>
    /// <param name="cValue">Value of the parameter c</param>
    /// <param name="dValue">Value of the parameter d</param>
    void setParameterValues(double aValue=1.0, double bValue=1.0, double cValue=1.0, double dValue=1.0);

    /// <summary>
    /// Returns the user-provided mathematical expression
    /// </summary>
    string get()const;

    /// <summary>
    /// Returns the list of tokens of mathematical expression in infix form
    /// </summary>
    list<string>& getInfix();

    /// <summary>
    /// Returns the list of tokens of mathematical expression in postfix form
    /// </summary>
    list<string>& getPostfix();
};