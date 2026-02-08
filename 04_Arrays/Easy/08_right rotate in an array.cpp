# include <bits/stdc++.h>
using namespace std;

void RightRotateByKPlaces1(vector <int> & nums,int n,int k){
    // brute force approch

    vector <int> temp;

    // step 1 :- jo elements right mae hai equal tho the value of k ie. if k = 2 the 2 elements un ko phele kisi temp mae store karlo
    for(int i = n - k; i < n; i++){
        temp.push_back(nums[i]);
    }

    // step 2 :- baki elements ko shift right
    for (int i = 0; i < n-k; i++){
        nums[i+k] = nums[i];
    }

    // step 3 :- reput the temp elemnets to the array in front
    for (int i = 0; i < k; i++){
        nums[i] = temp[i];
    }

}

void RightRotateByKPlaces2(vector <int> & nums,int n,int k){
    // optimal approch

    reverse (nums.begin(), nums.end());

    reverse(nums.begin(), nums.begin()+k);

    reverse(nums.begin()+k, nums.end());

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
    // RightRotateByKPlaces1(nums, n, k);
    // print(nums,n);
   
    RightRotateByKPlaces2(nums, n, k);
    print(nums, n);
}