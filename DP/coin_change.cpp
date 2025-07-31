#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> c = {1, 3, 5};
    int s = c.size();
    cout << c[2];
    int sum = 8;
    int mt[s + 1][sum + 1];

    for (int i = 0; i <= s; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 && j == 0)
            {
                mt[i][j] = 1;
            }
            else if (i == 0)
            {
                mt[i][j] = 0; //// No way to make positive sum with 0 coins
            }
            else if (j == 0)
            {
                mt[i][j] = 1; // Only 1 way to make sum 0 — use no coins
            }
            else
            {
                if (c[i - 1] > j)
                {
                    mt[i][j] = mt[i - 1][j];
                }
                else
                {
                    mt[i][j] = mt[i - 1][j] + mt[i][j - c[i - 1]];
                }
            }
        }
    }
    cout << "the total number of ways is: " << mt[s][sum] << "\n";


      // Better approach to solved this problem(optimized the space)

    vector<int> dp(sum + 1, 0); // dp[j] =(no. of ways) 'j'টাকার জন্য কত উপায় আছে
    dp[0] = 1;
    for (int coin : c)
    {
        for (int j = coin; j <= sum; j++)
        {
            dp[j] += dp[j - coin];
        }
    }
    cout << "The total no. of way is: " << dp[sum] << "\n";
}