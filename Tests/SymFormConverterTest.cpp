#include"Catch2TestFramework/catch.hpp"
#include"../SymParser.h"
#include"../SymFormConverter.h"
#include<string>
#include<vector>

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
	vector<string> output{ "x 1 +", "x 1 -", "x 1 *", "x 1 /",
						   "x un-", "x un-", "1 1 un- +","x un+",
						   "x un+", "1 un- 1 un+ +", "1 un+", "1",
						   "1 2 * 3 +", "1 2 3 4 ^ ^ ^", "x 1 un- ^", "e x 1 + ^",
						   "x sin", "x cos", "x tg", "x ctg",
						   "x 1 pi + sin * sin"};

	for (int i{ 0 }; i < input.size(); i++)
	{
		INFO(input[i]+" and "+output[i]);
		CHECK(SymFormConverter::InfixToPostfix(SymParser::CreateTokenList(input[i])) == output[i]);
	}
}