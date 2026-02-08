# include <bits/stdc++.h>
using namespace std;

 bool isValid(string s) {
        int n = s.length();
        stack <char> st;

        for(int i = 0; i < n; i++){
            // step 1 := if there is opening bracket preserve it into stack
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            // step 2 := if there is closing bracket check if it is in correct order 
            else{
                if (st.empty()) return false; // ager stack empty hai matlab opening bracket ka corresponding closing bracket nahi hai es liye return false

                char ch = st.top();  // store kar liya ch mae top element
                st.pop();  // aur pop kar diya
                // order checking
                if((s[i] == ')' && ch == '(') || 
                (s[i] == '}' && ch == '{') || 
                (s[i] == ']' && ch == '[')) {
                    continue;   // ager match ho raha hai thik hai pop kar kae aage badh jao
                }else{// nahi match huya tho false return karo
                    return false;
                }
            }
        }
        return st.empty();
    }


    // easae bhi likh sakte
    bool isValidParenthesis(string s)
{   
    stack <char> st;
    for(auto it: s){
        // if opening brackets preserve them in stack
        if (it == '(' || it == '{' || it == '['){
            st.push(it);
        }
        else{
            // closing brackets 
            
            if(st.empty()) return false;

            char ch = st.top();
            st.pop();

            if((it == ')' && ch == '(')||(it == '}' && ch == '{')||(it == ']' && ch == '[')){
                continue;
            }else{
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s;
    getline(cin,s);

    bool isValid_or_Not = isValid(s);
    if(isValid_or_Not){
        cout << " it is valid parenthesis";
    }else{
        cout << " it is not valid parenthesis";
    }

    return 0;
}