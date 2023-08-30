#include "chapter31.h"

// ******************************************************************
// *                                                                *
// *                      EUCLID ALGORITHM                          *
// *                - using GCD recursion theorem                   *
// *                                                                *
// ******************************************************************


/// @brief Euclid's algorithm used to compute the greatest common divisor of two integers
/// @param n1 I- first nonnegative integer
/// @param n2 I- second nonneagative integer
/// @return the greatest common divisor
int EUCLID(int n1, int n2)
{
    if (0 == n2)
        return n1;
    else
        return EUCLID(n2, n1 % n2); // gcd(a,b) = gcd(b, a mod b)
}

/// @brief the extended form of Eucilid's algorihtm
/// @param n1 -I first nonnegative integer
/// @param n2 -I second nonneagative integer
/// @return gcd and coefficients
GCD_Coeffi ExtendEUCLID(int n1, int n2)
{
    // gcd = n1 * c1 + n2 * c2
    // gcd = n2 * c1' + (n1 - n2⌊n1 / n2⌋) * c2'
    // which derived:
    //  c1 = c2'
    //  c2 = c1' - ⌊n1 / n2⌋ * c2'
    GCD_Coeffi gcd{n1, 1, 0};
    if(0 != n2)
    {
        GCD_Coeffi tmp_gcd = ExtendEUCLID(n2, n1 % n2);
        gcd.gcd = tmp_gcd.gcd;
        gcd.c1 = tmp_gcd.c2;
        gcd.c2 = tmp_gcd.c1 - n1 / n2 * tmp_gcd.c2;
    }
    return gcd;
}


void callEuclid()
{
    int a = 100;
    int b = 50;
    printf("cp31: the greatest common divisor of %d and %d is %d\n", 
            a, b, EUCLID(b, a));

    int c = 14, d = 100;
    GCD_Coeffi gcd = ExtendEUCLID(c, d);
    printf("cp31: the greatest common divisor of %d and %d is %d\n", 
            c, d, gcd.gcd);
    printf("\tand  %d = %d * %d + %d * %d\n",
            gcd.gcd, c, gcd.c1, d, gcd.c2);

}

// ******************************************************************
// *                                                                *
// *                    modular arithmetic                          *
// *                - using GCD recursion theorem                   *
// *                                                                *
// ******************************************************************

/// @brief solve the equation ret = a % n
/// @param a 
/// @param n 
/// @return 
inline int mod(int a, int n)
{
    int m = a % n;
    return m < 0 ? m + n : m;
}

/// @brief solve the modular linear equation that ax ≡ b(mod n)
/// @param a 
/// @param b 
/// @param n 
void modularLinearEquationSolver(int a, int b, int n)
{
    GCD_Coeffi gcd = ExtendEUCLID(a, n);
    if(b % gcd.gcd){
        printf("there is no solution\n");
    }
    else{
        int sln0 = mod(gcd.c1 * (b / gcd.gcd), n);
        for(int i = 0; i < gcd.gcd; i++)
        {
            int sln_i = mod(sln0 + i * (n / gcd.gcd), n);
            printf("No.%d solution is %d\n", i, sln_i);
        }
    }
}

void callModularLinearEquationSolver()
{
    int a = 3;
    int b = 1;
    int n = 7;
    GCD_Coeffi gcd = ExtendEUCLID(a, n);
    printf("cp31: the greatest common divisor of %d and %d is %d\n", 
            a, n, gcd.gcd);
    printf("\tand  %d = %d * %d + %d * %d\n",
            gcd.gcd, a, gcd.c1, n, gcd.c2);
    modularLinearEquationSolver(a, b, n);
}