# include <bits/stdc++.h>
using namespace std;

vector <int> nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return nums;
        }

        for(int i = n-1; i >=0; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1 ,nums.end());
        return nums;
    }
int main(){
    int size;
    cin >> size;

    vector <int> nums(size);

    for(int i = 0; i < size; i++){
        cin >> nums[i];
    }

    vector <int> ans = nextPermutation(nums);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}
