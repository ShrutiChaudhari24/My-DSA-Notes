# include <bits/stdc++.h>
using namespace std;

double myPow (int x, int n){
    double ans = 1.0;
    long long N = n;
    
    if(N < 0){
        N = -1 * n;
    }

    while(N){
        if(N % 2 == 1){
            ans = ans * x;
            N = N - 1;
        }
        else{
            x = x * x;
            N = N / 2;
        }
    }
    if(n < 0) {
        ans = (double) 1.0 / (double) ans;
    }
    return ans;
}

int main(){
    double x; // base
    cin >> x;

    int n; // n is power 
    cin >> n;

    double ans = myPow(x, n);

    cout << ans << endl;

    return 0;
}