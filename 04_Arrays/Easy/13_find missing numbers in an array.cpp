# include <bits/stdc++.h>
using namespace std;

int find_Missing_Number(vector <int> arr,int N) {
    int xor1 = 0, xor2 = 0;
    int n = N-1;  // n is the number of element present in the array ie. size of array

    for (int i = 0; i < n; i++){
        // xor2 will store the xor of array elements
        xor2 = xor2 ^ arr[i];

        // xor1 will store the xor of 1 to N numbers
        xor1 = xor1 ^ (i+1);
    }

    // xor1 ka ek xor rahe gaya N kae sath tho 
    xor1 = xor1 ^ N;

    int missing_number = xor1 ^ xor2;

    return missing_number;


}
int main(){
    vector <int> arr = {1, 2, 4, 5};
    int N = 5;  // N is the number of elements hone chiye array kae ander if N = 5 ie array contain 1 to 5 numbers ie [1,2,3,4,5]

    int missing_number = find_Missing_Number(arr, N);

    cout << missing_number;
    return 0;
}
