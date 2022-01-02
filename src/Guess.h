#pragma once
#ifndef _GUESS
#define _GUESS

#include <string>
#include <cstring>

using std::string;

#include "SudokuTypes.h"

class Sudoku;

class Guess
{
public:
    Guess();
    Guess(SQUARE _square, uint16_t _bit, SUDOKUTYPE& _puzzle, SUDOKUTYPE& _allowableValues);

	Guess(const Guess&);
	Guess& operator=(const Guess& cpy) ;
	string toString();

// members kept public to reduce stack hits
    SUDOKUTYPE puzzle;
    SUDOKUTYPE allowableValues;
	SQUARE square;
	uint16_t guess;
};

#endif // _GUESS

