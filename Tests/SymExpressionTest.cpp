#define CATCH_CONFIG_ENABLE_BENCHMARKING
//#define SYM_USE_BENCHMARKING
#include"Catch2TestFramework/catch.hpp"
#include"../src/SymExpression.h"
#include"../src/SymConstantManager.h"
#include"../src/SymCalculator.h"
#include<string>
#include<sstream>

using std::stringstream;
using std::string;

TEST_CASE("Test of constructor function")
{
	INFO("Constructor with string argument");
	SymExpression test{"x+1"};
	CHECK(test.get() == "x+1");
	test = "5+e";
	CHECK(test.getReal() == "5+2.718281828");
	CHECK(test.get() == "5+e");
}

TEST_CASE("Test of set() function")
{
	SymExpression test;
	test.set("sin  (x \t)\n");
	CHECK(test.get() == "sin(x)");
	string newExp{ " 1+\n \t2 +3^ 4   " };
	test.set(newExp);
	CHECK(test.get() == "1+2+3^4");
}

TEST_CASE("Test of setParameterValue() function")
{
	SymExpression test("a+1");
	test.setParameterValue("a", 5.5);
	CHECK(test.getParameterValue("a") == 5.5);
	CHECK_THROWS(test.setParameterValue("z", 11));
	double zero{ 0.0 };
	CHECK_THROWS(test.setParameterValue("a", 1.0/zero));
	CHECK_THROWS(test.setParameterValue("a", 0/zero));
}

TEST_CASE("Test of setParameterValues() function")
{
	SymExpression test("a+b+c+d");
	test.setParameterValues(2.0, 3.0, 4.0, 5.0);
	CHECK(test.getParameterValue("a") == 2.0);
	CHECK(test.getParameterValue("b") == 3.0);
	CHECK(test.getParameterValue("c") == 4.0);
	CHECK(test.getParameterValue("d") == 5.0);
}

TEST_CASE("Using of constants inside SymExpression")
{
	SymConstantManager::AddConstant("r", "1+2");
	SymConstantManager::AddConstant("z", "r+3");
	
	SymExpression expression("z  ");
	CHECK(expression.get() == "z");
	CHECK(expression.getReal() == "1+2+3");
	SymCalculator calculator(expression);
	CHECK(calculator.compute() == Approx(6.0));
	SymConstantManager::AddConstant("g", "r+z");
	expression = "g\n\t";
	CHECK(expression == "g");
	CHECK(expression.getReal() == "1+2+1+2+3");
	CHECK(calculator.compute() == Approx(9.0));

	SymConstantManager::RemoveConstant("r");
	SymConstantManager::RemoveConstant("z");
}

TEST_CASE("Test of '==' operation")
{
	SymExpression a{ "1+2+3-x" };
	SymExpression b{ "1+2+3-x" };

	CHECK(a == b);
	CHECK(a == "1+2+3-x");
	CHECK_FALSE(a == "x-1");
}

TEST_CASE("Test of '+' operation")
{
	SymExpression a{ "x+1-e" };
	SymExpression b{ "2*pi" };

	SymExpression c = a + b;

	CHECK(c == "x+1-e+2*pi");

	a = a + "x";
	CHECK(a == "x+1-e+x");
	a = a + 7;
	CHECK(a == "x+1-e+x+7");
	a = 1;
	a = 7 + a;
	CHECK(a == "7+1");
}

TEST_CASE("Test of '-' operation")
{
	SymConstantManager::AddConstant("z", "1");
	SymExpression a{ "7*x-4*z" };
	SymExpression b{ "8*x-z" };
	SymExpression c = a - b;
	CHECK(c == "(7*x-4*z)-(8*x-z)");
	SymConstantManager::RemoveConstant("z");

	a = a - 11;
	CHECK(a == "(7*x-4*z)-(11)");
	a = "x";
	a = a + "x+1";
	CHECK(a == "x+x+1");
	
}

TEST_CASE("Test of '*' operation")
{
	SymExpression a{ "x+1-3" };
	SymExpression b{"a-b"};

	SymExpression c{ a * b };
	CHECK(c == "(x+1-3)*(a-b)");
}

TEST_CASE("Test of '/' operation")
{
	SymExpression a{ "x " };
	SymExpression b{ "7\n" };

	SymExpression c = a / b;
	CHECK(c == "(x)/(7)");
}

TEST_CASE("Test of '^' operation")
{
	SymExpression a{ "789" };
	SymExpression b{ "x+1" };

	SymExpression c{ a ^ b };
	CHECK(c == "(789)^(x+1)");
}

TEST_CASE("Test of '+=' operation")
{
	SymExpression a{ "x+1" };
	SymExpression b{ "2" };
	a += b;
	CHECK(a == "x+1+2");
	a += "7-x";
	CHECK(a == "x+1+2+7-x");
}

TEST_CASE("Test of '-=' operation")
{
	SymExpression a{ "a+10-e" };
	SymExpression b{ "b-754" };
	a -= b;
	CHECK(a == "(a+10-e)-(b-754)");
	a -= "-123";
	CHECK(a == "((a+10-e)-(b-754))-(-123)");
}

TEST_CASE("Test of '*=' operation")
{
	SymExpression a{ "x-1" };
	SymExpression b{ "a+c" };

	a *= b;
	CHECK(a == "(x-1)*(a+c)");

}

TEST_CASE("Test of '/=' operation")
{
	SymExpression a{ "log(5,25)" };
	SymExpression b = "7*x";
	a /= b;
	CHECK(a == "(log(5,25))/(7*x)");
}

TEST_CASE("Test of '^=' operation")
{
	SymExpression a{ "x" };
	SymExpression b{ "x" };
	a ^= b;
	CHECK(a == "(x)^(x)");
	a = "7";
	a ^= "3";
	CHECK(a == "(7)^(3)");
}


TEST_CASE("Test of insertion/extraction operations(<</>>)")
{
	SymExpression a{ "x-1" };
	stringstream ss;
	ss << a;			// Inserts the expression inside the stream
	SymExpression b;
	ss >> b;
	CHECK(b.get() == a.get());
}
// Benchmarking
#ifdef SYM_USE_BENCHMARKING
TEST_CASE("SymExpression class")
{
	SymExpression exp;
	BENCHMARK("Constructor")
	{
		return SymExpression("x+1+2-tg(ctg(a+b+c+d))/4");
	};

	BENCHMARK("set()")
	{
		return exp.set("1+2+3+x+tg(x)/sin(x)*log(5,25)");
	};

	BENCHMARK("setParameterValue()")
	{
		exp.setParameterValue("a", 15);
		exp.setParameterValue("b", 8);
		exp.setParameterValue("c", 123);
		exp.setParameterValue("d", 55'555);
		return;
	};

	BENCHMARK("setParameterValues()")
	{
		return exp.setParameterValues(15, 8, 123, 55'555);
	};

	BENCHMARK("getInfix()")
	{
		return exp.getInfix();
	};

	BENCHMARK("getPostfix()")
	{
		return exp.getPostfix();
	};
}
#endif