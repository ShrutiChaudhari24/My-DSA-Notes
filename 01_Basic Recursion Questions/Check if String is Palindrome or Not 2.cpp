# include <iostream>
using namespace std;
	
bool palindromeCheck(int start,int end,string& s){
	// base case
    if(start >= end){
        return true;
    }

    if(s[start] != s[end]){
        return false;
    }
    palindromeCheck(start+1,end-1, s);
    }		
       
        int main(){
            string s = "abababa";
            int start = 0;
            int end = s.size() - 1;
            bool result = palindromeCheck (start, end, s);

            if(result){
                cout << "String is palindrome";
            }
            else{
                cout << "String is not palindrome";
            }
            return 0;
        }