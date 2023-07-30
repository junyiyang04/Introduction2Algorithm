#include "chapter7.h"
#include "common.cpp"

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
void quickSort(T* A, int start, int end)
{
    int middle = 0;
    if(start < end)
    {
        middle = partition(A, start, end);
        quickSort(A, start, middle - 1);
        quickSort(A, middle + 1, end);
    }
}

/// @brief partition the array(make elements whoes index smaller 
///        than middle are smaller than the value of middle element)
/// @tparam T 
/// @param A 
/// @param start 
/// @param end 
/// @return 
template <typename T>
int partition(T* A, int start, int end)
{
    T cmp = A[end];
    int middle = start - 1;
    for(int i = start; i < end; i++){
        if(A[i] < cmp){ // equality is alse ok in the book(more time consumed)
            middle++;
            // elemements whoes index not bigger than middle are smaller than 'cmp'
            swap(A + middle, A + i);
        }
    }
    middle++;
    swap(A + middle, A + end);
    return middle;
}

void callQuickSort()
{
    int size = 10;
    float* array = new float [size];
    std::cout << "\n>>> origin array:" << std::endl;
    for(int i = 0; i < size; i++)
    {
        array[i] = size - i;
        std::cout << "  " << array[i];
    }       
    std::cout << std::endl;
    quickSort(array, 0, size - 1);
    std::cout << "\n>>> sorted array:" << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cout << "  " << array[i];
    } 
    std::cout << std::endl;

}
