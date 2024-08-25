#include <bits/stdc++.h>

using namespace std;

void printt(set<int> &s)
{
    for (int val : s)
    {
        cout << val << " ";
    }
    cout<<"\n";
}

void find(set<int> &s)
{
    int num = 6;
    auto it = s.find(num);

    if (it != s.end())
    {
        cout << num << " exits" << "\n";
    }
    else
    {
        cout << num << " not exits" << "\n";
    }
}

int main()
{
    set<int> s;

    s.insert(2);
    s.insert(5);
    s.insert(8);
    s.insert(6);
    s.insert(2);
    s.insert(5);

    printt(s);

    find(s);
}