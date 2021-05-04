#include"Catch2TestFramework/catch.hpp"
#include"../SymParser.h"
#include<string>
#include<list>


using std::string;
using std::list;


TEST_CASE("Test of CreateTokenList() function")
{
	CHECK(SymParser::CreateTokenList("x - \t1") == list<string>{"x", "-", "1"});
	CHECK(SymParser::CreateTokenList("x+  1+a+pi+  (1+\tsin(x))") == list<string>{"x","+","1","+","a","+","pi","+","(","1","+","sin","(","x",")",")"});
	CHECK(SymParser::CreateTokenList("\n \t") == list<string>{});
}

