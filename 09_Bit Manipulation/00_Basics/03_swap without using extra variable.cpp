# include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a;
    cin >> b;

    a = a ^ b; // step 1 
    b = a ^ b;  // now a = (a ^ b) ^ b => a 
    a = a ^ b;  // a = (a ^ b) ^ a => b

    cout << a << endl;
    cout << b << endl;

}