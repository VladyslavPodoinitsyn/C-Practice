#include "greedy_robot.h"
#include <iostream>

using namespace std;

void testFindPaths(int xr, int yr, int xt, int yt, int maxDist) {
    vector<string> paths;
    findPaths(xr, yr, xt, yt, maxDist, 0, 0, "", paths);

    cout << "Paths from (" << xr << "," << yr << ") to (" << xt << "," << yt << ") with max distance " << maxDist << ":" << endl;
    printPaths(paths);
}

int main() {
    // Test cases for the findPaths function
    testFindPaths(0, 0, 2, 2, 3); // Test case 1
    testFindPaths(1, 1, 3, 3, 4); // Test case 2
    testFindPaths(0, 0, 5, 5, 6); // Test case 3

    return 0;
}
