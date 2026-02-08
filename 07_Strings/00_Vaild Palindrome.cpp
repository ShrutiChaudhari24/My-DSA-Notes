# include <iostream>
using namespace std;

char to_lowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isAlphaNumeric (char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

bool is_palindrome(string &s){
     string filtered = "";

    //  step 1 := filtering the string
     for(char ch : s){
     if (isAlphaNumeric(ch)){
        filtered.push_back(to_lowerCase(ch));
     }
}

    // step 2 := actually cheacking weather it is palindrome or not
    int start = 0;
    int end = filtered.length() - 1;

    while(start <= end){

         if(filtered[start] != filtered[end]){
            return false;
         }

         else{
            start++;
            end--;
         }
         return true;
    }
}

int main(){
    string s;
    cout << "Enter a string := " << endl;
    cin >> s;

    bool ans = is_palindrome(s);

    cout << ans;
    return 0;
}