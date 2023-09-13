#ifndef _CHAPTER_6_
#define _CHAPTER_6_

#include <iostream>
#include "export_macro.h"

// #include <concepts>
// #include <type_traits>

// template <typename T3>
// concept integral = std::is_integral_v<T3>;

template <typename T1, typename T2>

struct Heap
{
    T1* heap;
    T2 size;
};


/// @brief just make sure the current 'idx' element and its left and right children maintains the max-heap property
/// @tparam T build-in number type 
/// @param A input array
/// @param idx I- index of heap structure
/// @param heap_size I- size of the heap
template <typename T>
I2A_API void maxHeapify(T* A, int idx, int heap_size);

/// @brief build the max heap in a bottom-up manner via array (T)A(this code gonna build max heap where exactly the input array is)
/// @tparam T build-in number type 
/// @param A I- input array
/// @param heap_size array size
template <typename T>
I2A_API void buildMaxHeap(T* A, int heap_size);

/// @brief heap sort the array from small to large
/// @tparam T 
/// @param A I- input array
/// @param array_size I- array size
template <typename T>
I2A_API void heapSort(T* A, int array_size);


// ******************************************************************
// *                                                                *
// *                     PRIORITY QUEUE                             *
// *            ToDo: data should be stored in linker list          *
// *                                                                *
// ******************************************************************

/// @brief return max heap value
/// @tparam T 
/// @param A
/// @return 
template <typename T>
I2A_API inline T heapMaximum(T* A);

/// @brief extract the max value  from max heap and the size of the heap becomes 'size - 1'
/// @tparam T 
/// @param A 
/// @param size 
/// @return 
template <typename T> 
I2A_API T heapExtractMax(T* A, int* size);

/// @brief increase the specific element value to 'key'
/// @tparam T 
/// @param A 
/// @param idx 
/// @param key I- the key should be big than its original value, if not the heap would not been changed
///             (smaller value could break the property of max heap)
/// @param size 
template <typename T >
I2A_API void heapIncreaseKey(T* A, int idx, T key, int size);

I2A_API void callBuildMaxHeap();
I2A_API void callPriorityQueue();

#endif