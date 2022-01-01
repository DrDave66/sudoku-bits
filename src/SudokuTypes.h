#pragma once
#ifndef _SUDOKUTYPES
#define _SUDOKUTYPES

#include <cstdint>
#include <array>

using std::array;

// this type is used for puzzle and allowableValues
// it's in a separate header beause it used to be more than just a typedef
typedef uint16_t SUDOKUTYPE[9][9];
typedef uint16_t BITMASK;
#endif // _SUDOKUTYPES_H