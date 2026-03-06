#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if((N & N-1) == 0){
        cout << "Yes it is power of 2" << endl;
    }
    else{
        cout << "No it is Not power of 2 " << endl;
    }

    return 0;
}