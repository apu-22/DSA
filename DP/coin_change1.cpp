#include <bits/stdc++.h>
using namespace std;
int minCoins(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount];
}

int optMinCoin(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1); // initialize with a large value
    dp[0] = 0;

    for (int coin : coins)
    {
        for (int i = coin; i <= amount; i++)
        {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}
int main()
{
    int n, amount;
    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter total amount: ";
    cin >> amount;

    int result = minCoins(coins, amount);
    if (result == -1)
        cout << "Not possible to make the amount with given coins." << endl;
    else
        cout << "Minimum number of coins needed: " << result << endl;

    // Optimized space approach

    int result1 = minCoins(coins, amount);
    if (result1 == -1)
        cout << "Not possible to make the amount with given coins." << endl;
    else
        cout << "Minimum number of coins needed: " << result1 << endl;
}