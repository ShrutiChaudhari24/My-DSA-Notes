# include <bits/stdc++.h>
using namespace std;

vector <int> leftRotateByKPlaces1(vector <int> & nums, int n, int k){
    // brute force approch

    vector <int> temp;
    // step 1 :- jitni k ki value hai humey utne elements phele store kar lene honge kisi temp array mae
    for(int i = 0; i < k; i++){
        temp.push_back(nums[i]);
    }

    // step 2 :- baki elements ko left mae sarka doo
    for (int i = k; i < n; i++){
        nums[i - k] = nums[i];
    }

    // jo temp mae dale thae unko piche dalna hai wapis array mae tho putback karne honge 
    for (int i = n-k; i < n; i++){
        nums[i] = temp[i - (n-k)];
    }

    return nums;

}

vector <int> leftRotateByKPlaces2(vector <int> & nums, int n, int k){
    // optimal approch 
    // ye approch observation sae aayegi

    reverse (nums.begin(), nums.begin()+k);

    reverse(nums.begin()+k, nums.end());

    reverse(nums.begin(), nums.end());

    return nums;
}


void print (vector <int>& nums, int n){
     for (int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }cout << endl;
}

int main(){
    vector <int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    int k = 3;

    print(nums, n);
    // leftRotateByKPlaces1(nums, n, k);
    // print(nums,n);
   
    leftRotateByKPlaces2(nums, n, k);
    print(nums, n);
}