# include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v = {3, 4, 1, 2};
    sort(v.begin(), v.end());

    for(auto i : v){
        cout << i << endl;
    }
}