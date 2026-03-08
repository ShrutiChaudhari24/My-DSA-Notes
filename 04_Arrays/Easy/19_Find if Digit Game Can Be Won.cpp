# include <bits/stdc++.h>
using namespace std;

bool canAliceWin(vector<int>& nums) {
        int single_DigSum = 0;
        int double_DigSum = 0;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] <= 9){
                single_DigSum = single_DigSum + nums[i];
            }else{
                double_DigSum = double_DigSum + nums[i];
            }
        }

        if(single_DigSum == double_DigSum){
            return false;
        }else{
            return true;
        }
}

int main(){
    int n;
    cin >> n;

    vector <int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int result = canAliceWin(nums);
    cout << (result ? "true" : "false") << endl;
    
    return 0;
}