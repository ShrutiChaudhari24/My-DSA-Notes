# include <bits/stdc++.h>
using namespace std;

// brute force approch 
vector <int> rearrange(vector <int> &arr){
    int n  = arr.size();
    vector <int> pos;
    vector <int> neg;

    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    for(int i = 0; i < n/2; i++){
        arr[i*2] = pos[i];
        arr[i*2 +1] = neg[i];
    }
    return arr;
}

vector<int> rearrangeArray(vector<int>& nums) {
        // optimal approch TC := O(N) we will do in single pass SC := O(N)
        int pos = 0; 
        int neg = 1;
        int n = nums.size();
        int i = 0; 
        vector <int> ans(n);

        while(i < n){
            if(nums[i] >= 0){
                ans[pos] = nums[i];
                pos = pos + 2;
            }else{
                ans[neg] = nums[i];
                neg = neg + 2;
            }
            i++;
        }
        return ans;
    }

    // if number of positives and negatives are not equal then in this case there are 2 possibilities ie
    //  number of of positives are greater than number of negatives and 2nd number of positives are less than number of negatives
    vector <int> alternateNumbers (vector <int> &a){
        vector <int> pos, neg;
        int n = a.size();

        for(int i = 0; i < n; i++){
            if (a[i] > 0){
                pos.push_back(a[i]);
            }else{
                neg.push_back(a[i]);
            }
        }

        if(pos.size() > neg.size()){
            for(int i = 0; i < neg.size(); i++){
                a[2*i] = pos[i];
                a[2*i + 1] = neg[i];
            }
            int index = neg.size()*2;
            for(int i = neg.size(); i < pos.size(); i++){
                a[index] = pos[i];
                index++;
            }
        }
        else{
            for(int i = 0; i < pos.size(); i++){
                a[2*i] = pos[i];
                a[2*i + 1] = neg[i];
            }
            int index = pos.size()*2;
            for(int i = pos.size(); i < neg.size(); i++){
                a[index] = neg[i];
                index++;
            }
        }
        return a;
    } 

int main(){
    vector <int> arr = {3, 1, -2, -5, 2,-4};
    vector <int> brr = {3, 1, -2, -5, 7, 1, 9, -10, 2, -4};

    // vector <int> ans = rearrange(arr);
    vector <int> ans1 =  rearrangeArray(arr);
    vector <int> ans2 = alternateNumbers (brr);

    for(auto it : ans1){
        cout << it << " ";
    }cout << endl;

     for(auto it : ans2){
        cout << it << " ";
    }cout << endl;

    return 0;
}