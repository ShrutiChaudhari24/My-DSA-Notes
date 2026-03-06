# include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(log n)
// Because number of bits in binary representation is log₂(n)

string ConvertDecimal2Binary(int n){

    if(n == 0) return "0"; // handle zero case

    string result = "";

    while(n != 0){
        if(n % 2 == 1) {
            result = result + '1';
        }
        else{
            result = result + '0';
        }
        n = n/2;
    }
    reverse(result.begin(),result.end());
    return result;
}


int main(){
    int n;
    cin >> n;

    string binary = ConvertDecimal2Binary(n);

    cout << binary;

    return 0;
}