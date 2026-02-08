# include <bits/stdc++.h>
using namespace std;

int partition (vector <int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j){

        // move i right until an element less than or equal to pivot is found
        while(arr[i] <= pivot && i <= high -1){
            i++;
        }

        // move j left until an element greater to pivot is found
        while(arr[j] > pivot && j >= low +1){
            j--;
        }

        // swap wrong side elements
        if (i < j){
            swap (arr[i], arr[j]);
        }
    }
        // Place pivot in its correct position
        swap(arr[low], arr[j]);
        return j;  // pivot index
}

void quickSort (vector <int>& arr, int low, int high){    
    if (low < high){
        int pIndex = partition (arr, low, high);
        quickSort (arr, low, pIndex-1);
        quickSort (arr, pIndex+1, high);
    }
}

void printArray (vector <int>& arr, int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    vector <int> arr = {3, 4, 1, 11, 5, 5, 19, 4, 8, 24};
    int n = arr.size();

    cout << "Array before sorting := ";
    printArray (arr, n);

    quickSort(arr, 0, n-1);

    cout << "Array After sorting := ";
    printArray(arr, n);
    return 0;
}

