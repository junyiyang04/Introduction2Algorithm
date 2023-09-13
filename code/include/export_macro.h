#ifndef _export_macro_h_
#define _export_macro_h_
#include <iostream>
#include "config.h"
#if defined(I2A_DLL_BUILD)
#if defined(_MSC_VER) || defined (__MINGW32__)
#define I2A_API __declspec(dllexport)
#elif defined(__GNUC__) || defined(__clang__)
#define I2A_API __attribute__((visibility("default")))
#endif
#elif defined(I2A_DLL)
#if defined(_MSC_VER) || defined (__MINGW32__)
#define I2A_API __declspec(dllexport)
#endif
#endif

#ifndef I2A_API
#define I2A_API
#endif

#endif