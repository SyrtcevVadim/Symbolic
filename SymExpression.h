#pragma once
#include<string>
#include<map>
using namespace std;

class SymExpression
{
private:
    /// <summary>
    /// Initial user-provided mathematical expression
    /// </summary>
    string initialExpression;
    /// <summary>
    /// Mathematical expression written in infix form. Every constant inside it is replaced by it's value
    /// </summary>
    string infixExpression;
    /// <summary>
    /// Mathematical expression written in postfix form. Every parameter inside it is replaced by it's value
    /// </summary>
    string postfixExpression;
    /// <summary>
    /// Stores parameters' values. There're 4 parameters: a, b, c, d
    /// </summary>
    map<string, double> parameters;

    /// <summary>
    /// Minimum possible variable's value
    /// </summary>
    double minimumVariableValue;
    /// <summary>
    /// Maximum possible variable's value
    /// </summary>
    double maximumVariableValue;

    /// <summary>
    /// Substitutes constants' values in mathematical expression in infix form
    /// </summary>
    /// <param name="infixExpression">Mathematical expression in infix form</param>
    /// <returns>Mathematical expression in infix form with substituted constants' values</returns>
    string substituteConstantValues(string infixExpression);

    /// <summary>
    /// Substitutes parameters' values in mathematical expression in postfix form
    /// </summary>
    /// <param name="postfixExpression">Mathematical expression in postfix form</param>
    /// <returns>Mathematical expression in postfix form with substitutes parameter's values</returns>
    string subsituteParameterValues(string postfixExpression);

public:
    SymExpression();
    SymExpression(string initialExpression);

    /// <summary>
    /// Sets the initial value of the mathematical expression
    /// </summary>
    /// <param name="initialExpression">Initial mathematical expression</param>
    void setExpression(string initialExpression);

    /// <summary>
    /// Sets parameter's value
    /// </summary>
    /// <param name="name">Name of the parameter(a, b, c or d)</param>
    /// <param name="value">Value of the parameter</param>
    void setParameterValue(string name, double value);

    /// <summary>
    /// Sets parameter's values
    /// </summary>
    /// <param name="aValue">Value of the parameter a</param>
    /// <param name="bValue">Value of the parameter b</param>
    /// <param name="cValue">Value of the parameter c</param>
    /// <param name="dValue">Value of the parameter d</param>
    void setParameterValues(double aValue, double bValue, double cValue, double dValue);

    /// <summary>
    /// Returns provided parameter's value
    /// </summary>
    /// <param name="parameterName">Name of the parameter</param>
    /// <returns></returns>
    double getParameterValue(string parameterName);

    

    /// <summary>
    /// Substitutes the variable's value in mathematical expression in postfix form
    /// </summary>
    /// <param name="variableValue">Value of the variable</param>
    /// <returns>Mathematical expression in postfix form with substituted variable's value</returns>
    string substituteVariableValue(double variableValue);

    /// <summary>
    /// Returns the initial mathematical expression
    /// </summary>
    string getInitialExpression()const;

    /// <summary>
    /// Returns mathematical expression in infix form
    /// </summary>
    /// <returns></returns>
    string getInfixExpression()const;

    /// <summary>
    /// Returns mathematical expression in postfix form
    /// </summary>
    /// <returns></returns>
    string getPostfixExpression()const;

    /// <summary>
    /// Sets minimum variable's value
    /// </summary>
    /// <param name="value"></param>
    void setMinimumVariableValue(double value);

    /// <summary>
    /// Sets maximum variable's value
    /// </summary>
    /// <param name="value"></param>
    void setMaximumVariableValue(double value);

    /// <summary>
    /// Returns the minimum variable's value
    /// </summary>
    /// <returns></returns>
    double getMinimumVariableValue()const;

    /// <summary>
    /// Returns the maximum variable's value
    /// </summary>
    /// <returns></returns>
    double getMaximumVariableValue()const;


};