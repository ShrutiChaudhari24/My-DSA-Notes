# include <bits/stdc++.h>
using namespace std;

void MoveZerosAtEnd1(vector <int> & arr, int n){
    // brute forcte approch
    vector <int> temp ;

    // step 1 :- sare non zeros elements ko temp mae store kar lo
    for (int i = 0; i < n; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    } 

    // step 2:- take all elements from temp and put in front of the array
    for(int i = 0; i < temp.size(); i++){
        arr[i] = temp[i];
    }

    // step 3:- fill all the remaining values with zeros
    int nonzero = temp.size();
    for(int i = nonzero; i < n; i++){
        arr[i] = 0;
    }
}

void MoveZerosAtEnd2(vector <int> & arr, int n){
    // optimal approch 2 pointer approch := iterate into the same array

    int j = -1; 

    // step1 := j will start from that index jaha 0 hoga first time 
    for (int i = 0; i < n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    } 

    // step 2 := humey 0 jaha hai vo index mila tho j ki value -1 sae change ho kae i ho gayi
    for(int i = j+1; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }

}

void print (vector <int>& nums, int n){
     for (int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }cout << endl;
}

int main(){

    vector <int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = arr.size();

     print(arr, n);
    // MoveZerosAtEnd1(arr, n);
    // print(arr,n);
   
    MoveZerosAtEnd2(arr, n);
    print(arr, n);

    return 0;
}