# include <bits/stdc++.h>
using namespace std;

string merge_String_Alternately(string word1,string word2){
    int n = word1.length();
    int m = word2.length();
    string ans = "";
    int i = 0; //int j = 0;

    // while(i < n && j < m){
    //     ans = ans + word1[i] + word2[j];
    //     i++;
    //     j++;
    // }

    // while(i < n){
    //     ans = ans + word1[i];
    //     i++;
    // }

    // while(j < m){
    //     ans = ans + word2[j];
    //     j++;
    // }

    while(i < n || i < m){
        if(i < n) {
            ans = ans + word1[i];
        }
        if(i < m){
            ans = ans + word2[i];
        }
        i++;
    }
    return ans;

}

int main(){
    string word1;
    string word2;
    
    getline(cin,word1);  // ab
    getline(cin,word2);  // pqrs

    string ans = merge_String_Alternately(word1, word2);

    cout << ans;   // apbqrs
    return 0;
}