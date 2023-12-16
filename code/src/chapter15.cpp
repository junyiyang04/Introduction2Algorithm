#include "chapter15.h"
#include "common.h"



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



// each rod of i inches length earns price[i] dollars of revenue
static int price[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};


/// @brief calculate the maximum revenue of n inches rod based on the price-list 
/// @param price_list     I- the price_list for i inches rod is price_list[i]
/// @param price_list_len I- the price_list length
/// @param n              I- n is the length of the rod, this programm calculate the maximum revenue
/// @return the maximum revenue of a n inches rod
/// @note recursive top-down implementation
int cutRod(int* price_list, int price_list_len, int n)
{
    if (0 == n)
        return 0;
    int revenue = 0x80000001;
    for(int i = 1; i <= n; i++){
        printf("enter %d\n", i);
        int price4part = 0;
        if (i <= price_list_len)
            price4part = price_list[i - 1];
        int tmp_revenue = cutRod(price_list, price_list_len, n - i) + price4part;
        revenue = tmp_revenue > revenue ? tmp_revenue : revenue;
    }
    return revenue;
}

/// @brief initialize auxiliary array which is a memoized version of 'cutRod'
/// @param price_list     I- the price_list for i inches rod is price_list[i]
/// @param price_list_len I- the price_list length
/// @param n              I- n is the length of the rod, this programm calculate the maximum revenue
/// @param r_array        IO- auxiliary array that remembers previous procedure
/// @return the maximum revenue of a n inches rod
int memoizedCutRodAux(int* price_list, int price_list_len, int n, int* r_array)
{
    if(r_array[n] >= 0){
        return r_array[n];
    }   
    int q;
    if(n == 0)
        q = 0;
    else{
        q = 0x80000001;
        for(int i = 1; i <= n; i++){
        int price4part = 0; // the price for the part of cut down rod
        if (i <= price_list_len)
            price4part = price_list[i - 1];
        int tmp_q = price4part + memoizedCutRodAux(price_list, price_list_len, n - i, r_array);
        q = q > tmp_q ? q : tmp_q;
        }
    }
    r_array[n] = q;
    for(int i = 0; i <= n; i++)
        printf("   r_array[%d]=%d\n",i, r_array[i]);
    return q;
}

/// @brief calculate the maximum revenue of n inches rod based on the price-list 
/// @param price_list I the price_list for i inches rod is price_list[i]
/// @param price_list_len I the price_list length
/// @param n n is the length of the rod, this programm calculate the maximum revenue
/// @return the maximum revenue of a n inches rod
/// @note recursive top-down with memoization implementation
int memoizedCutRod(int *price_list, int price_list_len, int n)
{
    int* r = (int*)malloc(sizeof(int) * (n + 1));
    for(int i = 0; i <= n; i++){
        r[i] = 0x80000001;
    }
    int q = memoizedCutRodAux(price_list, price_list_len, n, r);
    free(r);
    return q;
}


/// @brief 
/// @param price_list 
/// @param price_list_len 
/// @param n 
/// @return 
/// @note 
int bottomUpCutRod(int *price_list, int price_list_len, int n)
{
    int* r = (int*)malloc(sizeof(int) * (n + 1));
    r[0] = 0;
    for(int j = 1; j <= n; j++){
        int q = 0x80000001;
        for(int i = 1; i <= j; i++){
            int tmp_q = price_list[i - 1] + r[j - i];
            q = q > tmp_q ? q : tmp_q;
        }
        r[j] = q;
    }
    int revenue = r[n];
    free(r);
    return revenue;
}

void callCutRod()
{
    printf("> Running test for chapter 15\n");
    // when the lenght is bigger than 20, the speed difference is apparently to tell
    int length = 20;
    int revenue0 = cutRod(price, 10, length);
    int revenue1 = memoizedCutRod(price, 10, length);
    printf("> The maximum revenue of %d inches rod is %d\n", length, revenue0);
    printf("> The maximum revenue of %d inches rod is %d(using memoized method to remember steps that have been worked through)\n", length, revenue1);
    printf("> Finish test for chapter 15\n");
}