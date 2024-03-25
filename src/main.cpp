#define CATCH_CONFIG_MAIN 
#include "catch.hpp"

#include "StringSlicing.h"

TEST_CASE("Testing std::string::subview(size_t start, size_t end)")
{
	const std::string source{ "Hello World!" }; // source.size() == 12

	REQUIRE(stdproposal::subview(source, 0, 5) == "Hello");
	REQUIRE(stdproposal::subview(source, 6, 11) == "World");
	REQUIRE(stdproposal::subview(source, 0, 12) == "Hello World!");
	REQUIRE(stdproposal::subview(source, 0, 18) == "Hello World!");
	REQUIRE(stdproposal::subview(source, 3, 15) == "lo World!");
	
	REQUIRE(stdproposal::subview(source, 0, 1) == "H");
	REQUIRE(stdproposal::subview(source, 11, 12) == "!");

	REQUIRE(stdproposal::subview(source, 11, 11) == "");
	REQUIRE(stdproposal::subview(source, 0, 0) == "");
	REQUIRE(stdproposal::subview(source, 6, 6) == "");

	REQUIRE(stdproposal::subview(source, 5, 0) == "");
	REQUIRE(stdproposal::subview(source, 5, 4) == "");
	REQUIRE(stdproposal::subview(source, 11, 10) == "");

	REQUIRE_THROWS_AS(stdproposal::subview(source, 12, 18), std::out_of_range);
	REQUIRE_THROWS_AS(stdproposal::subview(source, 15, 18), std::out_of_range);
}

TEST_CASE("Testing std::string_view::subview(size_t start, size_t end)")
{
	const std::string_view source{ "Hello World!" }; // source.size() == 12

	REQUIRE(stdproposal::subview(source, 0, 5) == "Hello");
	REQUIRE(stdproposal::subview(source, 6, 11) == "World");
	REQUIRE(stdproposal::subview(source, 0, 12) == "Hello World!");
	REQUIRE(stdproposal::subview(source, 0, 18) == "Hello World!");
	REQUIRE(stdproposal::subview(source, 3, 15) == "lo World!");
	
	REQUIRE(stdproposal::subview(source, 0, 1) == "H");
	REQUIRE(stdproposal::subview(source, 11, 12) == "!");

	REQUIRE(stdproposal::subview(source, 11, 11) == "");
	REQUIRE(stdproposal::subview(source, 0, 0) == "");
	REQUIRE(stdproposal::subview(source, 6, 6) == "");

	REQUIRE(stdproposal::subview(source, 5, 0) == "");
	REQUIRE(stdproposal::subview(source, 5, 4) == "");
	REQUIRE(stdproposal::subview(source, 11, 10) == "");

	REQUIRE_THROWS_AS(stdproposal::subview(source, 12, 18), std::out_of_range);
	REQUIRE_THROWS_AS(stdproposal::subview(source, 15, 18), std::out_of_range);
}