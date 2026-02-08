# include <bits/stdc++.h>
using namespace std;

void leftRotate (vector <int>& nums, int n){
    // first element ko end mae dalna hoga tho phele uss ko kahi store kar lo aur aage wale elements ko shift kardoo left

    // store first element
    int first = nums[0];

    // shift the remaining elements
    for (int i = 1; i < n; i++){
        nums[i-1] = nums[i];
    }

    // then reput the first element to the end
    nums[n-1] = first;

}

void print (vector <int>& nums, int n){
     for (int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }cout << endl;
}

int main(){
    vector <int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();

    print(nums, n);
    leftRotate(nums, n);
    print(nums,n);
   
}