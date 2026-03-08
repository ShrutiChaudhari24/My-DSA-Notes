# include <bits/stdc++.h>
using namespace std;

bool isVowel (char ch){
    return (ch == 'a'|| ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int maxVowel(string s, int k){
    int n = s.length();
    int vowelCount = 0;

    // for 1st window
    for(int i = 0; i < k; i++){
        if(isVowel(s[i])){
            vowelCount++;
        }
    }

    int maxVowelCount = vowelCount;

    // sliding window
    for(int i = k; i < n; i++){

        if(isVowel(s[i])) vowelCount++; // add new element
        if(isVowel(s[i-k])) vowelCount--; // remove old element

        maxVowelCount = max(maxVowelCount, vowelCount);
    }
    return maxVowelCount;
}

int main(){
    string s;
    getline(cin,s);

    int k;
    cin >> k;


    int maxVowelCount = maxVowel(s, k);

    cout << maxVowelCount << endl;
    return 0;
}