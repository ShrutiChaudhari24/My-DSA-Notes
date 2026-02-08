# include <bits/stdc++.h>
using namespace std;


    void helper(int arr[], int n, int start, int end){

        // base case
        if (start >= end){
            return ;
        }
        
        swap(arr[start],arr[end]);
        start++;
        end--;
        helper(arr, n, start, end);
        
    }
    

    void reverse(int arr[], int n){

        int start = 0;
        int end = n-1;
        
        helper(arr, n, start, end);

        
    }

    int main(){
        int arr[] = {1,2,3,4,5};

        reverse(arr,5);
        int n = 5;

        for(int i = 0; i<n; i++){
            cout << arr[i] << " ";
        }
    }

