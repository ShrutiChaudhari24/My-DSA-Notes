// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.

# include <bits/stdc++.h>
using namespace std;

vector <int> SingleNumber(vector <int>& nums){ // TC := O(N) + O(1) + O(N) = (2N) at worst case it will be O(n square) 
    // TC = O(n) + O(n) = O(n)  in worst case O(N square)
        // SC = O(n) because of map
        int n = nums.size();
        vector <int> ans;
        unordered_map <int,int> mpp;

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            if (it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }

    // optimal approch using bitwise operator
    vector <int> SingleNumber2(vector <int>& nums){ // TC := O(N) + O(1) + O(N) = (2N)
        // SC = O(1) because not using ay external data structure
        int n = nums.size();
        long long xorr = 0;

        for(int i = 0; i < n; i++){
            xorr = xorr ^ nums[i];
        }
        
        int rightmost = xorr & (-xorr);
        int b1 = 0,  b2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] & rightmost){
                b1 = b1 ^ nums[i];
            }else{
                b2 = b2 ^ nums[i];
            }
        }
        return {b1, b2};
        }



int main(){
    int n ;
    cin >> n;

    vector <int> nums(n);

    for(int i = 0;  i < n; i++){
        cin >> nums[i];
    }

    vector <int> ans = SingleNumber(nums);

    vector <int> ans2 = SingleNumber2(nums);

    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
     for(auto it : ans2){
        cout << it << " ";
    }

    return 0;
}