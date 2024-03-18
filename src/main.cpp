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