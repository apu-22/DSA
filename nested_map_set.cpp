#include <bits/stdc++.h>
using namespace std;

void nst_map();
void nst_map_set();

int main()
{
    // nst_map();
    nst_map_set();
}

void nst_map()
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

void nst_map_set()
{
    map<int, set<string>> mark_S;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        int mrk;
        cin >> mrk;

        mark_S[mrk].insert(name);
    }

    auto cnt_it = --mark_S.end();
    while (true)
    {
        auto &student_name = (*cnt_it).second;
        int mark = (*cnt_it).first;

        for (auto &student : student_name)
        {
            cout << student << "-> " << mark;
        }
        cout << "\n";

        if (cnt_it == mark_S.end())
            break;
        cnt_it--;
    }
}