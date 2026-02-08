# include <bits/stdc++.h>
using namespace std;

// brute force approch 
vector <int> rearrange(vector <int> &arr){
    int n  = arr.size();
    vector <int> pos;
    vector <int> neg;

    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    for(int i = 0; i < n/2; i++){
        arr[i*2] = pos[i];
        arr[i*2 +1] = neg[i];
    }
    return arr;
}

int main(){
    vector <int> arr = {3, 1, -2, -5, 2,-4};

    vector <int> ans = rearrange(arr);

    for(auto it : ans){
        cout << it << " ";
    }cout << endl;

    return 0;
}