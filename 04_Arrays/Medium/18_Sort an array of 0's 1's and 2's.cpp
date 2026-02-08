# include <bits/stdc++.h>
using namespace std;

void Sort012(vector <int> & nums, int n){

    // brute force approch - use any sorting algo like merge sort etc TC := O(N logN) SC:= O(N)
    //     sort(nums.begin(), nums.end());

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // better approch TC:= O(2N) SC:= O(1)
    // int count0 = 0, count1 = 0, count2 = 0;
    // for(int i = 0; i < n; i++){
    //     if(nums[i] == 0){
    //         count0++;
    //     }
    //     else if(nums[i] == 1){
    //         count1++;
    //     }
    //     else{
    //         count2++;
    //     }
    // }

    // for(int i = 0; i < count0; i++){
    //     nums[i] = 0;
    // }
    // for(int i = count0; i < count0+count1; i++){
    //     nums[i] = 1;
    // }
    // for(int i = count0+count1; i < n; i++){
    //     nums[i] = 2;
    // }
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // // optimal approch :- Deatch National flag algorithm TC := O(N) SC := O(1)
        int low = 0; int mid = 0; int high = n-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
}

void print (vector <int>& nums, int n){
    for(int i = 0; i < n; i++){
        cout << nums[i] <<" ";
    }cout << endl;
}


int main(){
    vector <int> nums = {0, 1, 1, 1, 0, 2, 0, 2, 2, 1, 2, 0, 0};
    int n = nums.size();

    cout << "before Sorting ";
    print(nums, n);

    cout <<"After Sorting ";
    Sort012(nums, n);
    print(nums, n);
    return 0;
}