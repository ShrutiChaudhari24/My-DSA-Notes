# include <bits/stdc++.h>
using namespace std;

int longest_Subarray_with_Sum_K1 (vector <int>& a, int n, int k){
    // brute force approch O(N square) SC O(1)
    int length = 0;
    for (int i = 0; i < n; i++){

        long long sum = 0;

        for (int j = i; j < n; j++){

            sum += a[j];

            if(sum == k){
                length = max (length, j-i+1);
            }

        }
    }
    return length;
}
    
int longest_Subarray_with_Sum_K2 (vector <int>& a, int n, int k){
    // better approch (this is the optimal approch for negative arrays as well) TC - O(N log N) SC O(N)
    map <long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for(int i = 0; i < n; i++){
        sum += a[i];

        if(sum == k){
            maxLen = max(maxLen, i+1);
        }

        long long remaining = sum - k;

        if(preSumMap.find(remaining) != preSumMap.end()){
            int len = i - preSumMap[remaining];
            maxLen = max(maxLen, len);
        }

        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
        
    }
    return maxLen;
}


int longest_Subarray_with_Sum_K3 (vector <int>& a, int n, int k){
    // this is the optimal approch but only for =VE numbers and zeros this will not work for -ve numbers 
    // for -ve numbers in array the better approch is the optimal approch 
    // TC O(2N) SC O(1)

    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;

    while (right < n){
        while(left  <= right && sum > k){
            sum -= a[left];
            left++;
        }

        if(sum == k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;

        if(right < n){
            sum += a[right];
        }
    }
    return maxLen;
}
    

int main(){

    vector <int> a = {1,2,3,1,1,1,1,4,2,3};
    int n = a.size();
    int k = 3;

    int longest_length_of_subarray1 =  longest_Subarray_with_Sum_K1 (a, n, k);
    int longest_length_of_subarray2 =  longest_Subarray_with_Sum_K2 (a, n, k);
    int longest_length_of_subarray3 =  longest_Subarray_with_Sum_K3 (a, n, k);

    cout << longest_length_of_subarray1 << endl;
    cout << longest_length_of_subarray2 << endl;
    cout << longest_length_of_subarray3 << endl;


    return 0;
}