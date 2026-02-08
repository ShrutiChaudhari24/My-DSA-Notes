# include <bits/stdc++.h>
using namespace std;

int max1Occ (vector <int>& arr, int n){
    int maxi = 0;
    int count = 0;

    for (int i = 0; i < n; i++){
        if(arr[i] == 1){
            count++;
            maxi = max(maxi, count);
        }
        else {
            count = 0;
        }
    }
    return maxi;
}

int main(){
    vector <int> arr = {1, 1, 0, 1, 1, 1, 0, 1, 0 , 1, 0, 1};
    int n = arr.size();
    
    int maximumOccurenceOfOnes = max1Occ(arr, n);

    cout << "maximum number of times one occured is := " << maximumOccurenceOfOnes << endl;  
    return 0;
}