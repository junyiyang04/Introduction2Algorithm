#include "common.h"

template<typename T>
inline void swap(T* a, T* b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}
// template void swap<int>(int* a, int* b);
// template void swap<float>(float* a, float* b);
