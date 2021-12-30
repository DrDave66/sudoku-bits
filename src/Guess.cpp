#include "Guess.h"

Guess::Guess() {
    square = RowCol(10,10);
    
}
Guess::Guess(RowCol _square, uint16_t _guess,SUDOKUTYPE _puzzle, SUDOKUTYPE _allowableValues) {
    puzzle = _puzzle;
    allowableValues = _allowableValues;
    square = _square;
	guess = _guess;
}

Guess::Guess(const Guess& g) {
    puzzle = g.puzzle;
    allowableValues = g.allowableValues;
	square = g.square;
	guess = g.guess;
}

Guess& Guess::operator=(const Guess& cpy) {
	square = cpy.square;
	guess = cpy.guess;
    puzzle = cpy.puzzle;
    allowableValues = cpy.allowableValues;

	return *this;
}

string Guess::toString() {
//	char ss[1000];
//    sprintf(ss,"Square: %s, Guess: %s,\n",square.toString().c_str(), Sudoku::bitToString(guess));
	string retval;
	return retval;
}