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
#include"SymExpression.h"
#include<map>
#include<string>
#include<functional>

using std::string;
using std::map;
using std::function;

class SymCalculator
{
private:
	/// <summary>
	/// Stores the address of methods for processing of standart functions
	/// </summary>
	static map<string, function<double(double, double)>> functionHandlers;

	/// <summary>
	/// Mathematical expression for providing calculations
	/// </summary>
	SymExpression& mathExpression;

	static double nothing(double value, double);

	static double negate(double value, double);

	static double absolute(double value, double);

	static double sum(double lValue, double rValue);

	static double difference(double lValue, double rValue);

	static double product(double lValue, double rValue);

	static double quotient(double dividend, double divisor);

	static double power(double base, double power);

	static double square(double base, double);

	static double squareRoot(double value, double);

	static double sinus(double angle, double);

	static double cosine(double angle, double);

	static double tangent(double angle, double);

	static double cotangent(double angle, double);

	static double arcsinus(double value, double);

	static double arccosine(double value, double);

	static double arctangent(double value, double);

	static double arccotangent(double value, double);

	/// <summary>
	/// Calculates value of logarithm with the 'e' base
	/// </summary>
	static double naturalLogarithm(double value, double);

	/// <summary>
	/// Calculates a value of logarithm with the '10' base
	/// </summary>
	/// 
	static double decimalLogarithm(double value, double);
	
	/// <summary>
	/// Calculates a value of logarithm with an arbitrary base
	/// </summary>
	/// <param name="base"></param>
	/// <param name="value"></param>
	/// <returns></returns>
	static double logarithm(double base, double value);


public:
	SymCalculator() = default;
	SymCalculator(SymExpression &mathematicalExpression);
	/// <summary>
	/// Caclulates the value of mathematical expression with
	/// substituted variable's value
	/// </summary>
	double compute(double variableValue=0.0);
};

