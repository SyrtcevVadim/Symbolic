#include"Catch2TestFramework/catch.hpp"
#include"../SymCalculator.h"
#include"../SymExpression.h"
#include<string>
#include<cmath>
#include<vector>
using std::vector;
using std::string;


TEST_CASE("Test of compute() function(simple functions/operations)")
{
	// Stores variable's value
	double x{0.2};
	vector<string> expressions({
		"1","x+1","x-1","x*2","x/4", "x^3",
		"-1","+1","-x","+x",
		"abs(-4)", "pow(x,3)","sqrt(121.0)", "sqr(5)",
		"sin(5)","cos(x)","tg(x)","ctg(x)","cot(x+1)",
		"arcsin(x)", "arccos(x)", "arctg(x)", "arctan(8.7)", "arcctg(x)", "arccot(8)","arccotan(73)",
		"ln(e)", "ln(1)", "ln(x)",
		"lg(10.0)", "lg(1.000)", "lg(x)",
		"log(5, 25)", "log(7, 1)", "log(8, x)"});

	vector<double> results({
		1,(x + 1), (x - 1),(x * 2),(x / 4), (x * x * x),
		-1, 1, -x, +x,
		4, x * x * x, 11.0, 25.0,
		sin(5.0), cos(x), tan(x), 1.0 / tan(x), 1.0 / tan(x + 1),
		asin(x), acos(x), atan(x), atan(8.7), (1.570796 - atan(x)), (1.570796 - atan(8.0)), (1.570796 - atan(73.0)),
		log(2.718281828), log(1.0), log(x),
		log10(10.0), log10(1.0), log10(x),
		log(25.0) / log(5), log(1) / log(7), log(x) / log(8) });

	SymExpression exp;
	SymCalculator calc(&exp);
	for (size_t i{ 0 }; i < expressions.size(); i++)
	{
		exp.set(expressions[i]);
		INFO(expressions[i]);
		CHECK(calc.compute(x) == Approx(results[i]).margin(.01));
	}
}