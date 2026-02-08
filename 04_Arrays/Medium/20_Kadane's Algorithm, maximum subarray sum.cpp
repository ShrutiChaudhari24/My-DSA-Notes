# include <bits/stdc++.h>
using namespace std;

int MaximumSubArraySum (vector <int>& arr, int n){
    // brute force approch TC := O(N cube) SC:= O(1)
    // int maxi = INT_MIN;

    // for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++){
    //         int sum = 0;

    //         for(int k = i; k <= j; k++){
    //             sum += arr[k];
    //         }
    //         maxi = max(sum, maxi);
    //     }
    // }
    // return maxi;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // better approch TC := O(N square) SC := O(1)
    // int maxi = INT_MIN;
    // for(int i = 0; i < n; i++){
    //     int sum = 0;
    //     for(int j = i; j < n; j++){
    //         sum += arr[j];
    //         maxi = max(sum, maxi); 
    //     }
    // }
    // return maxi;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // optimal approch kadane's algorithm TC := O(N) SC:= O(1)
    int maxi = INT_MIN;
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
}

int main(){

    vector <int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n  = arr.size();

    int maxSum = MaximumSubArraySum (arr, n);
    cout << maxSum;
    return 0;
}