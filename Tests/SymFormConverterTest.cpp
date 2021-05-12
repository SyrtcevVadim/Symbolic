#define CATCH_CONFIG_ENABLE_BENCHMARKING
#define SYM_USE_BENCHMARKING
#include"Catch2TestFramework/catch.hpp"
#include"../src/SymExpression.h"
#include"../src/SymParser.h"
#include"../src/SymFormConverter.h"

#include<string>
#include<list>
#include<vector>

using std::list;
using std::string;
using std::vector;

TEST_CASE("Test of InfixToPostfix() function")
{
	vector<string> input{ "x+1", "x-1", "x*1", "x/1",
						  "-x", "(-x)","1 + -1", "+x",
					      "(+x)", "-1 + +1", "((+1))", "1",
						  "1*2+3","1^2^3^4", "x^-1","e ^(x+ 1)",
					      "sin(x)", "cos(x)", "tg(x)", "ctg(x)",
						  "sin(x*sin(1+pi))"};

	vector<list<string>> output{{"x","1","+"}, {"x", "1", "-"},{"x","1","*"}, {"x","1", "/"},
								{"x","un-"}, {"x","un-"}, {"1","1","un-","+"},{"x", "un+"},
								{"x","un+"}, {"1","un-","1","un+","+" }, {"1","un+"}, {"1"},
								{"1","2","*","3","+"}, {"1","2","3","4","^","^","^"}, {"x","1","un-","^"},{"e","x","1","+","^" },
								{"x", "sin"}, {"x","cos"}, {"x","tg"}, {"x","ctg"},
								{"x","1","pi","+","sin","*","sin"}};

	for (int i{ 0 }; i < input.size(); i++)
	{
		INFO(input[i]);
		CHECK(SymFormConverter::InfixToPostfix(SymParser::CreateTokenList(input[i])) == output[i]);
	}
}

// Benchmarking
#ifdef SYM_USE_BENCHMARKING
TEST_CASE("SymFormConverter class")
{
	SymExpression exp("x+1+a+pi+(1+sin(x))+a*x^3+b*x^2+c*x+d - 14445.82*tg(x^2-54)/ln(log(5,155*x))");
	BENCHMARK("InfixToPostfix()")
	{
		return SymFormConverter::InfixToPostfix(exp.getInfix());
	};
}
#endif