#include<bits/stdc++.h>
using namespace std;

int sum(int n) {
    if (n > 0){ 
        return n + sum(n - 1);  // Recursive call to calculate sum
    } else {
        return 0;  
    }
}

int main()
{
    int n; cin>>n; cout<<sum(n);
    return 0;
}