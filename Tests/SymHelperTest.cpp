#include"Catch2TestFramework/catch.hpp"
#include"../SymHelper.h"

TEST_CASE("Test of IsNumber() function(positive case)")
{
	string testNumber = GENERATE("1", "+1", "-1", "1.1", "-1.1", "+1.1");
	CHECK(SymHelper::IsNumber(testNumber));
}

TEST_CASE("Test of IsNumber() function(negative case)")
{
	string testNumber = GENERATE("+", "-", ".", ".123", "15.", "1.1.","++1","--1");
	INFO(testNumber);
	CHECK_FALSE(SymHelper::IsNumber(testNumber));
}

TEST_CASE("Test of IsSeparator() function")
{
	string testSeparator = GENERATE(",", ";");
	INFO(testSeparator);
	CHECK(SymHelper::IsSeparator(testSeparator));
}

TEST_CASE("Test of IsVariable() function")
{
	string testVariable = GENERATE("x", "X");
	INFO(testVariable);
	CHECK(SymHelper::IsVariable(testVariable));
}

TEST_CASE("Test of IsParameter() function")
{
	string testParameter = GENERATE("a", "b", "c", "d");
	INFO(testParameter);
	CHECK(SymHelper::IsParameter(testParameter));
}

TEST_CASE("Test of IsCorrect() function(positive case)")
{
	string testToken = GENERATE("(", ")", "[", "]", "{", "}",
								",", ";",
								"+", "-", "*", "/", "^",
								"abs", "pow", "sqr", "sqrt",
								"sin", "cos", "tg", "tan", "ctg", "cot",
								"arcsin", "arccos", "arctg", "arctan", "arcctg", "arccot", "arccotan",
								"ln", "lg", "log",
								"x", "X",
								"a", "b", "c", "d",
								"pi", "e");
	CHECK(SymHelper::IsCorrect(testToken));
}

TEST_CASE("Test of IsCorrect() function(negative case)")
{
	string testToken = GENERATE("abra","sinx","tang",
								"@","#","$","%","&","\\","~","!");
	CHECK_FALSE(SymHelper::IsCorrect(testToken));
}

TEST_CASE("Test of IsOperation() function")
{
	string testOperation = GENERATE("un+", "un-", "+", "-", "*", "/", "^");
	CHECK(SymHelper::IsOperation(testOperation));
}

TEST_CASE("Test of IsFunction() function")
{
	string testFunction = GENERATE(	"abs", "pow", "sqr", "sqrt",
									"sin", "cos", "tg", "tan", "ctg", "cot",
									"arcsin", "arccos", "arctg", "arctan", "arcctg", "arccot", "arccotan",
									"ln", "lg", "log");
	CHECK(SymHelper::IsFunction(testFunction));
}

TEST_CASE("Test of IsOpeningBracket() function")
{
	string testBracket = GENERATE("(", "[", "{");
	CHECK(SymHelper::IsOpeningBracket(testBracket));
}

TEST_CASE("Test of IsClosingBracket() function")
{
	string testBracket = GENERATE(")", "]", "}");
	CHECK(SymHelper::IsClosingBracket(testBracket));
}