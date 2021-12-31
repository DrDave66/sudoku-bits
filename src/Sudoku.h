#pragma once
#ifndef _SUDOKU
#define _SUDOKU
#include <array>
#include <typeinfo>
#include <string>
#include <vector>
#include <set>
#include <iostream>     // std::cout
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <bitset>
#include <random>

using std::array;
using std::vector;
using std::set;
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
#include "RowCol.h"

#define ALL_SET 	UINT16_C(0b0000'0001'1111'1111) 
#define ALL_CLEAR 	UINT16_C(0b0000'0000'0000'0000)
class Sudoku
{
public:
    Sudoku();
	Sudoku(string puzzle);
	void clearPuzzle();
	uint64_t clearPuzzleCount;
	void createVectors(void);
    
	bool setPuzzle(string p);
	uint64_t setPuzzleCount;
    bool setValue(uint8_t row, uint8_t col, BITMASK bm);
	uint64_t setValueCount;
    bool setValue(RowCol rc, BITMASK bm);
	uint64_t setValueRCCount;
    
	void printPuzzle(void);
	void printPuzzle(string title);
	void printAllowableValues(void);
	void printAllowableValues(string title);
	static string bitsToString(uint16_t bits);

	void solveOnes(void);
	uint64_t solveOnesCount;
    bool isPuzzleSolved(void);
	uint64_t isPuzzleSolvedCount;
	bool removeGuess(RowCol, BITMASK);
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
	uint8_t singleBitSet(uint16_t b);
	uint64_t singleBitSetCount;
	void printCounts();
//private:
    // these arrays are used for optimized iteration
    array<uint8_t,9> rows;
    array<uint8_t,9> cols;
	array<uint8_t,9> bits;
//	uint8_t rows[9];
//	uint8_t cols[9];
//	uint8_t bits[9];

	std::default_random_engine generator;

	
	// arrays for unitList, units and peers
	// 27 units to list, 9 entries in a unitlist
    array<array<RowCol, 9> ,27> unitList;
	// each cell belongs to 3 units, each having 9 cells
	array<array<array<array<RowCol, 9> ,3 > ,9> ,9> units;
	// each cell has 20 peers
    array<array<array<RowCol, 20> ,9> ,9> peers;

    SUDOKUTYPE puzzle; // the puzzle
    SUDOKUTYPE allowableValues; // allowable values for each cell
	array<Guess, 81> guessList; // ordered list of guesses
	uint8_t guessNumber; // guess number used for entries in guess list
    Guess newGuess; // static new guess
	array<uint16_t, 10> bitMask; // bit masks for all values

};

// this is used to programmically populate cells, units, unitlists and peers
// it uses a vector because the return size is unknown
// crossProduct will take any two iterables
template <class T, class U>
vector<RowCol> crossProduct (T a, U b) {
    static vector<RowCol> v;
    v.clear();
    for(uint8_t aa : a) {
        for (uint8_t bb : b) {
            v.push_back(RowCol(aa,bb));
        }
    }
	return v;
}

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
