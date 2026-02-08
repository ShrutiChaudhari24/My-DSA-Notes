# include <bits/stdc++.h>
using namespace std;

int countDistinct(int arr[], int n){
    unordered_set <int> set;
   for (int i = 0; i < n; i++){
        set.insert(arr[i]);
    }

    return set.size();
}

int main(){
    int arr[5] = {1,2,1,2,4};
    int size = countDistinct(arr, 5);

    cout << size << endl;


    return 0;
}