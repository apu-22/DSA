#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &num)
{
    int n = num.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (num[j] < num[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int main()
{
    vector<int> num = {1, 10, 2, 20, 3, 30};
    cout << "The length of LIS is: " << LIS(num);
}