# include <bits/stdc++.h>
using namespace std;

vector <int> TwoSum1 (vector <int> &nums, int n, int target){
    // brute force 
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if(nums[i] + nums[j] == target){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector <int> TwoSum2 (vector <int> &nums, int n, int target){
    // better approch using hashing
    map <int, int> mpp; 
    for (int i = 0; i < n; i++){

        int num = nums[i];
        int more = target - num; 
        
        if(mpp.find(more) != mpp.end()){ // ie. key(more) is found
            return {mpp[more],i};
        }

        mpp[num] = i;
}
return {-1, -1};
}

// optimal approch for verity 1 
bool TwoSum3 (vector <int> & nums, int n, int target){
    int left = 0;
    int right = n-1;

    sort(nums.begin(), nums.end());

    while(left <= right){
        if(nums[left] + nums[right] == target){
            return true;
        }

        else if(target < nums[left] + nums[right]){
            right--;
        }

        else{
            left++;
        }
    }
    return false;
}

int main(){
    vector <int> nums = {2, 7, 11, 15};
    int n = nums.size();
    int target = 9;

    // vector <int> ans = TwoSum1(nums, n, target);
    vector <int> ans = TwoSum2(nums, n, target);
    bool ansPorN = TwoSum3(nums, n, target);



    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;

    cout << ansPorN;
    return 0;
}