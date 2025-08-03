#include <bits/stdc++.h>
using namespace std;

void LCS(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // if (str1[i] == str2[j])
            // {
            //     dp[i][j] = dp[i - 1][j - 1] + 1;
            // }
            // else
            // {
            //     dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            // }

            dp[i][j] = (str1[i - 1] == str2[j - 1]) ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << "The length of LCS is: " << dp[n][m];

    // Backtrack to get LCS:
    string lcs = "";
    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs = str1[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            j--;
        }
        else
            i--;
    }

    cout << "LCS is: " << lcs << endl;
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    LCS(str1, str2);
}