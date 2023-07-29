#include <iostream>


/// @brief just make sure the current 'idx' element and its left and right children maintains the max-heap property
/// @tparam T build-in number type 
/// @param A input array
/// @param idx I- index of heap structure
/// @param heap_size I- size of the heap
template <typename T>
void maxHeapify(T* A, int idx, int heap_size);

/// @brief build the max heap in a bottom-up manner via array (T)A(this code gonna build max heap where exactly the input array is)
/// @tparam T build-in number type 
/// @param A I- input array
/// @param heap_size array size
template <typename T>
void buildMaxHeap(T* A, int heap_size);

/// @brief heap sort the array from small to large
/// @tparam T 
/// @param A I- input array
/// @param array_size I- array size
template <typename T>
void heapSort(T* A, int array_size);

void callBuildMaxHeap();