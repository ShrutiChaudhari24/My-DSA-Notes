  # include <bits/stdc++.h>
  using namespace std;

  
  // int convertBinary(int n){
    //     int ans = 0;
    //     int pow = 1;

    //     while(n > 0){
    //         int rem = n % 2;
    //         n = n/2;
    //         ans = ans + (rem * pow);
    //         pow = pow * 10; 
    //     }
    //     return ans;
    // }

    // bool hasAlternatingBits(int n) {

    //     int binary = convertBinary(n);

    //     if(binary == 0) return false;

    //     int prev = binary % 10;
    //     binary = binary / 10;

    //     while(binary > 0){
    //         int curr = binary % 10;

    //         if(curr == prev){
    //             return false;
    //         }

    //         prev = curr;
    //         binary = binary / 10;
    //     }

    //     return true;
    // }

    bool hasAlternatingBits(int n) {
        int prev = n & 1;
    n >>= 1;

    while(n){
        int curr = n & 1;
        if(curr == prev) return false;
        prev = curr;
        n >>= 1;
    }
    return true;
    }

    int main(){
        int n;
        cin >> n;

        bool ans = hasAlternatingBits(n);
        cout << ans;
        return 0;
    }

// Example 1:
// Input: n = 5
// Output: true
// Explanation: The binary representation of 5 is: 101

// Example 2:
// Input: n = 7
// Output: false
// Explanation: The binary representation of 7 is: 111.
