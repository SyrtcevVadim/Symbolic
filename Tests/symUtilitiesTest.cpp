#define CATCH_CONFIG_ENABLE_BENCHMARKING
//#define SYM_USE_BENCHMARKING
#include"Catch2TestFramework/catch.hpp"
#include"../src/symUtilities.h"
#include<string>

using std::string;

TEST_CASE("Test of trim() function")
{
	string test = GENERATE("   ab     ", "     ab", "ab     ");
	CHECK(trim(test) == "ab");
}

TEST_CASE("Test of numberToString() function")
{
	CHECK(numberToString(1) == "1");
	CHECK(numberToString(-1) == "-1");
	CHECK(numberToString(+1) == "1");
	CHECK(numberToString(3.1415920000) == "3.14159");
	CHECK(numberToString(3.000001) == "3");
	CHECK(numberToString(11.000) == "11");
}

TEST_CASE("Test of stringToNumber() function")
{
	CHECK(stringToNumber("1") == 1.0);
	CHECK(stringToNumber("+3") == 3.0);
	CHECK(stringToNumber("-123") == -123.0);
	CHECK(stringToNumber("1.2345") == 1.2345);
	CHECK(stringToNumber("-54.233") == -54.233);
	CHECK(stringToNumber("+66.666") == 66.666);
	CHECK(stringToNumber("123.0") == 123.0);
}

// Benchmarking
#ifdef SYM_USE_BENCHMARKING
TEST_CASE("symUtilities")
{
	BENCHMARK("trim()")
	{
		return trim("   ab     ");
	};

	BENCHMARK("numberToString()")
	{
		return numberToString(123456789.9876543);
	};

	BENCHMARK("stringToNumber()")
	{
		return stringToNumber("342423525.99324432");
	};
}
#endif