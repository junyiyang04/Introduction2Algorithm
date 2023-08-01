#include <iostream>
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
void countingSort(Array<T, int> input, Array<T, int>& output, int range);

void callCountingSort();