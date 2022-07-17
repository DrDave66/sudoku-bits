/**
 * @file Sudoku.cpp
 * @author Dave Landis
 * @brief Implements a Sudoku puzzle solver
 * @version 0.1
 * @date 2021-12-25
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "Sudoku.h"
#include <locale>
#include <chrono>
#include <random>

std::uniform_int_distribution<uint8_t> rand08(0,8);	
std::uniform_int_distribution<uint16_t> rand01M(0,16959);	

/**
 * @brief given a square, returns a string representation
 * 
 * @param s square number
 * @return string representation of square (e.g. A5, D7)
 */
string squareToText(SQUARE s) {
    uint8_t r,c;
    string retval;
    retval.clear();
    r = s / 9;
    c = s % 9;
    retval += (char)('A' + r);
    retval += (char)('1' + c);
	return retval;
}

/**
 * @brief Construct a new Sudoku:: Sudoku object
 *
 */
Sudoku::Sudoku()
{
    init();
    clearPuzzle();
}

/**
 * @brief Construct a new Sudoku:: Sudoku object given a puzzle string
 *
 * @param puzzle
 */
Sudoku::Sudoku(string puzzle)
{
    init();
    clearPuzzle();
    setPuzzle(puzzle);
}

#define xPRINTVECTORS
/**
 * @brief sets initial counts to zero and seeds the RNG
 *
 */
