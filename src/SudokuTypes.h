#pragma once
#ifndef _SUDOKUTYPES
#define _SUDOKUTYPES

#include <cstdint>
#include <array>

using std::array;

// this type is used for puzzle and allowableValues
// it's in a separate header beause it used to be more than just a typedef
typedef array<array<uint16_t, 9> ,9> SUDOKUTYPE;
typedef uint16_t BITMASK;
#endif // _SUDOKUTYPES_H