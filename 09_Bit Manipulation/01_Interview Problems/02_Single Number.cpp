// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

# include <bits/stdc++.h>
using namespace std;
 
int SingleNum(vector <int> &nums){
    int ans = nums[0];
    for(int i = 1; i < nums.size(); i++){
        int ans = ans ^ nums[i];
    }
    return ans;
}

int main(){
    string s;
    getline (cin,s);

    if(s.front() == '[' && s.back() == ']'){
        s = s.substr(1, s.length()-2);
    }
    vector <int> nums;

    stringstream ss(s);
    string temp;

    while(getline(ss,temp,',')){
        int num = stoi(temp);
        nums.push_back(num);
    }

    int ans = SingleNum(nums);

    cout << ans << endl;

    return 0;
}