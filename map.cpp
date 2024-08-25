#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

void delete_key(map<int, string> &student)
{

    auto it = student.find(3);
    if (it != student.end())
    {
        student.erase(3);
    }
}

void find(map<int, string> &student)
{
    auto it = student.find(4);
    if (it != student.end())
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    else
    {
        cout << "No Value" << endl;
    }
}

void print(map<int, string> &student)
{
    // cout << student.size() << endl;
    // for (auto p : student)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }

    // for (int i = 1; i <= student.size(); i++)
    // {
    //     cout << "student[" << i << "]:" << student[i] << endl;
    // }

    map<int, string>::iterator iter;
    for (iter = student.begin(); iter != student.end(); iter++)
    {
        cout << (*iter).first << ':' << (*iter).second << "\n";
    }
}

int main()
{
    map<int, string> student{{1, "apu"}, {2, "lb"}};

    student[3] = "konock";
    student[4] = "rojo";

    student.insert(make_pair(5, "catherine"));

    delete_key(student);
    find(student);
    print(student);

    cout<<"\n";

    // frequency calculate of an array
    int n, value = INT_MIN;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // for (auto pr : a)
    // {
    //     cout <<pr << " ";
    // }

    unordered_map<int, int> freq;
    // for (int i = 0; i < n; i++)
    // {
    //     freq[a[i]]++;
    // }

    for (int num : a)
    {
        freq[num]++;
    }

    // unordered_map<int, int>::iterator it;
    for (const auto &pr : freq)
    {
        cout << pr.first << " :" << pr.second << "\n";
        value = max(value, pr.second);
    }
}