#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include"Catch2TestFramework/catch.hpp"
#include"../SymConstantManager.h"
#include"../SymParser.h"
#include<string>

using std::string;

TEST_CASE("Test of IsConstant() function(positive case)")
{
	string testConstant = GENERATE("e", "pi");
	CHECK(SymConstantManager::IsConstant(testConstant));
}
TEST_CASE("Test of IsConstant() functino(negative case)")
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
TEST_CASE("")
{

}
#endif