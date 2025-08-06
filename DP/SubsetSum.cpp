#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int t = 1; t <= target; t++)
        {
            if (arr[i - 1] > t)
                dp[i][t] = dp[i - 1][t];
            else
                dp[i][t] = dp[i - 1][t] || dp[i - 1][t - arr[i - 1]];
        }
    }
    return dp[n][target];
}
int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << subsetSum(arr, target);
}