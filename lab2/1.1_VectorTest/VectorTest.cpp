#define CATCH_CONFIG_MAIN
#include <../catch2/catch.hpp>
#include "../1.1_Vector/Vector.cpp"


SCENARIO("Process empty vector")
{
	std::vector<float> initialVector = { };
	std::vector<float> resultVector = { };

	MultiplyVectorByMinElement(initialVector);

	CHECK(CompareVectors(initialVector, resultVector));
}

SCENARIO("Process vector with one element")
{
	std::vector<float> initialVector = { 1.333f};
	std::vector<float> resultVector = { 1.777f };

	MultiplyVectorByMinElement(initialVector);

	CHECK(CompareVectors(initialVector, resultVector));
}

SCENARIO("Process vector with several positive elements")
{
	std::vector<float> initialVector = { 9.1f, 2.0f, 7.33f, 4.01f };
	std::vector<float> resultVector = { 18.2f, 4.0f, 14.66f, 8.02f};

	MultiplyVectorByMinElement(initialVector);

	CHECK(CompareVectors(initialVector, resultVector));
}