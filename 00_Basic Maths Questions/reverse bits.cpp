# include <bits/stdc++.h>
using namespace std;

int reverse_bits(int n){
    unsigned int result = 0;

    for(int i = 0; i < 32; i++){
        result = result << 1;   // shift result left
        result = result | (n & 1); // take last bit of n
        n = n >> 1;              // shift n right
    }
    return result;
}

int main(){
    int n;
    cin >> n;

    int ans = reverse_bits(n);

    cout << ans;   
    // i/p := 43261596 o/p := 964176192
    return 0;
}