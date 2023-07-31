#include "common.h"

// template<typename T>
// inline void swap(T* a, T* b)
// {
//     T tmp = *a;
//     *a = *b;
//     *b = tmp;
// }
// template void swap<int>(int* a, int* b); // 实例化
// template void swap<float>(float* a, float* b);

void abortMesage(std::string msg)
{
    std::cout << ">>> " << msg << std::endl
                << "    aborting ..." << std::endl;
    abort();
}
