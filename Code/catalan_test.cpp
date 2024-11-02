#include "catalan.h"
#include <iostream>

using namespace std;

void testCalculateCatalan(int n, unsigned long long expected) {
    unsigned long long result = calculateCatalan(n);
    if (result == expected) {
        cout << "Test case for n = " << n << " passed. Result: " << result << endl;
    } else {
        cout << "Test case for n = " << n << " failed. Expected: " << expected << ", Actual: " << result << endl;
    }
}

int main() {
    // Test cases for the calculateCatalan function
    testCalculateCatalan(0, 1);
    testCalculateCatalan(1, 1);
    testCalculateCatalan(5, 42);
    testCalculateCatalan(10, 16796);

    return 0;
}
