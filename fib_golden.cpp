#include <iostream>
#include <cmath>

// Function to calculate the nth Fibonacci number using the golden ratio approximation
int fibonacci_golden(int n) {
    double phi = (1 + sqrt(5)) / 2;
    int fib_n = round((pow(phi, n) - pow(1 - phi, n)) / sqrt(5));
    return fib_n;
}

int main() {
    // Using the Golden Ratio Approach
    int fib_golden_15 = fibonacci_golden(15);
    std::cout << "15th Fibonacci number (Golden Ratio): " << fib_golden_15 << std::endl;

    return 0;
}

