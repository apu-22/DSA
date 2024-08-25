#include <bits/stdc++.h>

using namespace std;

void printt(set<int> &s)
{
    for (int val : s)
    {
        cout << val << " " ;
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
}