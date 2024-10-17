#include "time_span.h"
#include "time_span.cpp"
#include <iostream>

void runUnitTest() {
    // Test constructor and accessors
    TimeSpan ts1(1, 2, 3);
    if (ts1.hours() == 1 && ts1.minutes() == 2 && ts1.seconds() == 3) {
        std::cout << "Constructor and accessors test passed.\n";
    } else {
        std::cout << "Constructor and accessors test failed.\n";
    }

    // Test addition operator
    TimeSpan ts2(0, 1, 30);
    TimeSpan result = ts1 + ts2;
    if (result.hours() == 1 && result.minutes() == 3 && result.seconds() == 33) {
        std::cout << "Addition test passed.\n";
    } else {
        std::cout << "Addition test failed.\n";
    }

    // Test subtraction operator
    TimeSpan ts3(0, 0, 45);
    TimeSpan ts4(0, 0, 15);
    TimeSpan result2 = ts3 - ts4;
    if (result2.hours() == 0 && result2.minutes() == 0 && result2.seconds() == 30) {
        std::cout << "Subtraction test passed.\n";
    } else {
        std::cout << "Subtraction test failed.\n";
    }
}