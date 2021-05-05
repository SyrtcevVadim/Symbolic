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
    /// Initial user-provided mathematical expression in infix form
    /// </summary>
    string initial;

    /// <summary>
    /// Mathematical expression written in infix form. Every constant inside it is replaced by it's value
    /// </summary>
    list<string> infix;
    /// <summary>
    /// Mathematical expression written in postfix form. Every parameter inside it is replaced by it's value
    /// </summary>
    list<string> postfix;

    /// <summary>
    /// Stores parameters' values. There're 4 parameters: a, b, c, d
    /// </summary>
    map<string, double> parameters;

    /// <summary>
    /// Substitutes constants' values in mathematical expression in infix form
    /// </summary>
    /// <param name="infix">List of tokens of mathematical expression in infix form</param>
    /// <returns>List of tokens of mathematical expression in infix form with substituted constants' values</returns>
    list<string> substituteConstantValues(const list<string> &infix);

    /// <summary>
    /// Substitutes parameters' values in mathematical expression in postfix form
    /// </summary>
    /// <param name="postfix">List of tokens of mathematical expression in postfix form</param>
    /// <returns>List of tokens of mathematical expression in postfix form with substitutes parameter's values</returns>
    list<string> subsituteParameterValues(const list<string> &postfix);

public:
    SymExpression();
    SymExpression(const char* mathematicalExpression);  
    SymExpression(string mathematicalExpression);

    /// <summary>
    /// Sets the value of the mathematical expression
    /// </summary>
    void setExpression(string mathematicalExpression);

    /// <summary>
    /// Sets parameter's value
    /// </summary>
    /// <param name="name">Name of the parameter(a, b, c or d)</param>
    /// <param name="value">Value of the parameter</param>
    void setParameterValue(const string &name, double value);

    /// <summary>
    /// Returns the value of parameter
    /// </summary>
    double getParameterValue(const string& name);

    /// <summary>
    /// Sets parameter's values
    /// </summary>
    /// <param name="aValue">Value of the parameter a</param>
    /// <param name="bValue">Value of the parameter b</param>
    /// <param name="cValue">Value of the parameter c</param>
    /// <param name="dValue">Value of the parameter d</param>
    void setParameterValues(double aValue=1.0, double bValue=1.0, double cValue=1.0, double dValue=1.0);

    /// <summary>
    /// Substitutes the variable's value in mathematical expression in postfix form
    /// </summary>
    /// <param name="value">Value of the variable</param>
    /// <returns>List of tokens of mathematical expression in postfix form with substituted variable's value</returns>
    list<string> substituteVariableValue(double value);

    /// <summary>
    /// Returns the user-provided mathematical expression
    /// </summary>
    string getExpression()const;

    /// <summary>
    /// Returns list of tokens of mathematical expression in infix form
    /// </summary>
    list<string> getInfix()const;

    /// <summary>
    /// Returns list of tokens of mathematical expression in postfix form
    /// </summary>
    list<string> getPostfix()const;
};