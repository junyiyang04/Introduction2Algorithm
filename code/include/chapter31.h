#ifndef _CHAPTER_31_
#define _CHAPTER_31_
#include <iostream>

// ******************************************************************
// *                                                                *
// *                      EUCLID ALGORITHM                          *
// *                - using GCD recursion theorem                   *
// *                                                                *
// ******************************************************************

/**
 * the greatest common divisor with corresponding coefficients
 * gcd = n1 * c1 + n2 * c2
 * if gcd==1, c1 is also the inverse of n1
*/
typedef struct _GCD_Coeffi_
{
    int gcd;
    int c1;
    int c2;
}GCD_Coeffi;

/// @brief Euclid's algorithm used to compute the greatest common divisor of two integers
/// @param n1 I- first integer
/// @param n2 I- second integer
/// @return the greatest common divisor
int EUCLID(int n1, int n2);

/// @brief the extended form of Eucilid's algorihtm
/// @param n1 -I first nonnegative integer
/// @param n2 -I second nonneagative integer
/// @return gcd and coefficients
GCD_Coeffi ExtendEUCLID(int n1, int n2);

void callEuclid();


void callModularLinearEquationSolver();



/// @brief computing a^b(mod n)
/// @param a 
/// @param b 
/// @param n 
/// @return 
int ModularExponentiation(int a, int b, int n);

void callModularExponentiation();


// ******************************************************************
// *                                                                *
// *                    Primality testing                           *
// *                - 伪素数测试法PseudoPrime                         *
// *                - 随机素数测试Miller-Rabin                        *
// *                -                   *
// *                                                                *
// ******************************************************************

/// @brief checking the primality of n
/// @param n 
/// @return if primality return true
bool PseudoPrime(int n);

#endif