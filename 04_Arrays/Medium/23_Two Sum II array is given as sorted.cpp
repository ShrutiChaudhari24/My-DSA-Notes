# include <bits/stdc++.h>
using namespace std;

vector <int> twoSum (vector <int>& arr, int target){
    int start = 0;
    int end = arr.size() - 1;

    while(start < end){
        if(arr[start] + arr[end] == target){
            return {start, end};    // {start+1, end+1} if 1 based indexing ans we want
        }
        else if (arr[start] + arr[end] < target){
            start++;
        }
        else {
            end--;
        }
    }
    return {-1,-1};
}

int main(){

    // vector <int> arr = {2, 7, 11, 15};
    vector <int> arr = {2, 3, 4};

    vector <int> ans = twoSum (arr, 6);

    for(auto it : ans){
        cout << it << " " ;
    }cout << endl;

    return 0;
}