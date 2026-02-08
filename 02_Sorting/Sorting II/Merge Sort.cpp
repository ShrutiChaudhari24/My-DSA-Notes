//best, avg , worst case time complexity of merge sort is O (N log N)
// space complexity is O(N)

# include <bits/stdc++.h>
using namespace std;

void merge (vector <int>& arr, int low, int mid, int high){
    vector <int> temp;

    int left = low;  // left represent left sorted array
    int right = mid + 1;  // right represent right sorted array

    while(left <= mid && right <= high)
    if(arr[left] <= arr[right]){  //ager lefthalf wala element chota hai righthalf wale element sae tho lefthalf wale element ko dal doo temp mae
        temp.push_back(arr[left]);
        left++;
    }
    else{
        temp.push_back(arr[right]); // nahi tho right half wale element ko dal doo 
        right++;
    }

    while (left <= mid){     // ager left array wale element bahe ho 
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){    //ager right haif wale element bache ho
        temp.push_back(arr[right]);
        right++;
    }
    
    // sub ho jane kae baad temp ko original array mae copy kar lo
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }

}

void mergeSort (vector <int> &arr, int low, int high){

    // jab low high kae baraber ho jaye ya aage nikal jaye tho return kar jana
    if(low >= high){
        return ;
    }

    int mid = (low + high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);


}

void printArray (vector <int>& arr, int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    vector <int> arr = {5, 19, 4, 8, 24, 65, 71, 0, 1, 20};
    int n = arr.size();

    cout << "Array before sorting " ;
    printArray (arr, n);
    
    mergeSort (arr, 0, n-1);

    cout << "Array after sorting ";
    printArray (arr, n);

    return 0;
}