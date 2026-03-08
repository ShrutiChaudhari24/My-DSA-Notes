# include <bits/stdc++.h>
using namespace std;
    
bool isVowel(char ch){
    if(ch =='a'||ch =='e'||ch =='i'||ch =='o'||ch =='u'||ch =='A'||ch =='E'||ch =='I'||ch =='O'||ch =='U'){
        return true;
    }else{
            return false;
    }
}

string reverseVowels(string &s) {
int n  = s.length();
int start = 0;
int end = n - 1;

while(start < end){
	if(isVowel(s[start] && isVowel(s[end]))){
		swap(s[start],s[end]);
		start++;
		end--;
	}
	else if(!isVowel(s[start])){
		start++;
	}
	else if(!isVowel(s[end])){
		end--;
	}
	else{
		start++;
		end--;
	}
	}
	return s;
}

int main(){
    string s;
    getline(cin, s);

    reverseVowels(s);

    cout << reverseVowels(s);

    return 0;
}