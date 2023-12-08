#include "chapter15.h"
#include "common.h"
// each rod of i inches length earns price[i] dollars of revenue
static int price[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};


// recursive top-down implementation, 
// n is the length of the rod, this programm calculate the maximum revenue
int cutRod(int* price_list, int n)
{
    if (0 == n)
        return 0;
    int revenue = -MAXIMUM;
    for(int i = 0; i < n; i++){
        int tmp_revenue = cutRod(price_list, n - i - 1) + price_list[i];
        revenue = tmp_revenue > revenue ? tmp_revenue : revenue;
    }
    return revenue;
}




void callCutRod()
{
    printf("> Running test for chapter 15\n");
    int length = 4;
    int revenue = cutRod(price, length);
    printf("> The maximum revenue of %d inches rod is %d\n", length, revenue);
    printf("> Finish test for chapter 15\n");

}