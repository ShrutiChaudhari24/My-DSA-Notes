# include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    if(x < 2) return false;

    for(int i = 2; i*i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    vector <int> ans;

/*for(int i = 2; i*i <= n; i++){
        if(n % i == 0){ // ager number factor hai 
            if(isPrime(i)){ // aur only if it is prime then only it is pushed into ans
                ans.push_back(i);
            }

            if(n/i != i && isPrime(n/i)){  // if i is factor and n/i == i the no need to push it into the and only just push i
                ans.push_back(n/i);
            }
        }
    }

    // egde case ager koi number already ek prime number hai tho uss ka factor or prime factor tho vo number itself hi hoga n 
    if(ans.empty()){
        if(isPrime(n)){
            ans.push_back(n);
        }
    } 

    for(auto it : ans){
        cout << it << " ";
    }
*/
    //  optimal approch to print all the prime factors
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
        ans.push_back(i);
        }

        while(n % i == 0){
        n = n /i;
        }
    }

    if(n > 1) ans.push_back(n);
    
    for(auto it : ans){
        cout << it << " ";
    }

    return 0;
}