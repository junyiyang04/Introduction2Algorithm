#include "chapter8.h"
#include "common.h"
// ******************************************************************
// *                                                                *
// *                     COUNTING SORT                              *
// *                                                                *
// ******************************************************************

/// @brief sort with counting sort
/// @tparam T 
/// @param input 
/// @param output 
/// @param range I- the size of range should be bigger than the max value in the input array
template <typename T>
void countingSort(Array<T, int> input, Array<T, int>& output, int range)
{
    if(input.size != output.size){
        abortMesage("input is not the same size with output");
    }
    T* counter = new T [range];
    for(int i = 0; i < range; i++)
    {

    }




    delete [] counter;
}

void callCountingSort()
{
    int size = 10;
    Array<int, int> array;
    array.data = new int [size];
    array.size = size;
    for(int i = 0; i < size; i++){
        array.data[i] = size - i;
    }
    coutArray(array, "origin array");

    // sort 
    Array<int, int> sort;
    sort.data = new int[size];
    sort.size = size;
    countingSort(array, sort, size + 1);
    coutArray(sort, "sorted array");
    delete [] array.data;
    delete [] sort.data;
    array.data = sort.data = nullptr;
}