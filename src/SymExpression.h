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
#include<string>
#include<iostream>
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
    /// User-provided mathematical expression with substituted constant's values
    /// </summary>
    string real;

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
    /// <param name="Initial">Mathematical expression in infix form</param>
    /// <returns>Mathematical expression in infix form with substituted constants' values</returns>
    string substituteConstantValues(string initial);

public:
    SymExpression();
    SymExpression(const char* mathematicalExpression);  
    SymExpression(string mathematicalExpression);
    SymExpression(double number);

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
    /// Returns the user-provided mathematical expression with substituted constants' values
    /// </summary>
    /// <returns></returns>
    string getReal()const;

    /// <summary>
    /// Returns the list of tokens of mathematical expression in infix form
    /// </summary>
    list<string>& getInfix();

    /// <summary>
    /// Returns the list of tokens of mathematical expression in postfix form
    /// </summary>
    list<string>& getPostfix();

    // Concatenates SymExpressions objects with substituting of the apropriate operation between them

    friend SymExpression operator+(const SymExpression& lVal, const SymExpression& rVal);
    friend SymExpression operator-(const SymExpression& lVal, const SymExpression& rVal);
    friend SymExpression operator*(const SymExpression& lVal, const SymExpression& rVal);
    friend SymExpression operator/(const SymExpression& lVal, const SymExpression& rVal);
    friend SymExpression operator^(const SymExpression& lVal, const SymExpression& rVal);

    // Appends the rVal expression to the lVal with substituting of the appropriate operation between these parts 

    SymExpression& operator+=(const SymExpression& rVal);
    SymExpression& operator-=(const SymExpression& rVal);
    SymExpression& operator*=(const SymExpression& rVal);
    SymExpression& operator/=(const SymExpression& rVal);
    SymExpression& operator^=(const SymExpression& rVal);

    // Compares two SymExpression objects

    friend bool operator==(const SymExpression &lVal, const SymExpression& rVal);

    friend std::ostream& operator<<(std::ostream& out, const SymExpression& expression);
    friend std::istream& operator>>(std::istream& in, SymExpression& expression);
};