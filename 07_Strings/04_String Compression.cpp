# include <bits/stdc++.h>
using namespace std;

vector <char> stringCompression(vector<char>& chars){
    int n = chars.size();
    int idx = 0;

    for(int i = 0; i < n; i++){
        char ch = chars[i];
        int count = 0;

        while(i < n && chars[i] == ch){
            count++;
            i++;
        }

        if(count == 1){
            chars[idx] = ch;
            idx++;
        }  
        else{
            chars[idx] = ch;
            idx++;

            string str = to_string(count);

            for(char dig: str){
                chars[idx] = dig;
                idx++; 
            }
        }
        i--;
    }
    chars.resize(idx);  // chars ko idx jitna bana denge good practice
    return chars;
}
int main(){
    string s;
    getline(cin,s);
    vector <char> chars;

    if(s.front() == '[' && s.back() == ']'){
        s = s.substr(1, s.length()-2);
    }

    stringstream ss(s);
    string temp;

    while(getline(ss,temp,',')){
    // remove quotes if present
    if(temp.front() == '"' && temp.back() == '"'){
        temp = temp.substr(1, temp.length() - 2);
    }
    char ch = temp[0];
    chars.push_back(ch);
}
    
    stringCompression(chars);

    cout << chars.size() << endl;

    for(auto it : chars){
        cout << it << " ";
    }



    return 0;
}