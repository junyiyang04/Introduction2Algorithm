#ifndef _CHAPTER_15_
#define _CHAPTER_15_
#include <iostream>
#include "export_macro.h"

// *************************************************************************************
// *                                                                                   *
// *                         DYNAMIC PROGRAMMING                                       *
// *                                                                                   *
// *    The four steps to follow when we are developing a                              *
// *    dynamic-programming algorithm                                                  *
// *    1. Characterize the structure of an optimal solution                           *
// *    2. Recursively define the value of an optimal solution                         *
// *    3. Compute the value of an optimal solution, typically in a bottom-up solution *
// *    4. Construct an optimal solution from computed information                     *
// *                                                                                   *
// *    Step 1-3 is the basis of a dynamic-programming solution to a problem, if we    *
// *    need only the value of the optimal solution and not the solution itself, we    *
// *    omit step4.                                                                    *
// *    When we do perform the step 4, we sometimes maintain addtional information     *
// *    during step 3 so that we can easily construct an optimal solution              *
// *                                                                                   *
// *************************************************************************************

/// @brief calculate the maximum revenue of n inches rod based on the price-list 
/// @param price_list     I- the price_list for i inches rod is price_list[i]
/// @param price_list_len I- the price_list length
/// @param n              I- n is the length of the rod, this programm calculate the maximum revenue
/// @return the maximum revenue of a n inches rod
/// @note recursive top-down implementation
I2A_API int cutRod(int* price_list, int price_list_len, int n);

/// @brief initialize auxiliary array which is a memoized version of 'cutRod'
/// @param price_list     I- the price_list for i inches rod is price_list[i]
/// @param price_list_len I- the price_list length
/// @param n              I- n is the length of the rod, this programm calculate the maximum revenue
/// @param r_array        IO- auxiliary array that remembers previous procedure
/// @return the maximum revenue of a n inches rod
I2A_API int memoizedCutRodAux(int* price_list, int price_list_len, int n, int* r_array);

/// @brief calculate the maximum revenue of n inches rod based on the price-list 
/// @param price_list I the price_list for i inches rod is price_list[i]
/// @param price_list_len I the price_list length
/// @param n n is the length of the rod, this programm calculate the maximum revenue
/// @return the maximum revenue of a n inches rod
/// @note recursive top-down with memoization implementation
I2A_API int memoizedCutRod(int *price_list, int price_list_len, int n);

/// @brief 
/// @param price_list 
/// @param price_list_len 
/// @param n 
/// @return 
/// @note 
I2A_API int bottomUpCutRod(int *price_list, int price_list_len, int n);

I2A_API void callCutRod();




I2A_API void callMatrixChainOrder();




#endif