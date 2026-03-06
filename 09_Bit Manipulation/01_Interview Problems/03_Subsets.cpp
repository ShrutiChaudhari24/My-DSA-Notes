# include <bits/stdc++.h>
using namespace std;
vector <vector <int>> subsets(vector<int>& nums){
    int n = nums.size();
    int subsets = 1 << n;  // number of subsets

    vector <vector <int>> ans;

    for(int num = 0; num < subsets; num++) { // because we want to go from 0 to (2 power n) -1
        vector <int> subarray;

        for(int i = 0; i < n; i++){
            if((num & (1 << i)) != 0){
                subarray.push_back(nums[i]);
            }
        }
        ans.push_back(subarray);
    }

    return ans;

}
int main(){
    int n;
    cin >> n;

    vector <int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector <vector <int>> ans = subsets (nums);

    for(auto it : ans){
        cout << "[ ";
        for(auto x : it){
            cout << x << " ";
        }
        cout << "]";
    }

    return 0;
}