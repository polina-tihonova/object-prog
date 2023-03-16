#include <fstream>
#include <iostream>
#include <optional>
#include <bitset>
#include <string>
#include <vector>

using namespace std;
const unsigned int ARGS_COUNT = 2;
const unsigned int MIN_NUMBER = 0;
const unsigned int MAX_NUMBER = 255;

struct Args
{
	unsigned int inputNumber;
};

int FlipByte(unsigned int inputNumber);
unsigned char ReverseBytes(unsigned char byte);
std::optional<Args> ParseArgs(int argc, char* argv[]);


int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	unsigned int outputNumber;
	outputNumber = FlipByte(args->inputNumber);
	std::cout << outputNumber << std::endl;

	return 0;
}


std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != ARGS_COUNT)
	{
		std::cout << "Invalid arguments count. Usage: 2.5_FlipByte.exe <input byte>\n";
		return std::nullopt;
	}

	unsigned int argNumber;
	try
	{
		argNumber = std::stoi(argv[1]);

		if (argNumber < MIN_NUMBER || argNumber > MAX_NUMBER)
		{
			std::cout << "Invalid argument. Permit only digit, value from 0 to 255\n";;
			return std::nullopt;
		}
	}
	catch (...)
	{
		std::cout << "Invalid argument. Permit only digit, value from 0 to 255\n";;
		return std::nullopt;
	}

	Args args;
	args.inputNumber = argNumber;
	return args;
}


int FlipByte(unsigned int inputNumber)
{
	unsigned char byte = (unsigned char)inputNumber;
	return static_cast<int>(ReverseBytes(byte));
}


unsigned char ReverseBytes(unsigned char byte)
{
	byte = (byte & 0xF0) >> 4 | (byte & 0x0F) << 4;
	byte = (byte & 0xCC) >> 2 | (byte & 0x33) << 2;
	byte = (byte & 0xAA) >> 1 | (byte & 0x55) << 1;
	return byte;
}