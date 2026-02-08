# include <bits/stdc++.h>
using namespace std;

 string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        // step 1 := reverse entire string so that each word will be in its correct position
        reverse(s.begin(),s.end());

        // step 2 := find individual word and bring them in its correct for by again reverseing 
        for(int i = 0; i < n; i++){
            string word = "";

            while(i < n && s[i] != ' '){
                word = word + s[i];
                i++;
            }
            reverse(word.begin(),word.end());

            if(word.length() > 0){
                ans = ans +" "+word;
            }
        }
        if(ans.size() == 0) return "";
        return ans.substr(1);
    }

int main(){
    string s;
    getline(cin,s);

    string ans = reverseWords(s);

    cout << ans;
    return 0;
}