#ifndef _COMMON_H_
#define _COMMON_H_
#include <iostream>


template <typename T1, typename T2>
struct Array
{
    T1* data;
    T2 size;
};

template<typename T>
void coutArray(Array<T, int> input, std::string msg)
{
    std::cout << "\n>>> " << msg << ":" << std::endl;
    for(int i = 0; i < input.size; i++)
    {
        std::cout << "  " << input.data[i];
    }
    std::cout << std::endl;
}

template<typename T>
inline void swap(T* a, T* b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

void abortMesage(std::string msg);

#endif