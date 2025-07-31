#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> hp(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        cin >> hp[i][0] >> hp[i][1] >> hp[i][2];
    }
    int preA = hp[0][0];
    int preB = hp[0][1];
    int preC = hp[0][2];
    // Find the maximum possible total points of happiness that Taro gains.
    for (int i = 1; i < n; i++)
    {
        int currA = hp[i][0] + max(preB, preC);
        int currB = hp[i][1] + max(preA, preC);
        int currC = hp[i][2] + max(preB, preA);

        preA = currA;
        preB = currB;
        preC = currC;
    }
    cout << max({preA, preB, preC});
    return 0;
}