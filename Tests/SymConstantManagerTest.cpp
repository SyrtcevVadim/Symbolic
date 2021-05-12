#define CATCH_CONFIG_ENABLE_BENCHMARKING
//#define SYM_USE_BENCHMARKING
#include"Catch2TestFramework/catch.hpp"
#include"../src/SymConstantManager.h"
#include"../src/SymExpression.h"
#include"../src/SymParser.h"
#include<string>

using std::string;

TEST_CASE("Test of IsConstant() function(positive case)")
{
	string testConstant = GENERATE("e", "pi");
	CHECK(SymConstantManager::IsConstant(testConstant));
}
TEST_CASE("Test of IsConstant() function(negative case)")
{
	string testConstant = GENERATE("ABRA", "ex", "pim");
	CHECK_FALSE(SymConstantManager::IsConstant(testConstant));
}

TEST_CASE("Test of HasConstants() function(positive case)")
{
	string expression = GENERATE("pi", "e", "x+pi-pi*pi", "1-e^x-pi");
	CHECK(SymConstantManager::HasConstants(SymParser::CreateTokenList(expression)));
}

TEST_CASE("Test of HasConstants() function(negative case)")
{
	string expression = GENERATE("", "x", "1+2+3");
	CHECK_FALSE(SymConstantManager::HasConstants(SymParser::CreateTokenList(expression)));
}

TEST_CASE("Test of AddConstant() function")
{
	string constant = "myConstant";
	SymConstantManager::AddConstant(constant, "11.22");
	CHECK(SymConstantManager::IsConstant(constant));
	SymConstantManager::RemoveConstant(constant);
}

TEST_CASE("Test of RemoveConstant() function")
{
	string constant = "myConstant";
	SymConstantManager::AddConstant(constant, "11");
	CHECK(SymConstantManager::IsConstant(constant));
	SymConstantManager::RemoveConstant(constant);
	CHECK_FALSE(SymConstantManager::IsConstant(constant));
}

TEST_CASE("Test of GetConstantValue() function")
{
	CHECK(SymConstantManager::GetConstantValue("e") == "2.718281828");
	CHECK(SymConstantManager::GetConstantValue("pi") == "3.141592");

	SymConstantManager::AddConstant("myConstant", "123+x");
	CHECK(SymConstantManager::GetConstantValue("myConstant") == "123+x");
	SymConstantManager::RemoveConstant("myConstant");
}


TEST_CASE("Test of AlterConstantValue() function")
{
	SymConstantManager::AddConstant("myConstant", "111");
	CHECK(SymConstantManager::GetConstantValue("myConstant") == "111");
	SymConstantManager::AlterConstantValue("myConstant", "222");
	CHECK(SymConstantManager::GetConstantValue("myConstant") == "222");
	SymConstantManager::RemoveConstant("myConstant");

	CHECK_THROWS(SymConstantManager::AlterConstantValue("myConstant", "x+x"));
}

// Benchmarking
#ifdef SYM_USE_BENCHMARKING
TEST_CASE("SymConstantManager class")
{
	SymExpression expWithConstants("x+sin(x)-tg(54)*log(log(5,25), pi)*e^x");
	SymExpression expWithoutConstants("arcsin(	4*x)-52*x^x-473*x^3+2*x^2-x*4 + (a*x^2+b*x+c)/(6*x^10)");
	BENCHMARK("IsConstant()(positive)")
	{
		return SymConstantManager::IsConstant("e");
	};

	BENCHMARK("IsConstant()(negative)")
	{
		return SymConstantManager::IsConstant("MyConstant");
	};

	BENCHMARK("HasConstants()(positive)")
	{
		return SymConstantManager::HasConstants(expWithConstants.getInfix());
	};

	BENCHMARK("HasConstants()(negative)")
	{
		return SymConstantManager::HasConstants(expWithoutConstants.getInfix());
	};
}
#endif