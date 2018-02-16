#include "catch.hpp"
#include "Board.h"

TEST_CASE("placeMove") {
	Board b;

	SECTION("Out of bounds: x < 0") {
		REQUIRE(b.placeMove(-1, 0, 'X') == false);
	}

	SECTION("Out of bounds: x > BOARD_SIZE") {
		REQUIRE(b.placeMove(3, 0, 'X') == false);
	}

	SECTION("Out of bounds: y < 0") {
		REQUIRE(b.placeMove(0, -1, 'X') == false);
	}

	SECTION("Out of bounds: y > BOARD_SIZE") {
		REQUIRE(b.placeMove(0, 3, 'X') == false);
	}

	SECTION("In bounds") {
		REQUIRE(b.placeMove(0, 0, 'X') == true);
	}
}