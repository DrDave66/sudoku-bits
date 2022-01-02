#include "SudokuTypes.h"
	const SQUARE peers[81][20] = {
/*A1*/ { 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,18,19,20,27,36,45,54,63,72},
/*A2*/ { 0, 2, 3, 4, 5, 6, 7, 8, 9,10,11,18,19,20,28,37,46,55,64,73},
/*A3*/ { 0, 1, 3, 4, 5, 6, 7, 8, 9,10,11,18,19,20,29,38,47,56,65,74},
/*A4*/ { 0, 1, 2, 4, 5, 6, 7, 8,12,13,14,21,22,23,30,39,48,57,66,75},
/*A5*/ { 0, 1, 2, 3, 5, 6, 7, 8,12,13,14,21,22,23,31,40,49,58,67,76},
/*A6*/ { 0, 1, 2, 3, 4, 6, 7, 8,12,13,14,21,22,23,32,41,50,59,68,77},
/*A7*/ { 0, 1, 2, 3, 4, 5, 7, 8,15,16,17,24,25,26,33,42,51,60,69,78},
/*A8*/ { 0, 1, 2, 3, 4, 5, 6, 8,15,16,17,24,25,26,34,43,52,61,70,79},
/*A9*/ { 0, 1, 2, 3, 4, 5, 6, 7,15,16,17,24,25,26,35,44,53,62,71,80},  
/*B1*/ { 0, 1, 2,10,11,12,13,14,15,16,17,18,19,20,27,36,45,54,63,72},
/*B2*/ { 0, 1, 2, 9,11,12,13,14,15,16,17,18,19,20,28,37,46,55,64,73},
/*B3*/ { 0, 1, 2, 9,10,12,13,14,15,16,17,18,19,20,29,38,47,56,65,74},
/*B4*/ { 3, 4, 5, 9,10,11,13,14,15,16,17,21,22,23,30,39,48,57,66,75},
/*B5*/ { 3, 4, 5, 9,10,11,12,14,15,16,17,21,22,23,31,40,49,58,67,76},
/*B6*/ { 3, 4, 5, 9,10,11,12,13,15,16,17,21,22,23,32,41,50,59,68,77},
/*B7*/ { 6, 7, 8, 9,10,11,12,13,14,16,17,24,25,26,33,42,51,60,69,78},
/*B8*/ { 6, 7, 8, 9,10,11,12,13,14,15,17,24,25,26,34,43,52,61,70,79},
/*B9*/ { 6, 7, 8, 9,10,11,12,13,14,15,16,24,25,26,35,44,53,62,71,80},
/*C1*/ { 0, 1, 2, 9,10,11,19,20,21,22,23,24,25,26,27,36,45,54,63,72},
/*C2*/ { 0, 1, 2, 9,10,11,18,20,21,22,23,24,25,26,28,37,46,55,64,73},
/*C3*/ { 0, 1, 2, 9,10,11,18,19,21,22,23,24,25,26,29,38,47,56,65,74},
/*C4*/ { 3, 4, 5,12,13,14,18,19,20,22,23,24,25,26,30,39,48,57,66,75},
/*C5*/ { 3, 4, 5,12,13,14,18,19,20,21,23,24,25,26,31,40,49,58,67,76},
/*C6*/ { 3, 4, 5,12,13,14,18,19,20,21,22,24,25,26,32,41,50,59,68,77},
/*C7*/ { 6, 7, 8,15,16,17,18,19,20,21,22,23,25,26,33,42,51,60,69,78},
/*C8*/ { 6, 7, 8,15,16,17,18,19,20,21,22,23,24,26,34,43,52,61,70,79},
/*C9*/ { 6, 7, 8,15,16,17,18,19,20,21,22,23,24,25,35,44,53,62,71,80},
/*D1*/ { 0, 9,18,28,29,30,31,32,33,34,35,36,37,38,45,46,47,54,63,72},
/*D2*/ { 1,10,19,27,29,30,31,32,33,34,35,36,37,38,45,46,47,55,64,73},
/*D3*/ { 2,11,20,27,28,30,31,32,33,34,35,36,37,38,45,46,47,56,65,74},
/*D4*/ { 3,12,21,27,28,29,31,32,33,34,35,39,40,41,48,49,50,57,66,75},
/*D5*/ { 4,13,22,27,28,29,30,32,33,34,35,39,40,41,48,49,50,58,67,76},
/*D6*/ { 5,14,23,27,28,29,30,31,33,34,35,39,40,41,48,49,50,59,68,77},
/*D7*/ { 6,15,24,27,28,29,30,31,32,34,35,42,43,44,51,52,53,60,69,78},
/*D8*/ { 7,16,25,27,28,29,30,31,32,33,35,42,43,44,51,52,53,61,70,79},
/*D9*/ { 8,17,26,27,28,29,30,31,32,33,34,42,43,44,51,52,53,62,71,80},
/*E1*/ { 0, 9,18,27,28,29,37,38,39,40,41,42,43,44,45,46,47,54,63,72},
/*E2*/ { 1,10,19,27,28,29,36,38,39,40,41,42,43,44,45,46,47,55,64,73},
/*E3*/ { 2,11,20,27,28,29,36,37,39,40,41,42,43,44,45,46,47,56,65,74},
/*E4*/ { 3,12,21,30,31,32,36,37,38,40,41,42,43,44,48,49,50,57,66,75},
/*E5*/ { 4,13,22,30,31,32,36,37,38,39,41,42,43,44,48,49,50,58,67,76},
/*E6*/ { 5,14,23,30,31,32,36,37,38,39,40,42,43,44,48,49,50,59,68,77},
/*E7*/ { 6,15,24,33,34,35,36,37,38,39,40,41,43,44,51,52,53,60,69,78},
/*E8*/ { 7,16,25,33,34,35,36,37,38,39,40,41,42,44,51,52,53,61,70,79},
/*E9*/ { 8,17,26,33,34,35,36,37,38,39,40,41,42,43,51,52,53,62,71,80},
/*F1*/ { 0, 9,18,27,28,29,36,37,38,46,47,48,49,50,51,52,53,54,63,72},
/*F2*/ { 1,10,19,27,28,29,36,37,38,45,47,48,49,50,51,52,53,55,64,73},
/*F3*/ { 2,11,20,27,28,29,36,37,38,45,46,48,49,50,51,52,53,56,65,74},
/*F4*/ { 3,12,21,30,31,32,39,40,41,45,46,47,49,50,51,52,53,57,66,75},
/*F5*/ { 4,13,22,30,31,32,39,40,41,45,46,47,48,50,51,52,53,58,67,76},
/*F6*/ { 5,14,23,30,31,32,39,40,41,45,46,47,48,49,51,52,53,59,68,77},
/*F7*/ { 6,15,24,33,34,35,42,43,44,45,46,47,48,49,50,52,53,60,69,78},
/*F8*/ { 7,16,25,33,34,35,42,43,44,45,46,47,48,49,50,51,53,61,70,79},
/*F9*/ { 8,17,26,33,34,35,42,43,44,45,46,47,48,49,50,51,52,62,71,80},
/*G1*/ { 0, 9,18,27,36,45,55,56,57,58,59,60,61,62,63,64,65,72,73,74},
/*G2*/ { 1,10,19,28,37,46,54,56,57,58,59,60,61,62,63,64,65,72,73,74},
/*G3*/ { 2,11,20,29,38,47,54,55,57,58,59,60,61,62,63,64,65,72,73,74},
/*G4*/ { 3,12,21,30,39,48,54,55,56,58,59,60,61,62,66,67,68,75,76,77},
/*G5*/ { 4,13,22,31,40,49,54,55,56,57,59,60,61,62,66,67,68,75,76,77},
/*G6*/ { 5,14,23,32,41,50,54,55,56,57,58,60,61,62,66,67,68,75,76,77},
/*G7*/ { 6,15,24,33,42,51,54,55,56,57,58,59,61,62,69,70,71,78,79,80},
/*G8*/ { 7,16,25,34,43,52,54,55,56,57,58,59,60,62,69,70,71,78,79,80},
/*G9*/ { 8,17,26,35,44,53,54,55,56,57,58,59,60,61,69,70,71,78,79,80},
/*H1*/ { 0, 9,18,27,36,45,54,55,56,64,65,66,67,68,69,70,71,72,73,74},
/*H2*/ { 1,10,19,28,37,46,54,55,56,63,65,66,67,68,69,70,71,72,73,74},
/*H3*/ { 2,11,20,29,38,47,54,55,56,63,64,66,67,68,69,70,71,72,73,74},
/*H4*/ { 3,12,21,30,39,48,57,58,59,63,64,65,67,68,69,70,71,75,76,77},
/*H5*/ { 4,13,22,31,40,49,57,58,59,63,64,65,66,68,69,70,71,75,76,77},
/*H6*/ { 5,14,23,32,41,50,57,58,59,63,64,65,66,67,69,70,71,75,76,77},
/*H7*/ { 6,15,24,33,42,51,60,61,62,63,64,65,66,67,68,70,71,78,79,80},
/*H8*/ { 7,16,25,34,43,52,60,61,62,63,64,65,66,67,68,69,71,78,79,80},
/*H9*/ { 8,17,26,35,44,53,60,61,62,63,64,65,66,67,68,69,70,78,79,80},
/*I1*/ { 0, 9,18,27,36,45,54,55,56,63,64,65,73,74,75,76,77,78,79,80},
/*I2*/ { 1,10,19,28,37,46,54,55,56,63,64,65,72,74,75,76,77,78,79,80},
/*I3*/ { 2,11,20,29,38,47,54,55,56,63,64,65,72,73,75,76,77,78,79,80},
/*I4*/ { 3,12,21,30,39,48,57,58,59,66,67,68,72,73,74,76,77,78,79,80},
/*I5*/ { 4,13,22,31,40,49,57,58,59,66,67,68,72,73,74,75,77,78,79,80},
/*I6*/ { 5,14,23,32,41,50,57,58,59,66,67,68,72,73,74,75,76,78,79,80},
/*I7*/ { 6,15,24,33,42,51,60,61,62,69,70,71,72,73,74,75,76,77,79,80},
/*I8*/ { 7,16,25,34,43,52,60,61,62,69,70,71,72,73,74,75,76,77,78,80},
/*I9*/ { 8,17,26,35,44,53,60,61,62,69,70,71,72,73,74,75,76,77,78,79}
	};


	const SQUARE units[81][3][9] = {
	/*A1*/ {
		{ 0,  9, 18, 27, 36, 45, 54, 63, 72 },
		{ 0,  1,  2,  3,  4,  5,  6,  7,  8 },
		{ 0,  1,  2,  9, 10, 11, 18, 19, 20 },
		},
	/*A2*/ {
		{ 1, 10, 19, 28, 37, 46, 55, 64, 73 },
		{ 0,  1,  2,  3,  4,  5,  6,  7,  8 },
		{ 0,  1,  2,  9, 10, 11, 18, 19, 20 },
		},
	/*A3*/ {
		{ 2, 11, 20, 29, 38, 47, 56, 65, 74 },
		{ 0,  1,  2,  3,  4,  5,  6,  7,  8 },
		{ 0,  1,  2,  9, 10, 11, 18, 19, 20 },
		},
	/*A4*/ {
		{ 3, 12, 21, 30, 39, 48, 57, 66, 75 },
		{ 0,  1,  2,  3,  4,  5,  6,  7,  8 },
		{ 3,  4,  5, 12, 13, 14, 21, 22, 23 },
		},
	/*A5*/ {
		{ 4, 13, 22, 31, 40, 49, 58, 67, 76 },
		{ 0,  1,  2,  3,  4,  5,  6,  7,  8 },
		{ 3,  4,  5, 12, 13, 14, 21, 22, 23 },
		},
	/*A6*/ {
		{ 5, 14, 23, 32, 41, 50, 59, 68, 77 },
		{ 0,  1,  2,  3,  4,  5,  6,  7,  8 },
		{ 3,  4,  5, 12, 13, 14, 21, 22, 23 },
		},
	/*A7*/ {
		{ 6, 15, 24, 33, 42, 51, 60, 69, 78 },
		{ 0,  1,  2,  3,  4,  5,  6,  7,  8 },
		{ 6,  7,  8, 15, 16, 17, 24, 25, 26 },
		},
	/*A8*/ {
		{ 7, 16, 25, 34, 43, 52, 61, 70, 79 },
		{ 0,  1,  2,  3,  4,  5,  6,  7,  8 },
		{ 6,  7,  8, 15, 16, 17, 24, 25, 26 },
		},
	/*A9*/ {
		{ 8, 17, 26, 35, 44, 53, 62, 71, 80 },
		{ 0,  1,  2,  3,  4,  5,  6,  7,  8 },
		{ 6,  7,  8, 15, 16, 17, 24, 25, 26 },
		},
	/*B1*/ {
		{ 0,  9, 18, 27, 36, 45, 54, 63, 72 },
		{ 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 0,  1,  2,  9, 10, 11, 18, 19, 20 },
		},
	/*B2*/ {
		{ 1, 10, 19, 28, 37, 46, 55, 64, 73 },
		{ 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 0,  1,  2,  9, 10, 11, 18, 19, 20 },
		},
	/*B3*/ {
		{ 2, 11, 20, 29, 38, 47, 56, 65, 74 },
		{ 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 0,  1,  2,  9, 10, 11, 18, 19, 20 },
		},
	/*B4*/ {
		{ 3, 12, 21, 30, 39, 48, 57, 66, 75 },
		{ 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 3,  4,  5, 12, 13, 14, 21, 22, 23 },
		},
	/*B5*/ {
		{ 4, 13, 22, 31, 40, 49, 58, 67, 76 },
		{ 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 3,  4,  5, 12, 13, 14, 21, 22, 23 },
		},
	/*B6*/ {
		{ 5, 14, 23, 32, 41, 50, 59, 68, 77 },
		{ 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 3,  4,  5, 12, 13, 14, 21, 22, 23 },
		},
	/*B7*/ {
		{ 6, 15, 24, 33, 42, 51, 60, 69, 78 },
		{ 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 6,  7,  8, 15, 16, 17, 24, 25, 26 },
		},
	/*B8*/ {
		{ 7, 16, 25, 34, 43, 52, 61, 70, 79 },
		{ 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 6,  7,  8, 15, 16, 17, 24, 25, 26 },
		},
	/*B9*/ {
		{ 8, 17, 26, 35, 44, 53, 62, 71, 80 },
		{ 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 6,  7,  8, 15, 16, 17, 24, 25, 26 },
		},
	/*C1*/ {
		{ 0,  9, 18, 27, 36, 45, 54, 63, 72 },
		{18, 19, 20, 21, 22, 23, 24, 25, 26 },
		{ 0,  1,  2,  9, 10, 11, 18, 19, 20 },
		},
	/*C2*/ {
		{ 1, 10, 19, 28, 37, 46, 55, 64, 73 },
		{18, 19, 20, 21, 22, 23, 24, 25, 26 },
		{ 0,  1,  2,  9, 10, 11, 18, 19, 20 },
		},
	/*C3*/ {
		{ 2, 11, 20, 29, 38, 47, 56, 65, 74 },
		{18, 19, 20, 21, 22, 23, 24, 25, 26 },
		{ 0,  1,  2,  9, 10, 11, 18, 19, 20 },
		},
	/*C4*/ {
		{ 3, 12, 21, 30, 39, 48, 57, 66, 75 },
		{18, 19, 20, 21, 22, 23, 24, 25, 26 },
		{ 3,  4,  5, 12, 13, 14, 21, 22, 23 },
		},
	/*C5*/ {
		{ 4, 13, 22, 31, 40, 49, 58, 67, 76 },
		{18, 19, 20, 21, 22, 23, 24, 25, 26 },
		{ 3,  4,  5, 12, 13, 14, 21, 22, 23 },
		},
	/*C6*/ {
		{ 5, 14, 23, 32, 41, 50, 59, 68, 77 },
		{18, 19, 20, 21, 22, 23, 24, 25, 26 },
		{ 3,  4,  5, 12, 13, 14, 21, 22, 23 },
		},
	/*C7*/ {
		{ 6, 15, 24, 33, 42, 51, 60, 69, 78 },
		{18, 19, 20, 21, 22, 23, 24, 25, 26 },
		{ 6,  7,  8, 15, 16, 17, 24, 25, 26 },
		},
	/*C8*/ {
		{ 7, 16, 25, 34, 43, 52, 61, 70, 79 },
		{18, 19, 20, 21, 22, 23, 24, 25, 26 },
		{ 6,  7,  8, 15, 16, 17, 24, 25, 26 },
		},
	/*C9*/ {
		{ 8, 17, 26, 35, 44, 53, 62, 71, 80 },
		{18, 19, 20, 21, 22, 23, 24, 25, 26 },
		{ 6,  7,  8, 15, 16, 17, 24, 25, 26 },
		},
	/*D1*/ {
		{ 0,  9, 18, 27, 36, 45, 54, 63, 72 },
		{27, 28, 29, 30, 31, 32, 33, 34, 35 },
		{27, 28, 29, 36, 37, 38, 45, 46, 47 },
		},
	/*D2*/ {
		{ 1, 10, 19, 28, 37, 46, 55, 64, 73 },
		{27, 28, 29, 30, 31, 32, 33, 34, 35 },
		{27, 28, 29, 36, 37, 38, 45, 46, 47 },
		},
	/*D3*/ {
		{ 2, 11, 20, 29, 38, 47, 56, 65, 74 },
		{27, 28, 29, 30, 31, 32, 33, 34, 35 },
		{27, 28, 29, 36, 37, 38, 45, 46, 47 },
		},
	/*D4*/ {
		{ 3, 12, 21, 30, 39, 48, 57, 66, 75 },
		{27, 28, 29, 30, 31, 32, 33, 34, 35 },
		{30, 31, 32, 39, 40, 41, 48, 49, 50 },
		},
	/*D5*/ {
		{ 4, 13, 22, 31, 40, 49, 58, 67, 76 },
		{27, 28, 29, 30, 31, 32, 33, 34, 35 },
		{30, 31, 32, 39, 40, 41, 48, 49, 50 },
		},
	/*D6*/ {
		{ 5, 14, 23, 32, 41, 50, 59, 68, 77 },
		{27, 28, 29, 30, 31, 32, 33, 34, 35 },
		{30, 31, 32, 39, 40, 41, 48, 49, 50 },
		},
	/*D7*/ {
		{ 6, 15, 24, 33, 42, 51, 60, 69, 78 },
		{27, 28, 29, 30, 31, 32, 33, 34, 35 },
		{33, 34, 35, 42, 43, 44, 51, 52, 53 },
		},
	/*D8*/ {
		{ 7, 16, 25, 34, 43, 52, 61, 70, 79 },
		{27, 28, 29, 30, 31, 32, 33, 34, 35 },
		{33, 34, 35, 42, 43, 44, 51, 52, 53 },
		},
	/*D9*/ {
		{ 8, 17, 26, 35, 44, 53, 62, 71, 80 },
		{27, 28, 29, 30, 31, 32, 33, 34, 35 },
		{33, 34, 35, 42, 43, 44, 51, 52, 53 },
		},
	/*E1*/ {
		{ 0,  9, 18, 27, 36, 45, 54, 63, 72 },
		{36, 37, 38, 39, 40, 41, 42, 43, 44 },
		{27, 28, 29, 36, 37, 38, 45, 46, 47 },
		},
	/*E2*/ {
		{ 1, 10, 19, 28, 37, 46, 55, 64, 73 },
		{36, 37, 38, 39, 40, 41, 42, 43, 44 },
		{27, 28, 29, 36, 37, 38, 45, 46, 47 },
		},
	/*E3*/ {
		{ 2, 11, 20, 29, 38, 47, 56, 65, 74 },
		{36, 37, 38, 39, 40, 41, 42, 43, 44 },
		{27, 28, 29, 36, 37, 38, 45, 46, 47 },
		},
	/*E4*/ {
		{ 3, 12, 21, 30, 39, 48, 57, 66, 75 },
		{36, 37, 38, 39, 40, 41, 42, 43, 44 },
		{30, 31, 32, 39, 40, 41, 48, 49, 50 },
		},
	/*E5*/ {
		{ 4, 13, 22, 31, 40, 49, 58, 67, 76 },
		{36, 37, 38, 39, 40, 41, 42, 43, 44 },
		{30, 31, 32, 39, 40, 41, 48, 49, 50 },
		},
	/*E6*/ {
		{ 5, 14, 23, 32, 41, 50, 59, 68, 77 },
		{36, 37, 38, 39, 40, 41, 42, 43, 44 },
		{30, 31, 32, 39, 40, 41, 48, 49, 50 },
		},
	/*E7*/ {
		{ 6, 15, 24, 33, 42, 51, 60, 69, 78 },
		{36, 37, 38, 39, 40, 41, 42, 43, 44 },
		{33, 34, 35, 42, 43, 44, 51, 52, 53 },
		},
	/*E8*/ {
		{ 7, 16, 25, 34, 43, 52, 61, 70, 79 },
		{36, 37, 38, 39, 40, 41, 42, 43, 44 },
		{33, 34, 35, 42, 43, 44, 51, 52, 53 },
		},
	/*E9*/ {
		{ 8, 17, 26, 35, 44, 53, 62, 71, 80 },
		{36, 37, 38, 39, 40, 41, 42, 43, 44 },
		{33, 34, 35, 42, 43, 44, 51, 52, 53 },
		},
	/*F1*/ {
		{ 0,  9, 18, 27, 36, 45, 54, 63, 72 },
		{45, 46, 47, 48, 49, 50, 51, 52, 53 },
		{27, 28, 29, 36, 37, 38, 45, 46, 47 },
		},
	/*F2*/ {
		{ 1, 10, 19, 28, 37, 46, 55, 64, 73 },
		{45, 46, 47, 48, 49, 50, 51, 52, 53 },
		{27, 28, 29, 36, 37, 38, 45, 46, 47 },
		},
	/*F3*/ {
		{ 2, 11, 20, 29, 38, 47, 56, 65, 74 },
		{45, 46, 47, 48, 49, 50, 51, 52, 53 },
		{27, 28, 29, 36, 37, 38, 45, 46, 47 },
		},
	/*F4*/ {
		{ 3, 12, 21, 30, 39, 48, 57, 66, 75 },
		{45, 46, 47, 48, 49, 50, 51, 52, 53 },
		{30, 31, 32, 39, 40, 41, 48, 49, 50 },
		},
	/*F5*/ {
		{ 4, 13, 22, 31, 40, 49, 58, 67, 76 },
		{45, 46, 47, 48, 49, 50, 51, 52, 53 },
		{30, 31, 32, 39, 40, 41, 48, 49, 50 },
		},
	/*F6*/ {
		{ 5, 14, 23, 32, 41, 50, 59, 68, 77 },
		{45, 46, 47, 48, 49, 50, 51, 52, 53 },
		{30, 31, 32, 39, 40, 41, 48, 49, 50 },
		},
	/*F7*/ {
		{ 6, 15, 24, 33, 42, 51, 60, 69, 78 },
		{45, 46, 47, 48, 49, 50, 51, 52, 53 },
		{33, 34, 35, 42, 43, 44, 51, 52, 53 },
		},
	/*F8*/ {
		{ 7, 16, 25, 34, 43, 52, 61, 70, 79 },
		{45, 46, 47, 48, 49, 50, 51, 52, 53 },
		{33, 34, 35, 42, 43, 44, 51, 52, 53 },
		},
	/*F9*/ {
		{ 8, 17, 26, 35, 44, 53, 62, 71, 80 },
		{45, 46, 47, 48, 49, 50, 51, 52, 53 },
		{33, 34, 35, 42, 43, 44, 51, 52, 53 },
		},
	/*G1*/ {
		{ 0,  9, 18, 27, 36, 45, 54, 63, 72 },
		{54, 55, 56, 57, 58, 59, 60, 61, 62 },
		{54, 55, 56, 63, 64, 65, 72, 73, 74 },
		},
	/*G2*/ {
		{ 1, 10, 19, 28, 37, 46, 55, 64, 73 },
		{54, 55, 56, 57, 58, 59, 60, 61, 62 },
		{54, 55, 56, 63, 64, 65, 72, 73, 74 },
		},
	/*G3*/ {
		{ 2, 11, 20, 29, 38, 47, 56, 65, 74 },
		{54, 55, 56, 57, 58, 59, 60, 61, 62 },
		{54, 55, 56, 63, 64, 65, 72, 73, 74 },
		},
	/*G4*/ {
		{ 3, 12, 21, 30, 39, 48, 57, 66, 75 },
		{54, 55, 56, 57, 58, 59, 60, 61, 62 },
		{57, 58, 59, 66, 67, 68, 75, 76, 77 },
		},
	/*G5*/ {
		{ 4, 13, 22, 31, 40, 49, 58, 67, 76 },
		{54, 55, 56, 57, 58, 59, 60, 61, 62 },
		{57, 58, 59, 66, 67, 68, 75, 76, 77 },
		},
	/*G6*/ {
		{ 5, 14, 23, 32, 41, 50, 59, 68, 77 },
		{54, 55, 56, 57, 58, 59, 60, 61, 62 },
		{57, 58, 59, 66, 67, 68, 75, 76, 77 },
		},
	/*G7*/ {
		{ 6, 15, 24, 33, 42, 51, 60, 69, 78 },
		{54, 55, 56, 57, 58, 59, 60, 61, 62 },
		{60, 61, 62, 69, 70, 71, 78, 79, 80 },
		},
	/*G8*/ {
		{ 7, 16, 25, 34, 43, 52, 61, 70, 79 },
		{54, 55, 56, 57, 58, 59, 60, 61, 62 },
		{60, 61, 62, 69, 70, 71, 78, 79, 80 },
		},
	/*G9*/ {
		{ 8, 17, 26, 35, 44, 53, 62, 71, 80 },
		{54, 55, 56, 57, 58, 59, 60, 61, 62 },
		{60, 61, 62, 69, 70, 71, 78, 79, 80 },
		},
	/*H1*/ {
		{ 0,  9, 18, 27, 36, 45, 54, 63, 72 },
		{63, 64, 65, 66, 67, 68, 69, 70, 71 },
		{54, 55, 56, 63, 64, 65, 72, 73, 74 },
		},
	/*H2*/ {
		{ 1, 10, 19, 28, 37, 46, 55, 64, 73 },
		{63, 64, 65, 66, 67, 68, 69, 70, 71 },
		{54, 55, 56, 63, 64, 65, 72, 73, 74 },
		},
	/*H3*/ {
		{ 2, 11, 20, 29, 38, 47, 56, 65, 74 },
		{63, 64, 65, 66, 67, 68, 69, 70, 71 },
		{54, 55, 56, 63, 64, 65, 72, 73, 74 },
		},
	/*H4*/ {
		{ 3, 12, 21, 30, 39, 48, 57, 66, 75 },
		{63, 64, 65, 66, 67, 68, 69, 70, 71 },
		{57, 58, 59, 66, 67, 68, 75, 76, 77 },
		},
	/*H5*/ {
		{ 4, 13, 22, 31, 40, 49, 58, 67, 76 },
		{63, 64, 65, 66, 67, 68, 69, 70, 71 },
		{57, 58, 59, 66, 67, 68, 75, 76, 77 },
		},
	/*H6*/ {
		{ 5, 14, 23, 32, 41, 50, 59, 68, 77 },
		{63, 64, 65, 66, 67, 68, 69, 70, 71 },
		{57, 58, 59, 66, 67, 68, 75, 76, 77 },
		},
	/*H7*/ {
		{ 6, 15, 24, 33, 42, 51, 60, 69, 78 },
		{63, 64, 65, 66, 67, 68, 69, 70, 71 },
		{60, 61, 62, 69, 70, 71, 78, 79, 80 },
		},
	/*H8*/ {
		{ 7, 16, 25, 34, 43, 52, 61, 70, 79 },
		{63, 64, 65, 66, 67, 68, 69, 70, 71 },
		{60, 61, 62, 69, 70, 71, 78, 79, 80 },
		},
	/*H9*/ {
		{ 8, 17, 26, 35, 44, 53, 62, 71, 80 },
		{63, 64, 65, 66, 67, 68, 69, 70, 71 },
		{60, 61, 62, 69, 70, 71, 78, 79, 80 },
		},
	/*I1*/ {
		{ 0,  9, 18, 27, 36, 45, 54, 63, 72 },
		{72, 73, 74, 75, 76, 77, 78, 79, 80 },
		{54, 55, 56, 63, 64, 65, 72, 73, 74 },
		},
	/*I2*/ {
		{ 1, 10, 19, 28, 37, 46, 55, 64, 73 },
		{72, 73, 74, 75, 76, 77, 78, 79, 80 },
		{54, 55, 56, 63, 64, 65, 72, 73, 74 },
		},
	/*I3*/ {
		{ 2, 11, 20, 29, 38, 47, 56, 65, 74 },
		{72, 73, 74, 75, 76, 77, 78, 79, 80 },
		{54, 55, 56, 63, 64, 65, 72, 73, 74 },
		},
	/*I4*/ {
		{ 3, 12, 21, 30, 39, 48, 57, 66, 75 },
		{72, 73, 74, 75, 76, 77, 78, 79, 80 },
		{57, 58, 59, 66, 67, 68, 75, 76, 77 },
		},
	/*I5*/ {
		{ 4, 13, 22, 31, 40, 49, 58, 67, 76 },
		{72, 73, 74, 75, 76, 77, 78, 79, 80 },
		{57, 58, 59, 66, 67, 68, 75, 76, 77 },
		},
	/*I6*/ {
		{ 5, 14, 23, 32, 41, 50, 59, 68, 77 },
		{72, 73, 74, 75, 76, 77, 78, 79, 80 },
		{57, 58, 59, 66, 67, 68, 75, 76, 77 },
		},
	/*I7*/ {
		{ 6, 15, 24, 33, 42, 51, 60, 69, 78 },
		{72, 73, 74, 75, 76, 77, 78, 79, 80 },
		{60, 61, 62, 69, 70, 71, 78, 79, 80 },
		},
	/*I8*/ {
		{ 7, 16, 25, 34, 43, 52, 61, 70, 79 },
		{72, 73, 74, 75, 76, 77, 78, 79, 80 },
		{60, 61, 62, 69, 70, 71, 78, 79, 80 },
		},
	/*I9*/ {
		{ 8, 17, 26, 35, 44, 53, 62, 71, 80 },
		{72, 73, 74, 75, 76, 77, 78, 79, 80 },
		{60, 61, 62, 69, 70, 71, 78, 79, 80 },
		}
	};


	const SQUARE unitlist[27][9]= {
		{  0,  9, 18, 27, 36, 45, 54, 63, 72 },
		{  1, 10, 19, 28, 37, 46, 55, 64, 73 },
		{  2, 11, 20, 29, 38, 47, 56, 65, 74 },
		{  3, 12, 21, 30, 39, 48, 57, 66, 75 },
		{  4, 13, 22, 31, 40, 49, 58, 67, 76 },
		{  5, 14, 23, 32, 41, 50, 59, 68, 77 },
		{  6, 15, 24, 33, 42, 51, 60, 69, 78 },
		{  7, 16, 25, 34, 43, 52, 61, 70, 79 },
		{  8, 17, 26, 35, 44, 53, 62, 71, 80 },
		{  0,  1,  2,  3,  4,  5,  6,  7,  8 },
		{  9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 18, 19, 20, 21, 22, 23, 24, 25, 26 },
		{ 27, 28, 29, 30, 31, 32, 33, 34, 35 },
		{ 36, 37, 38, 39, 40, 41, 42, 43, 44 },
		{ 45, 46, 47, 48, 49, 50, 51, 52, 53 },
		{ 54, 55, 56, 57, 58, 59, 60, 61, 62 },
		{ 63, 64, 65, 66, 67, 68, 69, 70, 71 },
		{ 72, 73, 74, 75, 76, 77, 78, 79, 80 },
		{  0,  1,  2,  9, 10, 11, 18, 19, 20 },
		{  3,  4,  5, 12, 13, 14, 21, 22, 23 },
		{  6,  7,  8, 15, 16, 17, 24, 25, 26 },
		{ 27, 28, 29, 36, 37, 38, 45, 46, 47 },
		{ 30, 31, 32, 39, 40, 41, 48, 49, 50 },
		{ 33, 34, 35, 42, 43, 44, 51, 52, 53 },
		{ 54, 55, 56, 63, 64, 65, 72, 73, 74 },
		{ 57, 58, 59, 66, 67, 68, 75, 76, 77 },
		{ 60, 61, 62, 69, 70, 71, 78, 79, 80 },
        };
