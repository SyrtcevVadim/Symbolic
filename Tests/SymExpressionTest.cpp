#include"Catch2TestFramework/catch.hpp"
#include"../SymExpression.h"
#include<string>

using std::string;

TEST_CASE("Test of constructor function")
{
	INFO("Constructor with string argument");
	SymExpression test{"x+1"};
	CHECK(test.get() == "x+1");
	test = "5+e";
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

TEST_CASE("Test of substituteVariableValue() function")
{
	SymExpression test("x+1");
	CHECK(test.substituteVariableValue(11.1) == list<string>{"11.1","1","+"});
	test = "x+x+x+(x+1)";
	CHECK(test.substituteVariableValue(3.12) == list<string>{"3.12", "3.12", "+", "3.12", "+", "3.12", "1", "+", "+"});
	double zero{ 0.0 };
	CHECK_THROWS(test.substituteVariableValue(1.0 / zero));
	CHECK_THROWS(test.substituteVariableValue(0 / zero));
}

TEST_CASE("Test of getInfix() function")
{
	SymExpression test("x+1");
	CHECK(test.getInfix() == list<string>{"x", "+", "1"});
	test = "e+1";
	CHECK(test.getInfix() == list<string>{"2.718281828", "+", "1"});
}

TEST_CASE("Test of getPostfix function")
{
	SymExpression test{ "x+a" };
	CHECK(test.getPostfix() == list<string>{"x", "1", "+"});
}