#include "chapter6.h"
#include "common.cpp"

inline int parent(int i)
{
    return (i - 1) / 2;
}

inline int left(int i)
{
    return 2 * (i + 1) - 1;
}
inline int right(int i)
{
    return 2 * (i + 1);
}

// ******************************************************************
// *                                                                *
// *                          MAX HEAP                              *
// *                                                                *
// ******************************************************************
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
inline T heapMaximum(T* A)
{
    return A[0];
}

/// @brief extract the max value  from max heap and the size of the heap becomes 'size - 1'
/// @tparam T 
/// @param A 
/// @param size 
/// @return 
template <typename T> 
T heapExtractMax(T* A, int* size)
{
    if(*size < 1)
    {
        std::cout << ">>> heap underflow"
                  << "    aborting ..." << std::endl;
        abort();
    }
    int max = A[0];
    A[0] = A[*size - 1]; // if this lead to memory leak(better use linker list to store the data) 
    (*size)--;
    maxHeapify(A, 0, *size);
    return max;
}

/// @brief increase the specific element value to 'key'
/// @tparam T 
/// @param A 
/// @param idx 
/// @param key I- the key should be big than its original value, if not the heap would not been changed
///             (smaller value could break the property of max heap)
/// @param size 
template <typename T >
void heapIncreaseKey(T* A, int idx, T key, int size)
{
    if(idx >= size || idx < 0)
    {
        std::cout << ">>> heapIncreaseKey error:  idx is out of range ..." << std::endl;
    }
    else{
        A[idx] = key;
        int p_idx = parent(idx);
        while(idx && A[idx] > A[p_idx])
        {
            swap(A + idx, A + p_idx);
            idx = p_idx;
            p_idx = parent(idx);
        }
    }
}

// to be finished using linker list
// template <typename T>
// void maxHeapInsert(T* A, T key, int* size) // data structure should use linker list
// {
//     (*size)++;

// }

void callBuildMaxHeap()
{
    int size = 10;
    float* array = new float [size];
    Heap<float, int> h = {array, size};
    std::cout << "\n>>> origin array:" << std::endl;
    for(int i = 0; i < size; i++)
    {
        h.heap[i] = i;
        std::cout << "  " << h.heap[i];
    }
    buildMaxHeap(h.heap, h.size);
    std::cout << "\n>>> maxheap:" << std::endl;
    for(int i = 0; i < h.size; i++)
    {
        std::cout << "  " << h.heap[i];
    }
    heapSort(h.heap, h.size);
    std::cout << "\n>>> heap sort(increase):" << std::endl;
    for(int i = 0; i < h.size; i++)
    {
        std::cout << "  " << h.heap[i];
    }
    std::cout << std::endl;
    delete [] array;
}



// priority queue(using max heap), can be used to schedule jobs on a shared computer
void callPriorityQueue()
{
    int size = 10;
    float* array = new float [size];
    Heap<float, int> h = {array, size};
    std::cout << "\n>>> origin array:" << std::endl;
    for(int i = 0; i < size; i++)
    {
        h.heap[i] = i;
        std::cout << "  " << h.heap[i];
    }
    buildMaxHeap(h.heap, h.size);
    std::cout << "\n>>> maxheap:" << std::endl;
    for(int i = 0; i < h.size; i++)
    {
        std::cout << "  " << h.heap[i];
    }
    heapExtractMax(h.heap, &h.size);
    std::cout << "\n>>> heap extract max:" << std::endl;
    for(int i = 0; i < h.size; i++)
    {
        std::cout << "  " << h.heap[i];
    }
    std::cout << std::endl;
    std::cout << "  size after extract " << h.size << std::endl;
    int idx = 8;
    float key = 6;
    heapIncreaseKey(h.heap, idx, key, h.size);
    std::cout << "\n>>> heap increase No." << idx << " to " << key << ":" << std::endl;
    for(int i = 0; i < h.size; i++)
    {
        std::cout << "  " << h.heap[i];
    }
    std::cout << std::endl;
    
    delete [] array;
}

