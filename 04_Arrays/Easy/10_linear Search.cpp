# include <bits/stdc++.h>
using namespace std;

bool linearSearch (vector <int>& arr, int target){
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == target){
            return true;
        }
    }
    return false;
}

int main(){
    vector <int> arr = {1, 2, 3, 4, 5, 8, 10};
    int target = 400;
    
    bool isfound = linearSearch (arr, target);    
    cout << isfound; 
}
