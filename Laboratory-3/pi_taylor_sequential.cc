#include <iomanip>
#include <chrono>
#include <iostream>
#include <limits>
#include <string>

// Allow to change the floating point type
using my_float = long double;

my_float pi_taylor(size_t steps) {

    my_float pi{ 0 }; // my_float pi = 0
    int sign = 1;

    for (size_t n = 0; n < steps; n++) {
        pi += static_cast<my_float>(sign / ((2 * n) + 1));
        sign = -sign;
    }
    pi *= 4;

    return pi;
}

int main(int argc, const char* argv[]) {

    // read the number of steps from the command line
    if (argc != 2) {
        std::cerr << "Invalid syntax: pi_taylor <steps>" << std::endl;
        exit(1);

    }

    size_t steps = std::stoll(argv[1]);
    auto start = std::chrono::steady_clock::now();
    auto pi = pi_taylor(steps);
    auto stop = std::chrono::steady_clock::now();
    auto elapsed = stop - start;

    std::cout << "For " << steps << ", pi value: "
        << std::setprecision(std::numeric_limits<my_float>::digits10 + 1)
        << pi << ". Elapsed time: " << elapsed.count() / 1000000000.0f << "s" << std::endl;
}
