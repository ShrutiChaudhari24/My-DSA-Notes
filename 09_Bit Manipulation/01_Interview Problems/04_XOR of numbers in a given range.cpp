# include <bits/stdc++.h>
using namespace std;

// optimal approch
int xorFrom1toN (int n){
    if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n-1;
    else if(n % 4 == 3) return 0;
    else return n;
}

int main(){
    int n;
    cin >> n;

    // TC := O(N) SC := O(1)
    // int ans = 0;
    // for(int i = 0; i <= n; i++){
    //     ans = ans ^ i;
    // }

    int ans = xorFrom1toN (n);
    cout << ans << endl;

    int L , R;
    cin >> L;
    cin >> R; 
    // what if we have give 2 numbers like L and R and told to find XOR of L to R
    // TC := O(L - R + 1) SC := O(1)
    // int ans = 0;
    // for(int i = L; i <= R; i++){
    //     ans = ans ^ i;
    // }
    // cout << ans << endl; 
    ans = 0;
    // optimal approch call the above function
    ans = xorFrom1toN (L - 1) ^ xorFrom1toN (R);  // eg := L = 4; R = 7  (1 ^ 2 ^ 3) ^ ( 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 )  ultimtely it is (4 ^ 5 ^ 6 ^ 7)
    cout << ans;

    return 0;
}
