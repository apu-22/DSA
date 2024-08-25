#include <iostream>
using namespace std;

int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

void printFibonacciRecursive(int n) {
    cout << "Fibonacci Series up to " << n << " terms:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << fibonacciRecursive(i) << " ";
    }
}

int main() {
    int numTerms;

    cout << "Enter the number of terms for Fibonacci Series: ";
    cin >> numTerms;

    if (numTerms <= 0) {
        cout << "Please enter a positive number of terms.";
        return 1;
    }

    printFibonacciRecursive(numTerms);

    return 0;
}
