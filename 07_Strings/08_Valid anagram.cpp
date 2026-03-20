# include <bits/stdc++.h>
using namespace std;

bool isValidAnagram (string s, string t){
    int n = s.length();
    int m = t.length(); 

    if(s.length() != t.length()) return false;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    
    /*int i = 0;
    while(i < n){
        if(s[i] == t[i]){
            i++;
        }else{
            return false;
        }    
    }
    return true;*/

    return s == t; // directly return this because we have already sorted
}

int main(){
    string s;
    getline(cin, s);

    string t;
    getline(cin,t);

    bool ans = isValidAnagram (s,t);

    cout << (ans ? "true" : "false");

    return 0;
}