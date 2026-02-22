#include <bits/stdc++.h> 
using namespace std;
string convertString(string str) {
    if (str.length() == 0) return "";

    str[0] = toupper(str[0]);   // First character uppercase

    int i = 1;
    while(i < str.length()){
        if(str[i-1] == ' '){    // If previous character is space
            str[i] = toupper(str[i]);  // Make current uppercase
        }
        i++;
    }
    return str;
}

int main() {
    string str;
    getline(cin, str);
    
    cout << convertString(str);
    return 0;
}