#include <bits/stdc++.h>

using namespace std;

void printt(set<int> &s)
{
    for (int val : s)
    {
        cout << val << " ";
    }
    cout << "\n";
}

void find(set<int> &s)
{
    int num = 6;
    auto it = s.find(num);

    if (it != s.end())
    {
        cout << (*it) << " exits" << "\n";
    }
    else
    {
        cout << (*it) << " not exits" << "\n";
    }
}

void delete_item(set<int> &s){
    int num = 98;
    auto it = s.find(num);

    if (it != s.end())
    {
        s.erase(num);
    }
    else
    {
        cout << " not exits" << "\n";
    }

    s.erase(78);
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

    delete_item(s);
     printt(s);
}