#include "Vector.h"

int main()
{
	std::vector<float> vector;
	vector = ReadVector(std::cin);
	SortVector(vector);
	MultiplyVectorByMinElement(vector);
	PrintVector(std::cout, vector);
}