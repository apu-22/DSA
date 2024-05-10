#include<bits/stdc++.h>
using namespace std;

int sum(int n) {
    if (n > 0){ 
        return n + sum(n - 1);  // Recursive call to calculate sum
    } else {
        return 0;  
    }
}
void rev() {
    char ch;
    cin.get(ch);  // Read a character from input

    if (ch != '\n') {
        rev();  // Recursively call rev() until newline is encountered

        // Print character after recursive call to reverse the order
        cout << ch;
    }
}

int main()
{
    int n; cin>>n; cout<<sum(n)<<endl;

    // reverse charecter
    cin.ignore();
    rev();
    return 0;
}