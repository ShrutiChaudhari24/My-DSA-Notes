# include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums){
    // brute force approch TC := O(N cube)
 
        // int n = nums.size();

        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         if(nums[i] < nums[j]){
        //             for(int k = j+1; k < n; k++){
        //                 if(nums[k] > nums[j] && nums[k] > nums[i]){
        //                     return true;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return false; 
        int first = INT_MAX;
        int second = INT_MAX;

        for(auto it : nums){
            if(it <= first){
                first = it;
            }
            else if(it <= second){
                second = it;
            }
            else{
                return true;
            }
        }
        return false;
    }



int main(){
    string s;
    getline(cin,s);

    vector <int> arr;

    if(s.front() == '[' && s.back() == ']'){
        s = s.substr(1, s.length()-2); 
    }

    stringstream ss(s);
    string temp;

    while(getline(ss,temp,',')){
        int num = stoi(temp);
        arr.push_back(num);
    }

    bool ans = increasingTriplet(arr);
    cout << ans;


    return 0;
}