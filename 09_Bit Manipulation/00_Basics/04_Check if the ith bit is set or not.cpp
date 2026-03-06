# include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int i; //ith bit which we want to check weather it is set or not
    cin >> i;

    // using left shift operator
    if(N & (1 << i) != 0 ){ // ager not equal to 0 hai tho bit is set
        cout << "true";
    }else{
        cout << "false";
    }

    // using right shift operator
    if((N >> i) & 1 == 0){  // ager equal to 0 hai tho bit is not set 
        cout << "false";
    }else{
        cout << "true";
    }

    return 0;
}