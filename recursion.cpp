#include <iostream>

// Recursive factorial.
// Base case: 0! and 1! are both 1.
// Recursive case: n! = n * (n - 1)!.
int factorial_recursive(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * factorial_recursive(n - 1);
}

// Iterative factorial. Does the same work with a loop instead of call stack.
int factorial_iterative(int n) {
    int result = 1;

    for (int i = 2; i <= n; ++i) {
        result *= i;
    }

    return result;
}

// Recursively sums numbers from 1 to n.
// Base case: sum up to 0 is 0.
// Recursive case: sum(n) = n + sum(n - 1).
int sum_recursive(int n) {
    if (n <= 0) {
        return 0;
    }

    return n + sum_recursive(n - 1);
}

int main() {
    for (int n : {0, 1, 5}) {
        std::cout << n << "! recursive = " << factorial_recursive(n) << '\n';
        std::cout << n << "! iterative = " << factorial_iterative(n) << '\n';
        std::cout << "sum 1.." << n << " = " << sum_recursive(n) << '\n';
    }

    return 0;
}
