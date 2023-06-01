#pragma once
#include <map>
//Только нужные для компиляции include
#include <vector>
#include <string>
#include <optional>
#include <iostream>
#include <algorithm>

//Перенести в cpp
const char ENCODED_START_SYMBOL = '&';
const char ENCODED_END_SYMBOL = ';';

//array<pair<string_view, string_view>>
const std::map<std::string, char> MAP_SYMBOL_HTML =
{
	{"&quot;", '"'},
	{"&apos;", '\''},
	{"&lt;",   '<'},
	{"&gt;",   '>'},
	{"&amp;",  '&'}
};
//
void DecodeString(std::istream& input, std::ostream& output);
std::string DecodeLine(std::string const& htmlString);
std::string DecodeEntity(std::string const& stringHTMLEntity);