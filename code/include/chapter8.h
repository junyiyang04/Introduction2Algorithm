#include <iostream>
#include "export_macro.h"

#include "common.h"
// ******************************************************************
// *                                                                *
// *                     COUNTING SORT                              *
// *                                                                *
// ******************************************************************

/// @brief sort with counting sort from small to big(only suitable for positive integer)
/// @param T 
/// @param input 
/// @param output 
/// @param range I- the size of range should be bigger than the max value in the input array
template <typename T>
I2A_API void countingSort(Array<T, int> input, Array<T, int>& output, int range);

I2A_API void callCountingSort();