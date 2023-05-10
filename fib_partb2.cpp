#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

const double goldenRatio = 1.618033988749895;


// Function to calculate Fibonacci number using Equation (3)
int fibonacciEquation3(int n) {
    double sqrt5 = sqrt(5);
    double phi = (1 + sqrt5);
    double psi = (1 - sqrt5);

    double fn = (pow(phi, n) - pow(psi, n)) / (pow(2, n) * sqrt5);

    return static_cast<int>(round(fn));
}

// Function to calculate Fibonacci number using Equation (4)
int fibonacciEquation4(int p, int n) {
    double phi = (1 + sqrt(5)) / 2;
    double fn = fibonacciEquation3(n) * pow(phi, n - p);

    return static_cast<int>(round(fn));
}

// Function to calculate Fibonacci number using Equation (5)
int fibonacciEquation5(int n) {
    double phi = (1 + sqrt(5)) / 2;
    double fn = fibonacciEquation3(n) * phi;

    return static_cast<int>(round(fn));
}

// Function to print the first 20 terms of Fibonacci sequence using Equations (4) and (5)
void printFibonacciTerms(int n) {
    cout << "Using Equation (4): ";
    for (int i = 0; i <= n; i++) {
        int term = fibonacciEquation4(0, i);
        cout << term << " ";
    }
    cout << endl;

    cout << "Using Equation (5): ";
    for (int i = 0; i <= n; i++) {
        int term = fibonacciEquation5(i);
        cout << term << " ";
    }
    cout << endl;
}

// Function to compare outputs of Equations (4) and (5)
void compareFibonacciOutputs(int n) {
    cout << "Comparison of outputs:" << endl;
    for (int i = 0; i <= n; i++) {
        int termEquation4 = fibonacciEquation4(0, i);
        int termEquation5 = fibonacciEquation5(i);
        cout << "Equation (4): " << termEquation4 << ", Equation (5): " << termEquation5;
        if (termEquation4 == termEquation5) {
            cout << " (Equal)";
        } else {
            cout << " (Not Equal)";
        }
        cout << endl;
    }
}


// Function to check the maxim that the ratio of consecutive Fibonacci numbers approaches the Golden Ratio
void checkMaxim() {
    double ratio1 = static_cast<double>(fibonacciEquation5(3)) / fibonacciEquation5(2);
    double ratio2 = static_cast<double>(fibonacciEquation5(30)) / fibonacciEquation5(29);
    
    double goldenRatio = (1 + sqrt(5)) / 2;

    std::cout << "The golden ratio is: " << goldenRatio << std::endl;
    std::cout << "Ratio of F(3) / F(2): " << ratio1 << std::endl;
    std::cout << "Ratio of F(30) / F(29): " << ratio2 << std::endl;


    

    if (std::abs(ratio1 - goldenRatio) < 1e-9 || std::abs(ratio2 - goldenRatio) < 1e-9) {
        std::cout << "The ratio of consecutive Fibonacci numbers approaches the Golden Ratio." << std::endl;
    } else {
        std::cout << "The ratio of consecutive Fibonacci numbers does not approach the Golden Ratio." << std::endl;
    }   

}


/*

void checkMaxim() {
    double ratio1 = static_cast<double>(fibonacciEquation5(3)) / fibonacciEquation5(2);
    double ratio2 = static_cast<double>(fibonacciEquation5(30)) / fibonacciEquation5(29);

    std::cout << "The golden ratio is: " << goldenRatio << std::endl;
    cout << "Ratio of F(3) / F(2): " << ratio1 << endl;
    cout << "Ratio of F(30) / F(29): " << ratio2 << endl;

    if (abs(ratio1 - ratio2) < 1e-9) {
        cout << "The ratio of consecutive Fibonacci numbers approaches the Golden Ratio." << endl;
    } else {
        cout << "The ratio of consecutive Fibonacci numbers does not approach the Golden Ratio." << endl;
    }
}
*/


int main() {
    int p, n;

    cout << "Enter the value of 'p' (a positive integer): ";
    cin >> p;

    while (cin.fail() || p <= 0 || floor(p) != p) {
        cout << "Invalid input. Please enter a positive integer for 'p': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> p;
    }

    cout << "Enter the value of 'n' (a non-negative integer): ";
    cin >> n;


    while (cin.fail() || n < 0 || floor(n) != n) {
        cout << "Invalid input. Please enter a non-negative integer for 'n': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> n;
    }

    // Part 1: Fibonacci Numbers
    cout << "Using Equation (4): ";
    for (int i = 0; i <= n; i++) {
        int term = fibonacciEquation4(p, i);
        cout << term << " ";
    }
    cout << endl;

    cout << "Using Equation (5): ";
    for (int i = 0; i <= n; i++) {
        int term = fibonacciEquation5(i);
        cout << term << " ";
    }
    cout << endl;

    compareFibonacciOutputs(n);
    checkMaxim();

    return 0;
}



