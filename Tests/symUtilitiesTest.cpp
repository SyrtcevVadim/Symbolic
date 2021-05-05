#include"Catch2TestFramework/catch.hpp"
#include"../symUtilities.h"
#include<string>

using std::string;

TEST_CASE("Test of trim() function")
{
	string test = GENERATE("   ab     ", "     ab", "ab     ");
	CHECK(trim(test) == "ab");
}

TEST_CASE("Test of numberToString() function")
{
	CHECK(numberToString(3.1415920000) == "3.141592");
	CHECK(numberToString(3.000001) == "3.000001");
	CHECK(numberToString(11.000) == "11");

	double zero{ 0.0 };
	CHECK_THROWS(numberToString(0.0 / zero));
	CHECK_THROWS(numberToString(1.0 / zero));
}