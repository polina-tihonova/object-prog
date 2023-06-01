#include "HTMLDecode.h"
#include <array>
#include <string_view>

using namespace std::literals;
namespace
{
	constexpr std::array DECODE_MAP{
		std::pair{"&amp;"sv, '&'},
	};
}

// & -> &
// &amp


void DecodeString(std::istream& input, std::ostream& output)
{
	std::string line;
	while (std::getline(input, line))
	{
		std::cout << DecodeLine(line) << std::endl;
	}
}

std::string DecodeLine(std::string const& htmlString)
{
	bool startDecoding = false;
	std::string decodingString; // =""  не писать
	std::string resultString;
	// Положить file.clang-format 
	for (char htmlSymbol : htmlString)
	{

		if (htmlSymbol == ENCODED_START_SYMBOL)
		{
			if (!decodingString.empty())
			{
				resultString += decodingString;
				decodingString.clear();
			}

			startDecoding = true;
			decodingString += htmlSymbol;
			continue;
		}

		if (startDecoding && htmlSymbol == ENCODED_END_SYMBOL)
		{
			startDecoding = false;
			decodingString += htmlSymbol;
			resultString += DecodeEntity(decodingString);
			decodingString.clear();
			continue;
		}

		if (startDecoding)
		{
			decodingString += htmlSymbol;
			continue;
		}

		resultString += htmlSymbol;
	}

	if (!decodingString.empty())
	{
		resultString += decodingString;
	}

	return resultString;
}

std::string DecodeEntity(std::string const& stringHTMLEntity)
{
	auto decodePair = MAP_SYMBOL_HTML.find(stringHTMLEntity);

	if (decodePair != MAP_SYMBOL_HTML.end())
	{
		return std::string(1, decodePair->second);
	}
	else
	{
		return stringHTMLEntity;
	}
}