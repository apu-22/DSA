#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int weight[n];
    int profit[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> profit[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (weight[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], profit[i - 1] + dp[i - 1][w - weight[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "The Maximum number of profit/value could be fit into knapsack for m max weight is: " << dp[n][m];

    return 0;
}