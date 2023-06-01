#define CATCH_CONFIG_MAIN 
#include <catch2/catch.hpp>

#include "../4.4_PrimeNumbers/PrimeNumbers.cpp"

// [Исправлено] Проверка на значения вместо количества
SCENARIO("Generate prime numbers.")
{
	std::set<int> initialPrimeSet;
	std::set<int> resultPrimeSet;

	initialPrimeSet = GeneratePrimeNumbersSet(0);
	resultPrimeSet = {};
	CHECK(initialPrimeSet == resultPrimeSet);

	// [Исправлено] Проверить с 1
	initialPrimeSet = GeneratePrimeNumbersSet(1);
	resultPrimeSet = {};
	CHECK(initialPrimeSet == resultPrimeSet);

	initialPrimeSet = GeneratePrimeNumbersSet(18);
	resultPrimeSet = {2, 3, 5, 7, 11, 13, 17};
	CHECK(initialPrimeSet == resultPrimeSet);

#ifdef NDEBUG // Компилируется только в релизе
	initialPrimeSet = GeneratePrimeNumbersSet(100000000);
	CHECK(initialPrimeSet.size() == 5761455);
#endif
}

SCENARIO("Generate prime numbers (invalid upper bound).")
{
	std::set<int> initialPrimeSet = GeneratePrimeNumbersSet(100000001);
	std::set<int> resultPrimeSet = {};
	CHECK(initialPrimeSet == resultPrimeSet);

	// [Исправлено] Удален тест с -1, т.к. тип unsigned int
}