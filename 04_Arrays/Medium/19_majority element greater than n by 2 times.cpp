# include <bits/stdc++.h>
using namespace std;

int majorityElement (vector <int>& arr, int n){
    // brute force approch TC := O(N square) / SC := O(N)
    // for(int i = 0; i < n; i++){
    //     int count = 0;
    //     for(int j = 0; j < n; j++){
    //         if(arr[j] == arr[i]){
    //             count++;
    //         }
    //     }
    //     if(count > n/2){
    //         return arr[i];
    //     }
    // }
    // return -1;

    // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // better approch TC := O(N logN + N) SC:= O(N)
    // map <int, int> mpp;

    // for(int i = 0; i < n; i++){
    //     mpp[arr[i]]++;
    // }

    // for(auto it : mpp){
    //     if(it.second > n/2){
    //         return it.first;
    //     }
    // }
    // return -1;

    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // optimal approch :- Moore's voting algorithm TC :- O(2N) SC :- O(1) 
    int count = 0;
    int element ;

    for(int i = 0; i < n; i++){
        if(count == 0){
            count = 1;
            element = arr[i];
        }
        else if(arr[i] == element){
            count++;
        }
        else{
            count--;
        }
    }

    // verification that the element we got is majority element or not
    int count1 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == element){
            count1++;
        }
        if(count1 > n/2){
            return element;
        }
    }
    return -1;
}

int main(){
    
    vector <int> arr = {2, 2, 3, 3, 1, 2, 2};
    int n = arr.size();

    int ans = majorityElement(arr, n);
    cout << ans ;

    return 0;
}