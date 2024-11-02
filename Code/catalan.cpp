#include "catalan.h"
using namespace std;
unsigned long long calculateCatalan(int n) {
    // Base cases
    if (n == 0 || n == 1) {
        return 1;
    }

    // Calculate nth Catalan number using recursion
    unsigned long long result = 0;
    for (int i = 0; i < n; i++) {
        result += calculateCatalan(i) * calculateCatalan(n - i - 1);
    }
    return result;
}

int main(int argc, char* argv[]) {
    // Check if an argument is provided
    if (argc != 2) {
        cerr << "Usage: catalan <non-negative integer>" << endl;
        return 1;
    }

    // Parse input
    int n;
    try {
        n = stoi(argv[1]);
    } catch (...) {
        cerr << "Invalid input. Please provide a non-negative integer." << endl;
        return 1;
    }

    if (n < 0) {
        cerr << "Negative numbers are not allowed." << endl;
        return 1;
    }

    const int LIMIT = 20; // Limit to avoid large computations
    if (n > LIMIT) {
        cerr << "Input too large to compute efficiently." << endl;
        return 1;
    }

    // Calculate and print the nth Catalan number
    cout << calculateCatalan(n) << endl;

    return 0;
}
