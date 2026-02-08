# include <bits/stdc++.h>
using namespace std;

int onceOccurence (vector <int>& arr, int n){
    int ans = 0;

    for (int i = 0; i < n; i++){
        ans = ans ^ arr[i];
    }

    return ans;
}
int main(){
    vector <int> arr = {1, 4, 2, 1, 4, 5, 5};
    int n = arr.size();

    int single_number = onceOccurence(arr, n); 

    cout << "the number that appears once is :=  " << single_number;
    return 0;
}
    