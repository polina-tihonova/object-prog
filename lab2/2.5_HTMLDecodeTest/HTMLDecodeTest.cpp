#define CATCH_CONFIG_MAIN
#include <../catch2/catch.hpp>
#include "../2.5_HtmlDecode/HtmlDecode.cpp"

SCENARIO("Decoding empty string gives empty string")
{
	std::string initialHTMLString = "";
	std::string resultString = "";

	std::string decodedHTMLString = DecodeLine(initialHTMLString);

	CHECK(decodedHTMLString == resultString);
}

SCENARIO("Decoding nonempty string with special symbols")
{
	std::string initialHTMLString = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	std::string resultString = "Cat <says> \"Meow\". M&M's";

	std::string decodedHTMLString = DecodeLine(initialHTMLString);

	CHECK(decodedHTMLString == resultString);
}

SCENARIO("Decoding nonempty string with wrong special symbols")
{
	std::string initialHTMLString = "Cat &lt123;says&gt; &quot;Meow&quot123;. M&amp;M&apos;s";
	std::string resultString = "Cat &lt123;says> \"Meow&quot123;. M&M's";

	std::string decodedHTMLString = DecodeLine(initialHTMLString);

	CHECK(decodedHTMLString == resultString);
}

SCENARIO("Decoding nonempty string with unclosed special symbols")
{
	std::string initialHTMLString = "&amp &amp &amp; &amp &amp; &amp";
	std::string resultString = "&amp &amp & &amp & &amp";

	std::string decodedHTMLString = DecodeLine(initialHTMLString);

	CHECK(decodedHTMLString == resultString);
}