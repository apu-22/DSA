#include <bits/stdc++.h>
using namespace std;

int main() {
  queue<int> s;
  s.push(5);
  s.push(2);
  s.push(1);
  s.push(9);
  s.push(6);
  s.push(7);

     cout<< s.size()<<endl;
     cout<<s.front()<<endl;
     s.pop();
     cout<<s.front()<<endl;

  while (!s.empty()) {
    cout << s.front() << endl;
    s.pop();
  }
}
