#include "catch.hpp"
#include "Board.h"

TEST_CASE("validInput") {
	Board b;

	SECTION("Out of bounds: x < 0") {
		REQUIRE(b.validInputPrint(-1, 0) == false);
	}

	SECTION("Out of bounds: x > BOARD_SIZE") {
		REQUIRE(b.validInputPrint(3, 0) == false);
	}

	SECTION("Out of bounds: y < 0") {
		REQUIRE(b.validInputPrint(0, -1) == false);
	}

	SECTION("Out of bounds: y > BOARD_SIZE") {
		REQUIRE(b.validInputPrint(0, 3) == false);
	}

	SECTION("In bounds") {
		REQUIRE(b.validInputPrint(0, 0) == true);
	}

	SECTION("Location occupied") {
		b.placeMove(0, 0, 'X');
		REQUIRE(b.validInputPrint(0, 0) == false);
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

TEST_CASE("checkColumns") {
	Board b;

	SECTION("No winner empty board") {
		REQUIRE(b.checkColumns() == false);
	}

	SECTION("No winner no matches XXO") {
		b.placeMove(0, 0, 'X');
		b.placeMove(0, 1, 'X');
		b.placeMove(0, 2, 'O');
		REQUIRE(b.checkColumns() == false);
	}

	SECTION("No winner no matches XOX") {
		b.placeMove(0, 0, 'X');
		b.placeMove(0, 1, 'O');
		b.placeMove(0, 2, 'X');
		REQUIRE(b.checkColumns() == false);
	}

	SECTION("No winner no matches OXX") {
		b.placeMove(0, 0, 'O');
		b.placeMove(0, 1, 'X');
		b.placeMove(0, 2, 'X');
		REQUIRE(b.checkColumns() == false);
	}

	SECTION("Winner left column") {
		b.placeMove(0, 0, 'X');
		b.placeMove(0, 1, 'X');
		b.placeMove(0, 2, 'X');
		REQUIRE(b.checkColumns() == true);
	}

	SECTION("Winner middle column") {
		b.placeMove(1, 0, 'X');
		b.placeMove(1, 1, 'X');
		b.placeMove(1, 2, 'X');
		REQUIRE(b.checkColumns() == true);
	}

	SECTION("Winner right column") {
		b.placeMove(2, 0, 'X');
		b.placeMove(2, 1, 'X');
		b.placeMove(2, 2, 'X');
		REQUIRE(b.checkColumns() == true);
	}
}

TEST_CASE("checkDiagonals") {
	Board b;

	SECTION("No winner empty board") {
		REQUIRE(b.checkDiagonals() == false);
	}

	SECTION("No winner top left to bottom right XXO") {
		b.placeMove(0, 0, 'X');
		b.placeMove(1, 1, 'X');
		b.placeMove(2, 2, 'O');
		REQUIRE(b.checkDiagonals() == false);
	}

	SECTION("No winner top left to bottom right XOX") {
		b.placeMove(0, 0, 'X');
		b.placeMove(1, 1, 'O');
		b.placeMove(2, 2, 'X');
		REQUIRE(b.checkDiagonals() == false);
	}

	SECTION("No winner top left to bottom right OXX") {
		b.placeMove(0, 0, 'O');
		b.placeMove(1, 1, 'X');
		b.placeMove(2, 2, 'X');
		REQUIRE(b.checkDiagonals() == false);
	}

	SECTION("No winner bottom left to top right XXO") {
		b.placeMove(0, 2, 'X');
		b.placeMove(1, 1, 'X');
		b.placeMove(2, 0, 'O');
		REQUIRE(b.checkDiagonals() == false);
	}

	SECTION("No winner bottom left to top right XOX") {
		b.placeMove(0, 2, 'X');
		b.placeMove(1, 1, 'O');
		b.placeMove(2, 0, 'X');
		REQUIRE(b.checkDiagonals() == false);
	}

	SECTION("No winner bottom left to top right OXX") {
		b.placeMove(0, 2, 'O');
		b.placeMove(1, 1, 'X');
		b.placeMove(2, 0, 'X');
		REQUIRE(b.checkDiagonals() == false);
	}

	SECTION("Winner top left to bottom right") {
		b.placeMove(0, 0, 'X');
		b.placeMove(1, 1, 'X');
		b.placeMove(2, 2, 'X');
		REQUIRE(b.checkDiagonals() == true);
	}

	SECTION("Winner bottom left to top right") {
		b.placeMove(0, 2, 'X');
		b.placeMove(1, 1, 'X');
		b.placeMove(2, 0, 'X');
		REQUIRE(b.checkDiagonals() == true);
	}
}