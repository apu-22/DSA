#include <bits/stdc++.h>
using namespace std;

int main() {
  queue<int> s;
  for(int i=0;i<6;i++)
  {
    s.push(i);
  }

    //  cout<< s.size()<<endl;
    //  cout<<s.front()<<endl;
    //  s.pop();
    //  cout<<s.front()<<endl;

  while (!s.empty()) {
    cout << s.front() << endl;
    s.pop();
  }
}
