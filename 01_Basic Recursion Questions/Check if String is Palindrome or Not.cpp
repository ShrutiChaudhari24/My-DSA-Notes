# include <iostream>
using namespace std;
	
bool palindromeCheck(int i,string& s){
	// base case
    int n = s.size();
    if(i >= n/2){
         return true;
    }

    if(s[i] != s[n-i-1]){
        return false;
    }
    palindromeCheck(i+1, s);
    }		
       
        int main(){
            string s = "abababa";
            bool result = palindromeCheck (0, s);

            if(result){
                cout << "String is palindrome";
            }
            else{
                cout << "String is not palindrome";
            }
            return 0;
        }