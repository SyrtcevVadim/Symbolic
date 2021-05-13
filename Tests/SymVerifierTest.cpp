#define CATCH_CONFIG_ENABLE_BENCHMARKING
//#define SYM_USE_BENCHMARKING
#include"Catch2TestFramework/catch.hpp"
#include"../src/SymVerifier.h"
#include<string>

using std::string;

TEST_CASE("Test of areAllTokensCorrect()(positive)")
{
	string expression = GENERATE("x+1", "a+b+c+123.12",
								"sin(cos(cot(111)))");
	SymVerifier verifier(expression);
	INFO(expression);
	CHECK(verifier.areAllTokensCorrect());
}

TEST_CASE("Test of areAllTokensCorrect()(negative)")
{
	string expression = GENERATE("abra+cadabra", "sig(x)-cos(a*b)", "|x+1&", "tang(556)");
	SymVerifier verifier(expression);
	INFO(expression);
	CHECK_FALSE(verifier.areAllTokensCorrect());
}

TEST_CASE("Test of areBracketsCorrespond()(positive)")
{
	string expression = GENERATE("(())", "[]", "{}", "{x+1*[tg(x)]}", "(x+1+(b+c)-5*tg(x))");
	SymVerifier verifier(expression);
	INFO(expression);
	CHECK(verifier.areBracketsCorrespond());
}

TEST_CASE("Test of areBracketsCorrespond()(negative)")
{
	string expression = GENERATE(
		")", "]", "}",
		"(]", "(}", "[)", "[}", "{)", "{]"
		"())", "[]]{", "x+1)",
		"sin(x", "x^(2]", "x+(x+1()");
	SymVerifier verifier(expression);
	INFO(expression);
	CHECK_FALSE(verifier.areBracketsCorrespond());
}


TEST_CASE("Test of hasEmptyBrackets()(positive)")
{
	string expression = GENERATE(
		"()", "[]", "{}");

	SymVerifier verifier(expression);
	INFO(expression);
	CHECK(verifier.hasEmptyBrackets());
}

TEST_CASE("Test of hasEmptyBrackets()(negative)")
{
	string expression = GENERATE(
		"x*(x+1)", "[tg(x-1)]", "{6}"
	);
	SymVerifier verifier(expression);

	INFO(expression);
	CHECK_FALSE(verifier.hasEmptyBrackets());
}

TEST_CASE("Test of hasMissedOperations()(positive)")
{
	string expression = GENERATE("x 1", "(1+2) 7", "b c", "1 1", "pi e");
	SymVerifier verifier(expression);

	INFO(expression);
	CHECK(verifier.hasMissedOperations());
}

TEST_CASE("Test of hasMissedOperations()(negative)")
{
	string expression = GENERATE("x+1", "e+e/3");
	SymVerifier verifier(expression);
	INFO(expression);
	CHECK_FALSE(verifier.hasMissedOperations());
}

TEST_CASE("Test of hasMissedOperands()(positive)")
{
	string expression = GENERATE("abs()", "log(5,)", "pow(,7)", "1+", "2-", "/4", "*8","a*","pi+");
	SymVerifier verifier(expression);
	INFO(expression);
	CHECK(verifier.hasMissedOperands());
}

TEST_CASE("Test of hasMissedOperands()(negative)")
{
	string expression{ "1+2+3-tg(x*ln(3*e))-(x^3+x^2+5.3*x)/ctg(7)" };
	SymVerifier verifier(expression);
	INFO(expression);
	CHECK_FALSE(verifier.hasMissedOperands());
}