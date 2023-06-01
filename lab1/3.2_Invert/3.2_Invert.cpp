#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <optional>

using namespace std;

const int MATRIX_SIZE = 3;
typedef std::array<std::array<double, MATRIX_SIZE>, MATRIX_SIZE> Matrix3;
typedef std::array<double, MATRIX_SIZE> MatrixLine3;

struct Args
{
	std::string inputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[]);
int Invert(std::string inputFilePath, std::ostream& outputFile);


int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	return Invert(args->inputFileName, std::cout);
}


std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments count. Usage: 3.2_Invert.exe <matrix file1>\n";
		return std::nullopt;
	}

	Args args;
	args.inputFileName = argv[1];
	return args;
}


int Invert(std::string inputFilePath, std::ostream& outputFile)
{
	auto matrix = ReadMatrix(inputFilePath, outputFile);

	if (!matrix)
	{
		outputFile << "Failed to read matrix\n";
		return 1;
	}
}

std::optional<Matrix3> ReadMatrix(std::string inputFilePath, std::ostream& outputFile)
{
	std::ifstream input;
	input.open(inputFilePath);

	if (!input)
	{
		outputFile << "Failed to open '" << inputFilePath << "' for reading\n";
		return std::nullopt;
	}

	std::string line;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		if (!getline(input, line))
		{
			cout << "Failed to read matrix" << "\n";
			return std::nullopt;
		}

		auto  ReadMatrixLine(line);
	}
}

std::optional<MatrixLine3> ReadMatrixLine(std::string line)
{
	Matrix3

	std::stringstream lineStream;
	lineStream << line;

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		double number;

		if (lineStream >> number)
		{
			matrix[i][j] = temp;
		}
		else
		{
			cout << "Failed to read matrix" << "\n";
			return std::nullopt;
		}
	}
}