void Sudoku::init(void)
{
    // seed PRNG 
	generator.seed((unsigned)std::chrono::system_clock::now().time_since_epoch().count());
    startGuessingCount=0;
    countBitsCount=0;
    clearPuzzleCount=0;
    setPuzzleCount=0;
    setValueCount=0;
    setValueRCCount=0;
    solveOnesCount=0;
    isPuzzleSolvedCount=0;
    removeGuessCount=0;
    guessesRemainCount=0;
    getGuessCount=0;
    popGuessCount=0;
    pushGuessCount=0;
    singleBitSetCount=0;
    array<Guess, 81> guessList; // ordered list of guesses

#ifdef PRINTVECTORS
    cout << endl << endl << "Squares " << endl;

    for(auto r:rows) {
        for (auto c:cols) {
            cout << squareToText(c + r*9) << " ";
        }
        cout << endl;
    }
    cout << "UnitList" << endl;
    for( int8_t ul = 0 ; ul < 27 ; ul++) {
        for (int8_t s = 0 ; s < 9 ; s++) {
            cout << squareToText(unitlist[ul][s]) << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;

    cout << endl
         << endl;
    uint8_t sq;
    for (uint8_t r = 0 ; r < 9 ; r++) 
    {
        for (uint8_t c = 0 ; c < 9 ; c++) 
        {
            sq = c + r*9;
            cout << "New Unit Dict: " << squareToText(sq) << " " << endl;
            for (int unum = 0; unum < 3; unum++)
            {
                for (i = 0; i < 9; i++)
                {
                    cout << squareToText(units[sq][unum][i]) << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    cout << endl << endl << "Peers" << endl;
    for (uint8_t r = 0 ; r < 9 ; r++) 
    {
        for (uint8_t c = 0 ; c < 9 ; c++) 
        {
            uint8_t sq = c + r*9;
            cout << squareToText(sq) << " - ";
            for(uint8_t p = 0 ; p < 20 ; p++) {
                cout << squareToText(peers[sq][p]) << " " ;
            }
            cout << endl;
        }
    }
#endif
}

/**
 * @brief Clears the puzzle and allowableValue members
 *
 */
void Sudoku::clearPuzzle(void)
{
    clearPuzzleCount++;
    for (uint8_t sq = 0 ; sq < 81 ; sq ++) {
        puzzle[sq] = ALL_CLEAR;
        allowableValues[sq] = ALL_SET;
    }
}

/**
 * @brief Sets a puzzle from a string
 *
 * @param string Text string of 81 or more characters
 * @return true if successful
 * @return false if conflict
 *
 * use a '.' character to represent a blank cell
 * example: "..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3.."
 */
bool Sudoku::setPuzzle(string p)
{
    setPuzzleCount++;
    char v;
    uint8_t b;
    if (p.size() < 81)
        return false;
    clearPuzzle();
    for(uint8_t sq = 0 ; sq < numSquares ; sq++) {
        v = p[sq];
        if (v == '.' || v == '0')
            b = 9;
        else
            b = (v - '1'); // which bit to set
        if (setValue(sq, bitMask[b]) == false)
        {
            return false;
        }
    }
    return true;
}

/**********************************************************
**********   Printing Functions ***************************
***********************************************************/

/**
 * @brief Print a puzzle with a title
 *
 * @param string Title for the puzzle
 */
void Sudoku::printPuzzle(string title)
{
    cout << endl
         << title;
    printPuzzle();
}

/**
 * @brief Prints a formatted puzzle representation
 *
 */
void Sudoku::printPuzzle(void)
{
    string header = "     1   2   3    4   5   6    7   8   9";
    string top = "  =========================================";
    string row_sep = "  || --------- || --------- || --------- ||";
    string col_sep = "||";
    string num_sep = "|";
    cout << endl
         << header << endl;
    cout << top << endl;
    uint32_t col_num = -1;
    uint32_t row_num = -1;
    string index;
    for (uint8_t r = 0 ; r < 9 ; r++) 
    {
        cout << (char)('A' + r) << " " << col_sep;
        for (uint8_t c = 0 ; c < 9 ; c++) 
        {
           if (puzzle[c + r*9] == ALL_CLEAR)
            {
                cout << " .";
            }
            else
            {
                for (uint8_t b = 0 ; b < 9 ; b++) 
                {
                    if ((puzzle[c + r*9] & bitMask[b]) > 0)
                    {
                        cout << " " << b + 1;
                    }
                }
            }
            if (col_num > 0 && (col_num - 1) % 3 == 0)
            {
                cout << " " << col_sep;
            }
            else
            {
                cout << " " << num_sep;
            }
            col_num++;
        }
        row_num++;
        cout << endl;
        if (row_num == 8)
        {
            cout << top << endl;
        }
        else if ((row_num + 1) % 3 == 0)
        {
            cout << row_sep << endl;
        }
    }
}

/**
 * @brief prints a formatted allowable value matrix
 *
 */
void Sudoku::printAllowableValues(void)
{
    string header = "         1           2           3            4           5           6            7           8           9";
    string top = "  =================================================================================================================";
    string row_sep = "  || --------------------------------- || --------------------------------- || --------------------------------- ||";
    string col_sep = "||";
    string num_sep = "|";
    cout << endl
         << header << endl;
    cout << top << endl;
    uint32_t col_num = -1;
    uint32_t row_num = -1;
    string outstr;
    for (uint8_t r = 0 ; r < 9 ; r++) 
    {
        cout << (char)('A' + r) << " " << col_sep;
        for (uint8_t c = 0 ; c < 9 ; c++) 
        {
            if (puzzle[c + r*9] != ALL_CLEAR)
            {
                outstr = " ";
            }
            else
            {
                stringstream ss;
                for (uint8_t b = 0 ; b < 9 ; b++) 
                {
                    if ((allowableValues[c + r*9] & bitMask[b]) > 0)
                    {
                        ss << int(b + 1);
                    }
                }
                outstr = ss.str();
            }
            cout << setw(10);
            cout << outstr;
            cout << setw(1);
            if (col_num > 0 && (col_num - 1) % 3 == 0)
            {
                cout << " " << col_sep;
            }
            else
            {
                cout << " " << num_sep;
            }
            col_num++;
        }
        row_num++;
        cout << endl;
        if (row_num == 8)
        {
            cout << top << endl;
        }
        else if ((row_num + 1) % 3 == 0)
        {
            cout << row_sep << endl;
        }
    }
}

// /**
//  * @brief Prints formatted allowable value matrix with title
//  *
//  * @param string The title for the allowable value matrix
//  */
void Sudoku::printAllowableValues(string title)
{
    cout << endl
         << title;
    printAllowableValues();
}

// /**********************************************************
//  **********   Solving Functions ***************************
//  ***********************************************************/

/**
 * @brief Sets the value of a cell in a puzzle
 *
 * @param r the cell's row
 * @param c the cell's column
 * @param bm a bitmask of the value to be set, 1 indicates bit to be set. send a value of 10 to indicate blank cell
 * @return true if successful
 * @return false if fails
 */
bool Sudoku::setValue(SQUARE sq, BITMASK bm)
{
    setValueCount++;
    if (bm == bitMask[9])
    { // if value is empty
        puzzle[sq] = ALL_CLEAR; // don't mess with allowable values
        return true;
    }
    else // if value is real
    { 
        // make sure the value is allowed to be set
        if ((allowableValues[sq] & bm) == 0)
        {
            // if not, return false
            return false;
        }
        // set value and clear allowableValues
        puzzle[sq] = bm;
        allowableValues[sq] = 0;
    }
    // propagate value to all peers, removing it from their allowable values
    uint16_t tbm = ~bm;
    for (uint8_t p = 0 ; p < numPeers ; p++)
    {
        allowableValues[peers[sq][p]] &= tbm;
    }
    return true;
}

/**
 * @brief solves for cells with a single available value, then for units
 * with only one occurance of a particular value
 *
 */
 void Sudoku::solveOnes(void)
 {
    solveOnesCount++;
    bool solvedSome = true; // set to true to allow one iteration
    while (solvedSome == true)
    { // we don't want to keep doing this if we are not finding solutions
        while (solvedSome == true)
        {    
            solvedSome = false; // set to false.  will be set to true if a value is set
            // find squares with only one available value
            for(uint8_t sq = 0 ; sq < 81 ; sq++) {
                if (countBits(allowableValues[sq]) == 1)
                {                                                        // if cell has only one available value
                    solvedSome = true;                                          // set flag to repeat loop
                    setValue(sq, bitMask[singleBitSet(allowableValues[sq])]);   // set the value
                }
            }
        }
        if (isPuzzleSolved() == true) // if solved, return true
            return;
        // now look through all units for a value that has only one occurance
        uint8_t bitCount;
        uint8_t goodSquare;
        for (uint8_t b = 0 ; b < 9 ; b++) 
        { // loop through all digits
            for (uint8_t ul = 0 ; ul < numUnitList ; ul++)
            { // loop through all unitlists
                bitCount = 0;
                goodSquare = 0;
                for (uint8_t sq = 0 ; sq < numInUnits ; sq++)
                {                                                   // loops through all RowCols in each unit
                    if((allowableValues[unitlist[ul][sq]] & bitMask[b]) != 0) {// add up number of times bit it set
                        bitCount++;
                        goodSquare = sq;
                    }
                    if (bitCount > 1)
                    {
                        break;
                    }
                }
                if (bitCount == 1) {
                    if ((allowableValues[unitlist[ul][goodSquare]] & bitMask[b]) != 0)
                    {                                // find where the bit was set
                        setValue(unitlist[ul][goodSquare], bitMask[b]); // and set the value
                        solvedSome = true;           // flag to repeat loop
                    }
                }
            }
        }
    }
}

    
// /**
//  * @brief determine if a puzzle is solved.  each unit should have all possible values
//  *
//  * @return true
//  * @return false
//  */
bool Sudoku::isPuzzleSolved(void)
{
    isPuzzleSolvedCount++;
    // a puzzle is solved if each unit in unitlist contains values of 1-9
    uint16_t bs = 0; // an accumulator for the bits set
    
    for (int8_t ul = 0 ; ul < 27 ; ul++)
    {   // for each unit in the unitlist
        bs = 0; // clear accumulator
        for (uint8_t sq = 0 ; sq < 9 ; sq++)
        {                                 // for each cell in the unit
            bs |= puzzle[unitlist[ul][sq]]; // or its set bit
        }
        if (bs != ALL_SET) // if all bits are not set, return false
            return false;
    }
   return true; // if we get here, all bits were set in all units
}

/**
 * @brief removes a potential guess because it was found to be not allowable
 *
 * @param rc RowCol of guess
 * @param b Value of guess
 * @return true if successful
 * @return false if the allowableValue element does not permit that bit to be guessed (never happens)
 */
bool Sudoku::removeGuess(SQUARE sq, BITMASK b)
{
    removeGuessCount++;
    if ((allowableValues[sq] & b) == 0) // if guess is not allowable, return value
        return false;
    else
    {
        allowableValues[sq] &= ~b; // clear the bit for the value that was guessed
         return true;
    }
}

/**
 * @brief determines if guesses remain in the puzzle
 *
 * @return bool true if yes, false if no
 */
bool Sudoku::guessesRemain(void)
{
    guessesRemainCount++;
    for(uint8_t sq = 0 ; sq < 81 ; sq++) 
    {
        if (countBits(allowableValues[sq])>= 1)
            return true;
    }
    return false;
}

/**
 * @brief returns a random guess, not counting available values. Used for benchmarking and random puzzle generation
 *
 * @return Guess the guess that was made, includes row, col, value, and puzzle state
 */
Guess Sudoku::getGuessRandom()
{
    // // guess is returned as square,value in an array of bits
    // // select random vector
    // bool squareIsEmpty = false;
    // RowCol square;
    // while (squareIsEmpty == false) {
    //     square =RowCol(rand08(generator), rand08(generator));
    //     if(allowableValues[square.row][square.col].count() != 0)
    //         squareIsEmpty = true;
    // }
    // // select random bit
    // vector<uint8_t> vBits;
    // for (uint8_t b = 0 ; b < 9 ; b++) 
    // {
    //     if (allowableValues[square.row][square.col].test(b) == true)
    //     {
    //         vBits.push_back(b);
    //     }
    // }
    // // pick random bit
    // if(vBits.size() == 0) printf("Exception coming\n");
    // uint8_t t = vBits[rand() % vBits.size()];
    // return Guess(square, bitMask[t], puzzle, allowableValues);
    return Guess();
}

/**
 * @brief returns a new guess
 *
 * @return Guess the guess that was made, includes row, col, value, and puzzle state
 */
Guess Sudoku::getGuess()
{ 
    getGuessCount++;
    // guess is returned as square,value in an array of bits
    uint8_t minCount = 9;
    // iterate through squares and get lowest count > 1
    uint8_t len;
    for(uint8_t sq = 0 ; sq < 81 ; sq++) {
        len = countBits(allowableValues[sq]);
        if (len > 1)
        {
            if (len < minCount)
            {
                minCount = len;
            }
        }
    }
    if(minCount == 9) {// squares have only one guess left
        for(uint8_t sq = 0 ; sq < 81 ; sq++) {
            if (countBits(allowableValues[sq]) == 1)
            {
                //printAllowableValues();
                return Guess(sq, allowableValues[sq], puzzle, allowableValues);
            }
    }       
    } 
    // now that we have minCount, find all cells with that count
    // must be a vector as we don't know the size
    vector<SQUARE> subset;
   for(uint8_t sq = 0 ; sq < 81 ; sq++) {
        if (countBits(allowableValues[sq]) == minCount)
        {
            subset.push_back(sq);
        }
    }
    // select random vector
    SQUARE square = subset[rand01M(generator) % subset.size()];
    // select random bit
    vector<uint8_t> vBits;
    for (uint8_t b = 0 ; b < 9 ; b++) 
    {
        if ((allowableValues[square] & bitMask[b] ) != 0)
        {
            vBits.push_back(b);
        }
    }
    // pick random bit
    uint8_t t = vBits[rand01M(generator) % vBits.size()];
    return Guess(square, bitMask[t], puzzle, allowableValues);

}

/**
 * @brief remove a guess from the list, restore puzzle state, and remove guess from allowableValues
 *
 * @return bool false if stack is empty, true otherwise
 */
bool Sudoku::popGuess()
{
    popGuessCount++;
    if (guessNumber == 0)
        return false;
    guessNumber--;
    Guess lastGuess;
    lastGuess = guessList[guessNumber];
    memcpy(puzzle,lastGuess.puzzle,sizeof(SUDOKUTYPE));
    memcpy(allowableValues,lastGuess.allowableValues,sizeof(SUDOKUTYPE));    
    removeGuess(lastGuess.square, lastGuess.guess);
    return true;
}

/**
 * @brief adds a guess to the guess list
 *
 * @param guess Guess class representing the guess, includes puzzle state
 */
void Sudoku::pushGuess(const Guess guess)
{
    pushGuessCount++;
    guessList[guessNumber] = guess;
    guessNumber++;
}

/**
 * @brief prints out a guess list
 *
 */
void Sudoku::printGuessList()
{
    if (guessNumber == 0)
        cout << "Empty";
    else
    {
        for (uint8_t i = 0; i < guessNumber; i++)
        {
            cout  << squareToText(guessList[i].square) << ":" << guessList[i].guess << " ";
        }
    }
    cout << "                                                       \r"
         << flush;
}

/**
 * @brief main routine for solving a puzzle.
 *
 * @return bool true if puzzle solved, false otherwise
 */
bool Sudoku::solvePuzzle()
{
    guessNumber=0;
    solveOnes();
    if (isPuzzleSolved())
        return true;
    else
    {
        startGuessing();
    }
    return isPuzzleSolved();
}

/**
 * @brief implements guessing loop
 *
 * @return bool returns if puzle was solved
 */
bool Sudoku::startGuessing()
{   
    startGuessingCount++;
    guessNumber = 0; // clears the guess list
    while (!isPuzzleSolved())
    { // while puzzle is not solved
        while (guessesRemain())
        {                                // while there are guesses
            Guess g = getGuess();        // make a guess
            pushGuess(g);                // store it on the guess list
            setValue(g.square, g.guess); // set the value
            solveOnes();                 // solve for unique answers or unique in set
            if (isPuzzleSolved() == false && guessesRemain() == false)
            {               // if we are out of guesses
                popGuess(); // remove last guess
            }
        }
        // after removing a guess, if no guesses remain, we must remove another guess.  this
        // propagates back up the binary tree for searching
        if (isPuzzleSolved() == false)
        {
            if (popGuess() == false)
            {
                return false;
            }
        }
    }
    return isPuzzleSolved();
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat="
void Sudoku::printCounts() {
    setlocale(LC_ALL,"");
    printf("\nSudoku counts - number of times a function was called since class creation\n");
    printf("clearPuzzle         %'lu\n",clearPuzzleCount);
    printf("setPuzzle           %'lu\n",setPuzzleCount);
    printf("setValue            %'lu\n",setValueCount);
    printf("setValueRC          %'lu\n",setValueRCCount);
    printf("solveOnes           %'lu\n",solveOnesCount);
    printf("isPuzzleSolved      %'lu\n",isPuzzleSolvedCount);
    printf("startGuessingCount  %'lu\n",startGuessingCount);
    printf("removeGuess         %'lu\n",removeGuessCount);
    printf("guessesRemain       %'lu\n",guessesRemainCount);
    printf("getGuess            %'lu\n",getGuessCount);
    printf("popGuess            %'lu\n",popGuessCount);
    printf("pushGuess           %'lu\n",pushGuessCount);
    printf("countBitsCount      %'lu\n",countBitsCount);
    printf("singleBitSet        %'lu\n",singleBitSetCount);
}
#pragma GCC diagnostic pop


uint8_t Sudoku::countBits(uint16_t bs) {
    countBitsCount++;
    unsigned int c; // c accumulates the total bits set in v
    // option 1, for at most 14-bit values in v:
    c = (bs * 0x200040008001ULL & 0x111111111111111ULL) % 0xf;
    return c;
    // strip one set bit per iteration
    // while only count until the remaining bits are zero
    // uint8_t result=0;
    // while (bs != 0)
    // {
    //     bs &= bs-1;
    //     result++;
    // }
    // return result;


    // for (uint8_t b = 0 ; b < 9 ; b++) 
    // {
    //     if (bs & bitMask[b])
    //         result++;
    // }
    // return result;
}

/**
 * @brief called after we determine only one bit is set, and returns the set bit
 *
 * @param bs a 16-bit value
 * @return uint8_t which bit is 
 */
uint8_t Sudoku::singleBitSet(uint16_t bs)
{
    singleBitSetCount++;

    // strip one set bit per iteration
    // while only count until the remaining bits are zero
    // uint8_t result = 0;
    // while (bs != 0)
    // {
    //     bs >>= 1;
    //     result++;
    // }
    // return result-1;

    for (uint8_t b = 0 ; b < 9 ; b++) 
    {
        if (bs & bitMask[b])
            return b;
    }
    return 10;


}