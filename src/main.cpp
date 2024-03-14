#define CATCH_CONFIG_MAIN 
#include "catch.hpp"

#include "StringSlicing.h"

TEST_CASE("Testing slice(size_t start, size_t end)")
{
	const std::string source{ "Hello World!" }; // source.size() == 12

	REQUIRE(stdproposal::slice(source, 0, 5) == "Hello");
	REQUIRE(stdproposal::slice(source, 6, 11) == "World");
	REQUIRE(stdproposal::slice(source, 0, 12) == "Hello World!");
	REQUIRE(stdproposal::slice(source, 0, 18) == "Hello World!");
	REQUIRE(stdproposal::slice(source, 3, 15) == "lo World!");
	
	REQUIRE(stdproposal::slice(source, 0, 1) == "H");
	REQUIRE(stdproposal::slice(source, 11, 12) == "!");

	REQUIRE(stdproposal::slice(source, 11, 11) == "");
	REQUIRE(stdproposal::slice(source, 0, 0) == "");
	REQUIRE(stdproposal::slice(source, 6, 6) == "");

	REQUIRE(stdproposal::slice(source, 5, 0) == "");
	REQUIRE(stdproposal::slice(source, 5, 4) == "");
	REQUIRE(stdproposal::slice(source, 11, 10) == "");

	REQUIRE_THROWS_AS(stdproposal::slice(source, 12, 18), std::out_of_range);
	REQUIRE_THROWS_AS(stdproposal::slice(source, 15, 18), std::out_of_range);
}

TEST_CASE("Testing slice(size_t start, size_t end, size_t step)")
{
	const std::string source{ "Hello World!" }; // source.size() == 12

	REQUIRE(stdproposal::slice(source, 0, 5, 0) == "Hello");
	REQUIRE(stdproposal::slice(source, 0, 5, 1) == "Hello");
	REQUIRE(stdproposal::slice(source, 6, 11, 0) == "World");
	REQUIRE(stdproposal::slice(source, 6, 11, 1) == "World");

	REQUIRE(stdproposal::slice(source, 0, 12, 2) == "HloWrd");
	REQUIRE(stdproposal::slice(source, 0, 12, 3) == "HlWl");
	REQUIRE(stdproposal::slice(source, 0, 12, 12) == "H");
	REQUIRE(stdproposal::slice(source, 3, 6, 3) == "l");

	REQUIRE(stdproposal::slice(source, 6, 3, 3) == "");
	REQUIRE(stdproposal::slice(source, 6, 3, 1) == "");
	REQUIRE(stdproposal::slice(source, 6, 3, 0) == "");
	REQUIRE(stdproposal::slice(source, 8, 5, 3) == "");

	REQUIRE_THROWS_AS(stdproposal::slice(source, 0, 5, 7), std::out_of_range);
	REQUIRE_THROWS_AS(stdproposal::slice(source, 0, 5, 13), std::out_of_range);

	REQUIRE_THROWS_AS(stdproposal::slice(source, 13, 12, 3), std::out_of_range);
	REQUIRE_THROWS_AS(stdproposal::slice(source, 12, 15, 0), std::out_of_range);
}

TEST_CASE("Testing first(size_t count)")
{
	const std::string source{ "Hello World!" }; // source.size() == 12

	REQUIRE(stdproposal::first(source, 1) == "H");
	REQUIRE(stdproposal::first(source, 3) == "Hel");
	REQUIRE(stdproposal::first(source, 7) == "Hello W");
	REQUIRE(stdproposal::first(source, 12) == "Hello World!");
	REQUIRE(stdproposal::first(source, 16) == "Hello World!");

	REQUIRE(stdproposal::first(source, 0) == "");
}

TEST_CASE("Testing last(size_t count)")
{
	const std::string source{ "Hello World!" }; // source.size() == 12

	REQUIRE(stdproposal::last(source, 1) == "!");
	REQUIRE(stdproposal::last(source, 3) == "ld!");
	REQUIRE(stdproposal::last(source, 7) == " World!");
	REQUIRE(stdproposal::last(source, 12) == "Hello World!");
	REQUIRE(stdproposal::last(source, 18) == "Hello World!");

	REQUIRE(stdproposal::last(source, 0) == "");
}