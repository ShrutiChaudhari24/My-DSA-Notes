# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector <int> ans;

    for(int i = 1; i * i <= n; i++){  // TC := O(N) SC := O(1)
        if(n % i == 0){
            ans.push_back(i);
            if(n/i != i){ // the another number
                ans.push_back(n/i);
            }
        }
    }

    for(auto it : ans){
        cout << it << " ";
    }


    return 0;
}