// Seive of Erathosthenes 

# include <bits/stdc++.h>
using namespace std;

int  CountPrimes(int n){
    int count = 0;

    vector <bool> prime(n+1, true);

    prime[0] = prime[1] = 0;
    
    for(int i = 2; i < n; i++){

        if(prime[i] == 1){
            count++;
        }

        for(int j = 2 * i; j < n; j = j + i){
            prime[j] = 0; 
        }
    }
    return count;
}



int main(){
    int n ;
    cin >> n;

    int count = CountPrimes(n);

    cout << count << endl;

    return 0;
}
