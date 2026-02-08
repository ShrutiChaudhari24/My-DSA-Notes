# include <bits/stdc++.h>
using namespace std;

int largestElement(int* arr, int n){  //int arr[] ease likho ya int * arr baat ek hi hai
    int large = INT_MIN;

    for(int i = 0; i < n; i++ ){
        if(large < arr[i]){
            large = arr[i];
        }
    }
    return large;
}


int main(){
    int n;
    cout << "Enter the size of the array := ";
    cin >> n;
    int arr[n];
    cout << "Enter the Elements in the array := " << endl;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }cout << endl;

    int large = largestElement(arr, n);

    cout << "Largest element is := " << large;

    return 0; 
}