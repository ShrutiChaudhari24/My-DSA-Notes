// Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that 
// each unique element appears only once.
# include <bits/stdc++.h>
using namespace std;

// this is the brute force approch
// int removeDuplicates (vector <int>& nums, int n){
//     set <int> st;

//     // humey pata hai ki set hamesha sorted order mae unique elements ko store karta hai tho phele array mae jo elements hai vo set mae dal datae hai 
//     for(int i = 0; i < n; i++){
//         st.insert(nums[i]);
//     }

//     // abb kya jo elements dalae thae vo humet pata hai unique elements hai tho jitne elements set mae hai un lo count kar latae hai
//     // matalb phele ek variable index 0 sae initialize karlatae hai 
//     // uss set pae iterate karte hai aur array mae elements daltae jate hai jo array ka size koga vo hi number of unique elements honge

//     int index = 0;
//     for (auto it : st){
//         nums[index] = it;
//         index++;
//     }
//     return (index + 1);  // because array index start from 0 tho 
// }  

// optimal approch using 2 pointer approch

int removeDuplicates(vector<int>& arr, int n) {
        int i = 0;

        for(int j = 1; j < n; j++){
            if(arr[i] != arr[j]){
                arr[i+1] = arr[j];
                i++;
            }
        }
        return i+1;
    }


int main(){

    vector <int> nums = {1, 1, 2, 2, 2, 3, 3};
    int n = nums.size();

    int numberOfUniqueElements = removeDuplicates (nums, n);
    cout << "There are total " << numberOfUniqueElements << " unique elements in the array "<<endl;
    return 0;
}