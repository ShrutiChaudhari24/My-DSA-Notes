# include <bits/stdc++.h>
using namespace std;

void countFrequencyOfArrayElement(int arr[],int n){
    unordered_map <int, int> mpp;

    // array pae traverse kiya array ka har element map mae insert karte gaye 
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;  //ye key ki corresponding value ka count ++ ho raha hai ye mat samajhna ki key ki value ++ ho rahi hai 
    }

    cout << "Element" << " -> " << "Frequency" << endl;
    for(auto it : mpp){
        cout << it.first << " -> " << it.second << endl; 
    }


}

int main(){
    int arr[] ={1, 2, 3, 2, 1, 3, 2, 2, 1, 2};
    int n = 10; 

    countFrequencyOfArrayElement(arr, n);
    return 0; 
   
}