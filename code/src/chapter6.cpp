#include "chapter6.h"

inline int left(int i)
{
    return 2 * (i + 1) - 1;
}
inline int right(int i)
{
    return 2 * (i + 1);
}

template <typename T>
inline void swap(T* a, T*b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}
/// @brief just make sure the current 'idx' element and its left and right children maintains the max-heap property
/// @tparam T build-in number type 
/// @param A input array
/// @param idx I- index of heap structure
/// @param heap_size I- size of the heap
template <typename T>
void maxHeapify(T* A, int idx, int heap_size)
{
    int largest = idx;
    int l_idx = left(idx);
    int r_idx = right(idx);
    if(l_idx < heap_size && A[l_idx] > A[idx]){
        largest = l_idx;
    }
    // we init largest as idx to omit this segment
    // else{
    //     largest = idx;
    // }
    if(r_idx < heap_size && A[r_idx] > A[largest]){
        largest = r_idx;
    }
    if(largest != idx){
        T tmp  = A[idx];
        A[idx]=  A[largest];
        A[largest] = tmp;
        maxHeapify(A, largest, heap_size);
    }
}

/// @brief build the max heap in a bottom-up manner via array (T)A(this code gonna build max heap where exactly the input array is)
/// @tparam T build-in number type 
/// @param A I- input array
/// @param heap_size array size
template <typename T>
void buildMaxHeap(T* A, int heap_size)
{
    for(int i = heap_size / 2 - 1; i > -1 ; i--) // start backward from point that are not leaf
        maxHeapify(A, i, heap_size);
}
// 
// heap sort

/// @brief heap sort the array from small to large
/// @tparam T 
/// @param A I- input array
/// @param array_size I- array size
template <typename T>
void heapSort(T* A, int array_size)
{
    buildMaxHeap(A, array_size);
    // for(int i = array_size - 1; i > 0; i --){
    //     swap(A, A + i);
    //     array_size--;
    //     maxHeapify(A, 0, array_size); 
    // }
    for(; array_size-- > 0;){ // more condensed way
        swap(A, A + array_size);
        maxHeapify(A, 0, array_size); 
    }
}

void callBuildMaxHeap()
{
    int size = 10;
    float* array = new float [size];
    std::cout << "\n>>> origin array:" << std::endl;
    for(int i = 0; i < size; i++)
    {
        array[i] = i;
        std::cout << "  " << array[i];
    }
    buildMaxHeap(array, size);
    std::cout << "\n>>> maxheap:" << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cout << "  " << array[i];
    }
    heapSort(array, size);
    std::cout << "\n>>> heap sort:" << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cout << "  " << array[i];
    }
    std::cout << std::endl;
    
    delete [] array;
}

