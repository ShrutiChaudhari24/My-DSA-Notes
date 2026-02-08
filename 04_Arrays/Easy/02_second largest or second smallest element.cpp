# include <bits/stdc++.h>
using namespace std;

int secondLargest(vector <int> &arr, int n){
    int largest = arr[0];
    int sLargest = INT_MIN;

    for (int i = 1; i < n; i++){
        if(arr[i] > largest){
            sLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > sLargest){
            sLargest = arr[i];
        }
    }
    return sLargest;
}

int secondSmallest(vector <int> &arr, int n){
    int smallest = arr[0];
    int sSmallest = INT_MAX;

    for(int i = 1; i < n; i++){
        if(arr[i] < smallest){
            sSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] > smallest && arr[i] < sSmallest){
            sSmallest = arr[i];
        }
    }
    return sSmallest;
}

int main(){
    vector <int> arr = {5, 9, 1, 8, 24};
    int n = arr.size();

    int sLargest = secondLargest(arr, n);
    int sSmallest = secondSmallest (arr, n);

    vector <int> ans = {sLargest, sSmallest};

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;
}