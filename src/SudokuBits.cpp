// vcSudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <thread>
#include <chrono>
#include <iomanip>


using std::fstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::setw;
            

#include "Puzzles.h"
#include "Sudoku.h"
#include "PrecisionTimeLapse.h"
#include "SudokuTypes.h"
#include "Guess.h"
// solved with ones/peers
string grid1 =   "..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3..";
string grid3 =   "8.2.5.7.1..7.8246..1.9.....6....18325.......91843....6.....4.2..9561.3..3.8.9.6.7";
// not solved with ones/peers
string needguess=".61.2.....4.6.59..392...5.882...9..74....3......48...3..7..21...1..7....98..146.2";
string easy505 = "1..92....524.1...........7..5...81.2.........4.27...9..6...........3.945....71..6";
string grid2 =   "4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......";
string hard1 =   ".....6....59.....82....8....45........3........6..3.54...325..6..................";
string easy506 = ".43.8.25.6.............1.949....4.7....6.8....1.2....382.5.............5.34.9.71.";
string blank =   ".................................................................................";
// solved puzzles
string solved1 = "431829765276513984598467312389251647642378591157946238964785123723194856815632479";
string solved2 = "687942351591376284342158769465239178138567942279814635853791426924683517716425893";
string solved3 = "523846917961537428487219653154693782632478195798152346879324561316985274245761839";
string solved4 = "152483679697152348438976251314765892869241735275398164786524913941837526523619487";
string solved5 = "176923584524817639893654271957348162638192457412765398265489713781236945349571826";

string p1 = "....1..75....8.6..9....5...4.2...561..1.2..9..9...1.32.7.1.2.8458.67...312.3.....";
string p2 = "5.7....61...76.8...6..8...4.....3....5..4...949.6.2..814..5...6.79........5.18..2";
string p3 = "6..4....5.92.3.....4.76.23.......37..6...1.2.329.......1.....829.3...5...7451...3";
string s1 = "248916375357284619916735248432897561861523497795461832673152984584679123129348756";
string s2 = "587324961914765823362189754821593647756841239493672518148257396279436185635918472";
string s3 = "631482795792135648845769231158296374467351829329847156516973482983624517274518963";
string oo = "1.2.3.4.5.6.7.8.9................................................................";


// Loaded 100 		puzzles in 0.784945 msec, 7.849450 usec/puzzle
// Loaded 1000 		puzzles in 2.524844 msec, 2.524844 usec/puzzle
// Loaded 10000 	puzzles in 16.981709 msec, 1.698171 usec/puzzle
// Loaded 100000 	puzzles in 113.327293 msec, 1.133273 usec/puzzle
// Loaded 1000000 	puzzles in 1011.960570 msec, 1.011961 usec/puzzle
// Loaded 10000000 	puzzles in 10631.764658 msec, 1.063176 usec/puzzle

// 100P 0 ..4.83..2.51..43......9671.12.8....6.4....5..83.6.79...6.3.9.4...7...2.5.9..5.8.3
#define xSHORTMAIN
#ifdef SHORTMAIN
// uint8_t RCToNumber(RowCol& rc) {
// 	return rc.row*9 + rc.col;
// }

int main() {
	PrecisionTimeLapse ptl;
	ptl.start();
	std::this_thread::sleep_for (std::chrono::seconds(3));
	ptl.stop();
	printf("time lapse was %f\n",ptl.elapsed());
}

#else

int main()
{
	Puzzles pf("../../sudoku-puzzles/1MP.txt");
	cout << pf.getNumberOfPuzzles() << " puzzles loaded" << endl << endl << endl;
	if (pf.getNumberOfPuzzles() == 0)
		return 1;
	Sudoku s;
	PrecisionTimeLapse total;
	PrecisionTimeLapse ptl;
	uint32_t numPuzzles = pf.getNumberOfPuzzles();
	int solved = 0;
	double minTime = 100000.0;
	double maxTime = 0.0;
	double sumTime =  0.0;
	double time;
	total.start();
	bool isSolved;
	uint16_t guessed = 0;
	uint32_t onePercent = (uint32_t)(pf.getNumberOfPuzzles()/100);
	for (uint32_t i = 0; i < pf.getNumberOfPuzzles(); i++) {
		s.setPuzzle(pf.getPuzzle(i));
		ptl.start();
		isSolved = s.solvePuzzle();
		ptl.stop();
		time = ptl.elapsed();

		if (isSolved == true)
		{ 
   			solved += 1;
			if(s.guessNumber != 0) {
				guessed++;
				//puzzle 7734746 needed a guess
				//printf("puzzle %d needed a %d guesses\n",i,s.guessNumber);
				//cout << pf.getPuzzle(i) << endl;
			}
		}
		else {
			printf("Not solved puzzle %d\n",i);
			s.printPuzzle();
			s.printAllowableValues();
		}
		minTime = min(minTime, time);
        maxTime = max(maxTime, time);
		sumTime += time;
		if (i % onePercent == 0) {
			printf("%6.2f%%   \n", (double)i/(double)numPuzzles * 100);
		}
	}
	total.stop();
    cout << "Solved " << solved << " out of " << pf.getNumberOfPuzzles() << " puzzles. " << guessed << " puzzles needed guesses" << endl;
	cout << "Min time: " << minTime*1000.0 << " ms, Max time: " << maxTime*1000.0 << " ms, Average Time: " << (double)sumTime / (double)solved * 1000 << " ms, Total: " << total.elapsedString(SEC) << " sec" << endl;
	cout << endl << endl;
	s.printCounts();
	printf("\n");
}

#endif

// 10MP-Failed.txt      	Min time: 0.107397 ms, Max time: 180.694 ms, Average Time: 0.963753 ms, Total: 364.072973 sec
// 1MP old way				Min time: 0.021334 ms, Max time: 5.1635 ms, Average Time: 0.0305412 ms, Total: 66.192528 sec
// 1MP bit round 1 			Min time: 0.006958 ms, Max time: 12.3362 ms, Average Time: 0.00862062 ms, Total: 13.802928 sec
// 1MP better loops			Min time: 0.005765 ms, Max time: 6.95828 ms, Average Time: 0.00742397 ms, Total: 10.232687 sec

// 10MP						Min time: 0.003219 ms, Max time: 68.2603 ms, Average Time: 0.0180983 ms, Total: 220.961769 sec
// 10MP bit 1/5				Min time: 0.000882 ms, Max time: 49.7904 ms, Average Time: 0.00711188 ms, Total: 88.808665 sec
//							Min time: 0.000498 ms, Max time: 28.1895 ms, Average Time: 0.00597333 ms, Total: 72.157265 sec