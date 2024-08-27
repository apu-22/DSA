#include <bits/stdc++.h>
using namespace std;

void arr_vec();
void vec_vec();

void printvec(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main()
{

    arr_vec();
    vec_vec();

}

void arr_vec()
{
    int N;
    cin >> N;
    vector<int> v[N];

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    for (int i = 0; i < N; i++)
    {
        printvec(v[i]);
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

void vec_vec(){
    int N;
    cin >> N;
    vector<vector<int>> v;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        vector<int>temp;
        for (int j = 0; j < n; j++)
        {
            int x; cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }

    v[0].push_back(8);
    v[1].pop_back();

    for (int i = 0; i < v.size(); i++)
    {
        printvec(v[i]);
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<v[i].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}