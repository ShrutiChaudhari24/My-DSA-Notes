#include <bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n-1;
        int count = 0;

        while(i < j){
            if(nums[i] + nums[j] == k){
                count++;
                i++;
                j--;
            }
            else if(nums[i] + nums[j] < k){
                i++;
            }
            else{
                j--;
            }
        }
        return count;
}
int main(){
    string s;
    getline(cin,s);

    if(s.front() == '[' &&  s.back() == ']'){
        s = s.substr(1, s.length()-2);
    }

    vector <int> nums;

    string temp;
    stringstream ss(s);

    while(getline(ss,temp,',')){
        int num = stoi(temp);
        nums.push_back(num);
    }

    int k;
    cin >> k;   // take k as input

    int ans = maxOperations(nums, k);

    cout << ans << endl;
  
    
    return 0;
}