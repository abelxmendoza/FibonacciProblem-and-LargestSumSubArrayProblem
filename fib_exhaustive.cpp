#include <iostream>


// Recursive function to calculate the nth Fibonacci number (exhaustive pattern)
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    // Using the Exhaustive Pattern
    int fib_15 = fibonacci(15);
    std::cout << "15th Fibonacci number (Exhaustive Pattern): " << fib_15 << std::endl;

    return 0;
}
