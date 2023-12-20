#include <iostream>
#include "./code/include/include.h"

int hash(const std::string &key) {
    int sum = 0;
    for (char c : key) {
        sum += c;
        std::cout << " the value of sum: " << sum << std::endl;
    }
    return sum % 10;
}


int main()
{
    // // chapter2
    // callMergeSort();

    // // chapter6
    // callBuildMaxHeap();
    // callPriorityQueue();

    // // chapter7
    // callQuickSort();

    // // chapter8
    // callCountingSort();

    // // chapter10
    // callLNode();
    // callDLNode();

    // int total = 10;
    // std::string name = "Cillian";
    // hash(name);

    // // chapter31
    // callEuclid();
    // callModularLinearEquationSolver();
    // callModularExponentiation();

    // // chapter12
    // callBinarySearchTree();

    // chapter13
    // callRedBlackTree();

    // chapter15
    // callCutRod();
    callMatrixChainOrder();

    return 0;
}
