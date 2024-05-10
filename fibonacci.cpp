#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n <= 1)
        return n;
    else
        return fibo(n - 1) + fibo(n - 2);
}

void fibonacciSeries(int n)
{
    cout << "Fibonacci series of " << n << " " << "terms is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << fibo(i) << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    fibonacciSeries(n);

    return 0;
}
