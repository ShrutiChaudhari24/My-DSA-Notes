# include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int i; // the bit we want to set 
    cin >> i;

    N = N | (1 << i);

    cout << N << endl;
    return 0;
}

