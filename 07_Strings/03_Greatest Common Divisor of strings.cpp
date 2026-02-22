# include <bits/stdc++.h>
using namespace std;

string gcd_Of_strings(string str1, string str2){
    int n = str1.length();
    int m = str2.length();

    if(str1+str2 != str2+str1) {
        return "";  // stright away return "" because if they are not equal this means their is not any string which divides both the strings completely  
    }

    // we have to find the gcd means sring with highest length which is divisor of both the strings completely so find the gcd of length
    while(n != m){
            if(n > m){
            n = n-m;
            }
            else{
                m = m-n;
            }
    }

    // here both becomes equal so we can say that 
    int len = n ; // or m

    return str1.substr(0,len);  // or return str2.substr(0,len);
}

int main(){

    string str1;
    string str2;

    getline(cin, str1);
    getline(cin, str2);

    string ans = gcd_Of_strings(str1, str2);

    cout << ans;

    return 0;
}