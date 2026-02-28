# include <bits/stdc++.h>
using namespace std;
bool isSubsequence(string s,string t){
    int n = s.length();
    int m = t.length();

    int i = 0, j = 0;

    while(i < n && j < m){
        if(s[i] == t[j]){
            i++;
            j++;
        }else{
            j++;
        }
    }

    if(i == n) return true;
    else return false;
}
int main(){
    string s;
    getline(cin,s);

    string t;
    getline(cin,t);

    bool ans = isSubsequence(s,t);
    cout << ans << endl;

    return 0;
}