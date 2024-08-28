#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<pair<string, string>, vector<int>> m;
    int n;
    cin >> n;

    while (n--)
    {
        string fn, ln;
        int cnt;
        cin >> fn >> ln >> cnt;
        for (int i = 0; i < cnt; i++)
        {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }

    for (auto &pr : m)
    {
        auto &name = pr.first;
        auto &list = pr.second;

        cout << name.first << " " << name.second << "\n";
        cout << list.size() << "\n";

        for (auto &element : list)
        {
            cout << element << " ";
        }
        cout << "\n";
    }
}