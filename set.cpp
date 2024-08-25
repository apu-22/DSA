#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;

    s.insert(2);
    s.insert(5);
    s.insert(8);
    s.insert(6);
    s.insert(2);
    s.insert(5);

    for (int val : s)
    {
        cout << val << " " << "\n";
    }
}