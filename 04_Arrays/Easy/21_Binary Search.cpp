// Binary Search ki main condition array should be in sorted manner
// time complexity = O(logN)

#include <iostream>
using namespace std;

int binarySearch (int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int mid = start + ((end - start)/2) ;//integer overflow na ho es liye ye kiya  //  int mid = ((start + end)/2);    
    while(start <= end){
      
     if(arr[mid]==key){
        return mid;
     }

    //ager key badi hai arr[mid] sae go to right wala part
     else if(key > arr[mid]){
        start = mid + 1;
     }
    // matlab key choti  hai arr[mid] sae go to left wala part
     else{
        end = mid - 1;
     }
     mid = start + ((end - start)/2); //integer overflow na ho es liye easa likha  //   mid = ((start+end)/2);  //updation
    }
    return -1;
}
int main(){
    int even [6] ={2,4,5,6,8,12};
    int odd [7] = {5,10,15,20,25,30,35};

    int index  =  binarySearch(even,6,8);
    int index2 = binarySearch(odd,7,10);
    
    cout <<"Index of 8 is : ="<<index <<endl;
    cout <<"Index of 10 is : ="<<index2 <<endl;


    return 0;
}