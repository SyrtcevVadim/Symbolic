#define CATCH_CONFIG_ENABLE_BENCHMARKING
//#define SYM_USE_BENCHMARKING
#include"Catch2TestFramework/catch.hpp"
#include"../src/SymParser.h"
#include<string>
#include<chrono>
#include<thread>
#include<list>


using std::string;
using std::list;


TEST_CASE("Test of CreateTokenList() function")
{
	CHECK(SymParser::CreateTokenList("x - \t1") == list<string>{"x", "-", "1"});
	CHECK(SymParser::CreateTokenList("x+  1+a+pi+  (1+\tsin(x))") == list<string>{"x","+","1","+","a","+","pi","+","(","1","+","sin","(","x",")",")"});
	CHECK(SymParser::CreateTokenList("\n \t") == list<string>{});
}

// Benchmarking
#ifdef SYM_USE_BENCHMARKING
TEST_CASE("SymParser class")
{
	BENCHMARK("CreateTokenList().Simple")
	{
		return SymParser::CreateTokenList("x+x+x^2");
	};

	BENCHMARK("CreateTokenList().Difficult")
	{
		return SymParser::CreateTokenList("x+sin(cos(tg(ctg(x+log(5,25)))))-14");
	};
}
#endif