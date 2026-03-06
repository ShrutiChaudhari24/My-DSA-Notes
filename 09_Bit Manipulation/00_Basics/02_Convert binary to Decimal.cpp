# include <bits/stdc++.h>
using namespace std;

// TC O(length) SC := O(1)
int Convertbinary2Decimal(string s){
    int len = s.length();
    int powof2 = 1; //initially 2 to power 0 is 1
    int num = 0;

    for(int i = len-1; i >=0; i--){
        if(s[i] == '1') {
            num = num + powof2;
        }
        powof2 = powof2 * 2;  
    }
    return num;
}

int main(){
    string s;
    getline(cin,s);

    int decimal = Convertbinary2Decimal(s);

    cout << decimal;

    return 0;
}