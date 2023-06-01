#pragma once
#include <optional>
#include <iostream>
#include <string>
#include <set>
#include <vector>

const unsigned int MAX_UPPER_BOUND = 100000000;

struct Args
{
	unsigned int upperBound;
};

std::optional<Args> GetNumberFromInput(int argc, char* argv[]);
std::vector<bool> GeneratePrimeNumbersSieve(unsigned int upperBound);
std::set<int> GeneratePrimeNumbersSet(unsigned int upperBound);
void PrintSet(std::ostream& output, std::set<int> const& primeSet);
