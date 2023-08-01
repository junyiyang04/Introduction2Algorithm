#include "chapter8.h"
#include "common.h"
// ******************************************************************
// *                                                                *
// *                     COUNTING SORT                              *
// *                                                                *
// ******************************************************************

/// @brief sort with counting sort from small to big
///   (only suitable for positive integer, negtive can be modified from this programme)
/// @param T 
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
    for(int i = 0; i < input.size; i++){
        counter[input.data[i]]++;
    }
    for(int i = 1; i < range; i++){
        counter[i] += counter[i - 1];
    }
    for(int i = 0; i < input.size; i++){
        // std::cout << "location: " << counter[input.data[i]] << std::endl;
        output.data[counter[input.data[i]] - 1] = input.data[i];
        counter[input.data[i]]--;
    }
    // input: [5, 4, 5, 3, 8, 7]
    // index:    0  1  2  3  4  5  6  7  8
    // counter: [0, 0, 0, 0, 0, 0, 0, 0, 0] there is nine number in the counter
    // counter: [0, 0, 0, 1, 1, 2, 0, 1, 1]
    // counter: [0, 0, 0, 1, 2, 4, 0, 5, 6] 
    // the extraction from 'counter' should depend on the the origin 'input'
    delete [] counter;
}

// ******************************************************************
// *                                                                *
// *                        RADIX SORT                              *
// *                                                                *
// ******************************************************************
template <typename T>
void radixSort()
{

}

void callCountingSort()
{
    int size = 10;
    Array<int, int> array;
    array.data = new int [size];
    array.size = size;
    for(int i = 0; i < size; i++){
        array.data[i] = size - i - 1;
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