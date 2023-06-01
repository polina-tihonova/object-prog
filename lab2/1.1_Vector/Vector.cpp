#include "Vector.h"

float NUM_PRECISION = 0.001f;

std::vector<float> ReadVector(std::istream& input)
{
	std::vector<float> vector;
	float element;

	while (input >> element)
	{
		vector.push_back(element);
	}

	return vector;
}

void PrintVector(std::ostream& output, std::vector<float>& vector)
{
	output << std::fixed << std::setprecision(3);
	for (auto element : vector)
	{
		output << element << " ";
	}
	output << std::endl;
}

void MultiplyVectorByMinElement(std::vector<float>& vector)
{
	const auto minElement = FindVectorMinElement(vector);

	if (minElement) {
		// Убрать округление - Сделано
		std::transform(vector.begin(), vector.end(), vector.begin(),
			// Принимать element по значению - Сделано
			[scale = *minElement](float element) { return element * scale; }
		);
	}
}

std::optional<float> FindVectorMinElement(std::vector<float>& vector)
{
	if (vector.size() == 0)
	{
		return std::nullopt;
	}

	return *std::min_element(vector.begin(), vector.end());
}

void SortVector(std::vector<float>& vector)
{
	std::sort(vector.begin(), vector.end());
}

// Добавлено
bool CompareVectors(std::vector<float>& first, std::vector<float>& second)
{
	bool isEqual = true;
	for (std::size_t i = 0; i < std::min(first.size(), second.size()); i++)
	{
		if (!(abs(first[i] - second[i]) < 0.001))
		{
			isEqual = false;
			return isEqual;
		}
	}
	return isEqual;
}
