#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int p[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> w[i];
    }
    double ratio[n + 1];
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (double)p[i] / w[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[j] > ratio[i])
            {
                swap(ratio[i], ratio[j]);
                swap(p[i], p[j]);
                swap(w[i], w[j]);
            }
        }
    }

    double totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        if (m == 0)
            break;

        if (w[i] <= m)
        {
            totalProfit += p[i];
            m -= w[i];
        }
        else
        {
            totalProfit += ratio[i] * m;
            m = 0;
        }
    }

    cout << "The maximam profit will be(in Fractional knapsack): " << totalProfit << endl;
    return 0;
}