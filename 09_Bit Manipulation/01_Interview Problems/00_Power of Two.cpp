# include <bits/stdc++.h>
using namespace std;

bool isPowerof2 (int n){
    bool ans;
    
    if((n & (n-1)) == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;

    bool ans = isPowerof2(n);

    cout << (ans ? "true" : "false") << endl;


    return 0;
}