# include <bits/stdc++.h>
using namespace std;

vector <int> leadersInArray(vector <int>& arr){
    vector <int> ans;
    int n  = arr.size();

    int maxi = INT_MIN;
    for(int i = n-1; i >= 0; i++){
        
        if(arr[i] > maxi){
            maxi = arr[i];
            ans.push_back(arr[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s;
    getline(cin,s);

    vector <int> arr;

    if(s.front() == '[' && s.back() == ']'){
        s = s.substr(1, s.length()-2); 
    }

    stringstream ss(s);
    string temp;

    while(getline(ss,temp,',')){
        int num = stoi(temp);
        arr.push_back(num);
    }

    vector <int> ans = leadersInArray(arr);

    for(auto it : ans){
        cout << it << " ";
    }

    return 0;
}