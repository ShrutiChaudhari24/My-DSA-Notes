# include <bits/stdc++.h>
using namespace std;

long reverseBits(int n){
    long result = 0;

    for(int i = 0; i < 32; i++){
        result = (result << 1) | (n & 1);
        n = n >> 1;
    }
}
int main(){
    int n;
    cin >> n;

    long ans = reverseBits(n);

    cout << ans;

    return 0;
}