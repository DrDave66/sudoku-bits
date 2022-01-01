#include "Guess.h"

Guess::Guess() {
    square = RowCol(10,10);
    
}
Guess::Guess(RowCol _square, uint16_t _guess,SUDOKUTYPE& _puzzle, SUDOKUTYPE& _allowableValues) {
    memcpy(puzzle,_puzzle,sizeof(SUDOKUTYPE));
    memcpy(allowableValues, _allowableValues, sizeof(SUDOKUTYPE));
    square = _square;
	guess = _guess;
}

Guess::Guess(const Guess& g) {
    memcpy(puzzle,g.puzzle,sizeof(SUDOKUTYPE));
    memcpy(allowableValues, g.allowableValues, sizeof(SUDOKUTYPE));
	square = g.square;
	guess = g.guess;
}

Guess& Guess::operator=(const Guess& cpy) {
	square = cpy.square;
	guess = cpy.guess;
    memcpy(puzzle,cpy.puzzle,sizeof(SUDOKUTYPE));
    memcpy(allowableValues, cpy.allowableValues, sizeof(SUDOKUTYPE));

	return *this;
}

string Guess::toString() {
//	char ss[1000];
//    sprintf(ss,"Square: %s, Guess: %s,\n",square.toString().c_str(), Sudoku::bitToString(guess));
	string retval;
	return retval;
}