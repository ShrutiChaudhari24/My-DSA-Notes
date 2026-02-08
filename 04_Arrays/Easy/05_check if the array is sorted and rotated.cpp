# include <bits/stdc++.h>
using namespace std;

bool CheckSortedAndRotated (vector <int>& nums, int n){
    int breakcount = 0;
    for (int i = 0; i < n-1; i++){
        if(nums[i] > nums[i+1]){
            breakcount++;
        }
    }

    // last element kae liye alag sae check karna pedega
    if(nums[n-1] > nums[0]){
        breakcount++;
    } 

    return(breakcount <= 1);
}

int main(){

    vector <int> nums = {3,4,5,1,2};

    int n= nums.size();

    bool isValid = CheckSortedAndRotated(nums, n); 
    cout << isValid;

    return 0;
}
