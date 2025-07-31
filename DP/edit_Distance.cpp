#include <bits/stdc++.h>
using namespace std;

int editDistance(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j; //base case-->insert all j char(from str 2)
            else if (j == 0)
                dp[i][j] = i; //base case-->delete all i char(from str1)
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + min({
                                   dp[i - 1][j],    // delete char
                                   dp[i][j - 1],    // insert char
                                   dp[i - 1][j - 1] // replace char
                               });
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << "Edit Distance: " << editDistance(str1, str2) << endl;
    return 0;
}