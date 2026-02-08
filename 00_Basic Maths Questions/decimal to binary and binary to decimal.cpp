# include <bits/stdc++.h>
using namespace std;

int decimal_to_binary(int n){                                
    int ans = 0;
    int pow = 1;

    while(n > 0){
        int rem = n % 2;
        n = n / 2;

        ans = ans + (rem * pow);
        pow = pow * 10;
    }
    return ans;
}

// best approch
string decimal_to_binary1(int n){
    
    if(n == 0){
        return "0";
    }

    string ans = "";

    while(n > 0){
       ans = char('0' + (n % 2)) + ans;
       n = n/2;
    }
    return ans;
}

int binary_to_decimal (int n){
    long long ans = 0;
    long long pow = 1;

    while(n > 0){
        int rem = n % 10;
        ans = ans + (rem * pow);
        n = n / 10;
        pow = pow * 2;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    int ans = decimal_to_binary(n);
    cout << ans;
    cout << endl;
    string ans2 = decimal_to_binary1(n);;
    cout << ans2;

    cout << endl;

    int num;
    cin >> num;
    int ans3 = binary_to_decimal (n);
    cout << ans3;

    return 0;
}