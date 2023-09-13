#include <iostream>
#include "export_macro.h"
// merge
template <typename T>
I2A_API void merge(T* A, int p , int q, int r);

// mergre sort 
template <typename T>
I2A_API void mergeSort(T* A, int p, int r);

I2A_API void callMergeSort();