# include <bits/stdc++.h>
using namespace std;

int No_OfSetbits1(int N){
    int cnt1 = 0;

    while(N > 1){
        cnt1 = cnt1 + (N & 1);
        N = N >> 1;
    }
    if(N == 1) cnt1 += 1;
    
    return cnt1;
}


int No_OfSetbits(int N){
    int cnt = 0;

    while(N != 0){
        N = N & (N-1);
        cnt++;
    }
    return cnt;
}


int main(){
    int N;
    cin >> N;

    // this is the buildin c++ stl lib to count the number of set bits
    int count = __builtin_popcount(N);
    cout << count << endl;

    // function to count the number of set bits
    int cnt = No_OfSetbits(N);
    cout << cnt << endl;

    int cnt1 = No_OfSetbits1(N);
    cout << cnt1 << endl;



    return 0;
}