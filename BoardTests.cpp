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

	SECTION("Location occupied") {
		b.placeMove(0, 0, 'X');
		REQUIRE(b.placeMove(0, 0, 'O') == false);
	}

}

TEST_CASE("checkRows") {
	Board b;

	SECTION("No winner empty board") {
		REQUIRE(b.checkRows() == false);
	}

	SECTION("No winner no matches XXO") {
		b.placeMove(0, 0, 'X');
		b.placeMove(1, 0, 'X');
		b.placeMove(2, 0, 'O');
		REQUIRE(b.checkRows() == false);
	}

	SECTION("No winner no matches XOX") {
		b.placeMove(0, 0, 'X');
		b.placeMove(1, 0, 'O');
		b.placeMove(2, 0, 'X');
		REQUIRE(b.checkRows() == false);
	}

	SECTION("No winner no matches OXX") {
		b.placeMove(0, 0, 'O');
		b.placeMove(1, 0, 'X');
		b.placeMove(2, 0, 'X');
		REQUIRE(b.checkRows() == false);
	}

	SECTION("Winner top row") {
		b.placeMove(0, 0, 'X');
		b.placeMove(1, 0, 'X');
		b.placeMove(2, 0, 'X');
		REQUIRE(b.checkRows() == true);
	}

	SECTION("Winner middle row") {
		b.placeMove(0, 1, 'X');
		b.placeMove(1, 1, 'X');
		b.placeMove(2, 1, 'X');
		REQUIRE(b.checkRows() == true);
	}

	SECTION("Winner bottom row") {
		b.placeMove(0, 2, 'X');
		b.placeMove(1, 2, 'X');
		b.placeMove(2, 2, 'X');
		REQUIRE(b.checkRows() == true);
	}
}