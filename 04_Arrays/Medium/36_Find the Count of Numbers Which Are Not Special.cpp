# include <bits/stdc++.h>
using namespace std;

// but this approch gives TLE
bool divisorCount(int n){
    int divisorCount = 0;

    for(int i = 1; i < n; i++){
        if(n % i == 0){
            divisorCount++;
        }
    }
    if(divisorCount == 2){
        return true;
    }else{
        return false;
    }
}

int nonSpecialCount(int l, int r) {
    int nonSpecialCount = 0;
    for(int i = l; i <= r; i++){
        if(!divisorCount(i)){
            nonSpecialCount++;
        }
    }
    return nonSpecialCount;
}

//  optimal approch 
    int nonSpecialCount1(int l, int r) {
        int limit = sqrt(r);
        vector <bool> prime(limit+1, true);
        prime[0] = prime[1] = false;

        for(int i = 2; i * i <= limit; i++){
            if(prime[i]){
                for(int j = i * i; j <= limit; j = j + i){
                    prime[j] = false;
                }
            }
        }

        int special = 0;

        for(int i = 2; i <= limit; i++){
            if(prime[i]){
                long long sq = 1LL * i * i;
                if(sq >= l && sq <= r){
                    special++;
                }
            }
        }
        return (r - l + 1) - special;
    }

int main(){
    int l;
    cin >> l;
    int r;
    cin >> r;

    int non_SpecialCount = nonSpecialCount(l, r);

    int non_SpecialCount1 = nonSpecialCount1(l, r);

    cout << non_SpecialCount << endl;
    cout << non_SpecialCount1 << endl;




    return 0;
}