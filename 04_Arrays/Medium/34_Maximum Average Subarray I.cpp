#include <bits/stdc++.h>
using namespace std;

// brute force approch
double findMaxAverage(vector<int>& nums, int k) { // TC := O(N square)
        int n = nums.size();
        double maxSum = INT_MIN;

        for(int i = 0;  i <= n-k; i++){
            int sum = 0;
            for(int j = i; j < i + k; j++){
                sum = sum + nums[j];
            }
            maxSum = max(maxSum, (double)sum);
        }
        return maxSum / k;
    }


// optimal approch
 double findMaxAverage2(vector<int>& nums, int k) { // TC := O(N)
        int n = nums.size();
        int sum = 0;
        // calculate initial sum
        for(int i = 0; i < k; i++){
            sum = sum + nums[i];
        }
        int maxSum = sum;

        // initially declare window contain sum of first k elements so initially first we have to  delete the first element and add kth element (as array starts from 0) and we have to do this process till we reach to the window which contain last element
        int startIndex = 0;
        int endIndex = k;

        while(endIndex < n){
            // remove the previous element
            sum = sum - nums[startIndex];
            startIndex++;

            // add next element
            sum = sum + nums[endIndex];
            endIndex++;

            maxSum = max(maxSum,sum);
        }
        return (double)maxSum / k;
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
    
    int ans = findMaxAverage(nums,k);
    int ans1 = findMaxAverage2(nums,k);

    cout << ans << endl;
    cout << ans1 << endl;

    return 0;
}