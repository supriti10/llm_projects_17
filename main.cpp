
#include <iostream>
#include <iomanip>
#include <chrono>

double calculate(int iterations, double param1, double param2) {
    double result = 1.0;
    // Use a vectorized loop if possible, or optimize the calculations within the loop.
    // The current implementation is already quite straightforward for direct translation.
    for (int i = 1; i <= iterations; ++i) {
        double j1 = static_cast<double>(i) * param1 - param2;
        result -= (1.0 / j1);
        double j2 = static_cast<double>(i) * param1 + param2;
        result += (1.0 / j2);
    }
    return result;
}

int main() {
    // Use C++ chrono for timing
    auto start_time = std::chrono::high_resolution_clock::now();

    // Larger precision for calculations
    double param1 = 4.0;
    double param2 = 1.0;
    int iterations = 200000000;

    // Perform the calculation
    double result = calculate(iterations, param1, param2) * 4.0;

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    // Print the result with specified precision
    std::cout << std::fixed << std::setprecision(12) << "Result: " << result << std::endl;
    // Print execution time with specified precision
    std::cout << std::fixed << std::setprecision(6) << "Execution Time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
