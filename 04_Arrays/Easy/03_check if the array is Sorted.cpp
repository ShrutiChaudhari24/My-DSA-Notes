# include <bits/stdc++.h>
using namespace std;

bool check (vector <int> &arr, int n){
    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
}

int main(){

    vector <int> arr = {5, 10, 17, 19, 24};
    vector <int> brr = {14, 16, 78, 9, 10, 0, 1};
    int n = arr.size();
    int n2 = brr.size(); 

    bool ans = check(arr, n); 
    bool ans2 = check(brr, n2);

    cout << "Is the Array Sorted := " << ans << endl;
    cout << "Is the Array Sorted := " << ans2;

    return 0;
}