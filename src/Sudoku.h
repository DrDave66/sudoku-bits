#pragma once
#ifndef _SUDOKU
#define _SUDOKU
#include <typeinfo>
#include <string>
#include <vector>
#include <iostream>     // std::cout
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <bitset>
#include <random>

using std::vector;
using std::cout;
using std::endl;
using std::setw;
using std::flush;
using std::stringstream;
using std::string;
using std::uint8_t;
using std::uint16_t;

#include "Guess.h"
#include "PrecisionTimeLapse.h"
#include "SudokuTypes.h"

#define ALL_SET 	UINT16_C(0b0000'0001'1111'1111) 
#define ALL_CLEAR 	UINT16_C(0b0000'0000'0000'0000)
class Sudoku
{
public:
    Sudoku();
	Sudoku(string puzzle);
	void clearPuzzle();
	uint64_t clearPuzzleCount;
	void init(void);
    
	bool setPuzzle(string p);
	uint64_t setPuzzleCount;
    //bool setValue(uint8_t row, uint8_t col, BITMASK bm);
	uint64_t setValueCount;
    bool setValue(SQUARE rc, BITMASK bm);
	uint64_t setValueRCCount;
    
	void printPuzzle(void);
	void printPuzzle(string title);
	void printAllowableValues(void);
	void printAllowableValues(string title);
//	static string bitsToString(uint16_t bits);

	void solveOnes(void);
	uint64_t solveOnesCount;
    bool isPuzzleSolved(void);
	uint64_t isPuzzleSolvedCount;
	bool removeGuess(SQUARE, BITMASK);
	uint64_t removeGuessCount;
	bool guessesRemain(void);
	uint64_t guessesRemainCount;
	Guess getGuess();
	uint64_t getGuessCount;
	Guess getGuessRandom();
	bool popGuess();
	uint64_t popGuessCount;
	void pushGuess(const Guess);
	uint64_t pushGuessCount;
	bool solvePuzzle();
	bool startGuessing();
	uint64_t startGuessingCount;
	void printGuessList();
	uint8_t countBits(uint16_t num);
	uint64_t countBitsCount;
	uint8_t singleBitSet(uint16_t b);
	uint64_t singleBitSetCount;
	void printCounts();
	string getPuzzleString();
//private:

	const uint8_t rows[9] = {0,1,2,3,4,5,6,7,8};
	const uint8_t cols[9] = {0,1,2,3,4,5,6,7,8};
	const uint8_t bits[9] = {0,1,2,3,4,5,6,7,8};
	const uint8_t squares[81] = {
	 0, 1, 2, 3, 4, 5, 6, 7, 8,
	 9,10,11,12,13,14,15,16,17,
	18,19,20,21,22,23,24,25,26,
	27,28,29,30,31,32,33,34,35,
	36,37,38,39,40,41,42,43,44,
	45,46,47,48,49,50,51,52,53,
	54,55,56,57,58,59,60,61,62,
	63,64,65,66,67,68,69,70,71,
	72,73,74,75,76,77,78,79,80
	};

	// }
	std::default_random_engine generator;
    SUDOKUTYPE puzzle; // the puzzle
    SUDOKUTYPE allowableValues; // allowable values for each cell
	Guess guessList[81]; // ordered list of guesses
	uint8_t guessNumber; // guess number used for entries in guess list
    Guess newGuess; // static new guess
	const uint16_t bitMask[10] = {
		0b0000'0000'0000'0001,
		0b0000'0000'0000'0010,
		0b0000'0000'0000'0100,
		0b0000'0000'0000'1000,
		0b0000'0000'0001'0000,
		0b0000'0000'0010'0000,
		0b0000'0000'0100'0000,
		0b0000'0000'1000'0000,
		0b0000'0001'0000'0000,
		0b0000'0010'0000'0000
	};

//      1   2   3    4   5   6    7   8   9
//   =========================================
// A || 0 | 1 | 2 || 3 | 4 | 5 || 6 | 7 | 8 ||
// B || 9 | 10| 11|| 12| 13| 14|| 15| 16| 17||
// C || 18| 19| 20|| 21| 22| 23|| 24| 25| 26||
//   || --------- || --------- || --------- ||
// D || 27| 28| 29|| 30| 31| 32|| 33| 34| 35||
// E || 36| 37| 38|| 39| 40| 41|| 42| 43| 44||
// F || 45| 46| 47|| 48| 49| 50|| 51| 52| 53||
//   || --------- || --------- || --------- ||
// G || 54| 55| 56|| 57| 58| 59|| 60| 61| 62||
// H || 63| 64| 65|| 66| 67| 68|| 69| 70| 71||
// I || 72| 73| 74|| 75| 76| 77|| 78| 79| 80||
//   =========================================

//	const SQUARE peers[81][20] = {
//  const SQUARE units[81][3][9] = {
//	const SQUARE unitlist[27][9]= {
#include "BigArrays.h"

	const uint8_t numSquares = 81;
	const uint8_t numUnitList = 27;
	const uint8_t numInUnitList = 9;	
	const uint8_t numUnits = 3;
	const uint8_t numInUnits = 9;	
	const uint8_t numPeers = 20;
};

template<typename T>
static std::string toBinaryString(const T& x)
{
    std::stringstream ss;
    ss << "0b" << std::bitset<sizeof(T) * 8>(x);
	string s = ss.str();
	if(sizeof(T) >=1)
		s.insert(6,"'");
	if(sizeof(T) >=2) {
		s.insert(11,"'");
		s.insert(16,"'");
	}
	if(sizeof(T) >=4) {
		s.insert(21,"'");
		s.insert(26,"'");
		s.insert(31,"'");
		s.insert(36,"'");	
	}
	if(sizeof(T) >=8) {
		s.insert(41,"'");
		s.insert(46,"'");
		s.insert(51,"'");
		s.insert(56,"'");	
		s.insert(61,"'");
		s.insert(66,"'");
		s.insert(71,"'");
		s.insert(76,"'");	
	}
    return s; //ss.str();
}
#endif // _SUDOKU
