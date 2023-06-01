#include <vector>
#include <iomanip>
#include <iostream>
#include <optional>
#include <algorithm>


std::vector<float> ReadVector(std::istream& input);
std::optional<float> FindVectorMinElement(std::vector<float>& vector);
void PrintVector(std::ostream& output, std::vector<float>& vector);
void MultiplyVectorByMinElement(std::vector<float>& vector);
void SortVector(std::vector<float>& vector);
bool CompareVectors(std::vector<float>& first, std::vector<float>& second);