# include <iostream>
using namespace std;

void insertionSort (int* arr, int n){
    for(int i = 0; i <= n-1; i++){ // ye wala loop comapre karne kae liye 

        int j = i;

        while(j > 0 && arr[j-1] > arr[j]){  // ye wala shift karne kae liye 

            swap(arr[j-1], arr[j]);
            j--; 
        }
    }
}

void printArray (int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    
    int arr [6] = {24, 4, 29, 6, 5, 5};
    int n = 6;

    insertionSort (arr, n);
    printArray(arr, n);
    

    return 0;
}