#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct Args
{
	std::string inputFileName;
	std::string seacrhString;
};

std::optional<Args> ParseArgs(int argc, char* argv[]);
int FindText(std::optional<Args> args, std::ostream &outputFile);
std::vector<size_t> FindEntries(std::ifstream& input, const std::string& replaceString);
std::string ToLower(std::string str);

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	return FindText(args, std::cout);
}

int FindText(std::optional<Args> args, std::ostream &outputFile)
{
	std::ifstream input;
	input.open(args->inputFileName);

	if (!input)
	{
		outputFile << "Failed to open '" << args->inputFileName << "' for reading\n";
		return 1;
	}

	auto entries = FindEntries(input, args->seacrhString);

	if (entries.empty())
	{
		outputFile << "Text not found!\n";
		return 1;
	}

	for (auto entry : entries) {
		outputFile << entry << std::endl;
	}
	return 0;
}

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments count. Usage: 1.3_FindText.exe <file name> <text to search>\n";
		return std::nullopt;
	}

	Args args;
	args.inputFileName = argv[1];
	args.seacrhString = argv[2];
	return args;
}

std::vector<size_t> FindEntries(std::ifstream& input, const std::string& searchString)
{
	std::vector<size_t> entries;
	std::string line;
	size_t line_index = 0;

	while (std::getline(input, line))
	{
		line_index += 1;
		if (ToLower(line).find(ToLower(searchString)) != std::string::npos)
		{
			entries.push_back(line_index);
		}
	}

	return entries;
}

std::string ToLower(std::string str)
{
	for (auto& string : str)
	{
		string = tolower(static_cast<unsigned char>(string));
	}
	return str;
}