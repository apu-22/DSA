#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int>q;

    q.push(3);
    q.push(2);
    q.push(6);
    q.push(9);

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
}