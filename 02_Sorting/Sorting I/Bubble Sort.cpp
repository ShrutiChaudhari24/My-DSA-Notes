// TC Avg and worst case O(n^2) best case O(n)
# include <iostream>
using namespace std;

void bubbleSort(int* arr , int n){
    bool isSwapped = false;

    for (int i = n-1; i >= 1; i--){// n-1 rounds chalenae hai 

        for(int j = 0; j <= i-1; j++){// index 0 sae lae kar index i-1 tak hi compare karna hai kyoki uss kae baad j+1 hoga hi nahi tho kis ko swap karoge arr[j] ko 
                                                        // elements compare up to i-1 to prevent out of bounds.
            if(arr[j] > arr[j+1]){
                swap (arr[j], arr[j+1]);
                isSwapped = true;
            }
        }

        if(isSwapped == false){
            break;
        }

    }
}

void printArray (int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}
int main(){

    int arr[6] = {64, 25, 12, 22, 11, 45};

    bubbleSort (arr, 6);

    printArray (arr, 6);

    return 0;
}