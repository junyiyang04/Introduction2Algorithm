#include <iostream>

// ******************************************************************
// *                                                                *
// *                        QUICK SORT                              *
// *                                                                *
// ******************************************************************

/// @brief quick sort(element between start and end will be sorted)
/// @tparam T 
/// @param A I-  input array 
/// @param start I- start element index
/// @param end I- end element index
template <typename T>
void quickSort(T* A, int start, int end);

/// @brief partition the array(make elements whoes index smaller 
///        than middle are smaller than the value of middle element)
/// @tparam T 
/// @param A 
/// @param start 
/// @param end 
/// @return 
template <typename T>
int partition(T* A, int start, int end);

void callQuickSort();