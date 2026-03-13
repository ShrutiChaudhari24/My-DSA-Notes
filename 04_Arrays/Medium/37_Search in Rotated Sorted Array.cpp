# include <bits/stdc++.h>
using namespace std;
int binarySearch(vector <int>& nums, int start, int end, int target){
    // int mid = start + ((end - start)/2) ;//integer overflow na ho es liye ye kiya  //  int mid = ((start + end)/2); 
    int mid = ((start + end) >> 1);

    while(start <= end){
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }

        mid = (start + end) >> 1;
    }
    return -1;
}
int search (vector <int>& nums, int target){
    int n = nums.size();
    int pivot = -1;

    // step 1 := find pivot 
    for(int i = 0; i < n-1; i++){
        if(nums[i] > nums[i+1]){
            pivot = i;
            break;
        }
    }

    // if array is not rotated tho directly binary search sae laga doo
    if(pivot == -1); // ie if still pivot value is -1 ie array is not rotated
    return binarySearch(nums, 0, n-1, target); 

    // if target is in second half
    if(target >= nums[0]){
        return binarySearch(nums, 0, pivot, target);
    }

    // abb tho ek hi condition remaining hai ki target is in right half
    return binarySearch(nums, pivot+1, n-1, target);
}

int main(){
    string s;
    getline(cin,s);

    vector<int> nums;

    if(s.front() == '[' && s.back() == ']'){
        s = s.substr(1,s.length()-2);
    }

    string temp;
    stringstream ss(s);
    while(getline(ss,temp,' ')){
        int num = stoi(temp);
        nums.push_back(num);
    }

    int target;
    cout << "Enter the value you want to search := " << endl;
    cin >> target;

    int ans = search(nums,target);

    cout << ans << endl;

    return 0;
}