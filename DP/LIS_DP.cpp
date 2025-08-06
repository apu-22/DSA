#include <bits/stdc++.h>
using namespace std;

int LIS_DP(vector<int> &num)
{
    int n = num.size();
    vector<int> dp(n, 1);
                                //DP[bottom-up approach-->T.C:O(n^2)]
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

int LIS_BS(vector<int> &nums){
    int n=nums.size();
    vector<int> temp;
                        //using binary search with patience sort[T.C: O(NlogN)]
    for(int num:nums){
        auto it= lower_bound(temp.begin(),temp.end(),num);
        if(it==temp.end()){
            temp.push_back(num);
        }else{
            *it=num;
        }
    }
      return temp.size();
}
int main()
{
    vector<int> num = {1, 10, 2, 20, 3, 30};
    cout << "The length of LIS is: " << LIS_DP(num)<<"\n\n";

    cout << "The length of LIS is: " << LIS_BS(num);
}