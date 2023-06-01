#include "PrimeNumbers.h"
#include <boost/timer.hpp>
#include <algorithm>
#include <iostream>
#include <iterator>

int main(int argc, char* argv[])
{
	auto args = GetNumberFromInput(argc, argv);
	if (!args)
	{
		return 1;
	}

	std::cout << "Generating prime numbers from 1 to " << args->upperBound << '.' << std::endl;

	boost::timer t;
	t.restart();

	auto primeNumbers = GeneratePrimeNumbersSet(args->upperBound);

	double duration = t.elapsed();

	std::cout << "Time: " << duration << " sec." << std::endl;
	std::cout << "Count: " << primeNumbers.size() << " unit(s)." << std::endl;

	PrintSet(std::cout, primeNumbers);

	return 0;
}