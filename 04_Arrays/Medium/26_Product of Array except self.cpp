# include <bits/stdc++.h>
using namespace std;

vector <int> Product_of_array_except_self(vector <int> &arr){ // TC := O(3N) => O(N) and SC O(N)
    int n = arr.size();
    vector <int> ans(n);
    vector <int> prefix(n);
    vector <int> suffix(n);

    // calculating prefix
    prefix[0] = 1;
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] * arr[i-1];
    }

    // calculating suffix
    suffix[n-1] = 1;
    for(int i = n-2; i >=0; i--){
        suffix[i] = suffix[i+1] * arr[i+1];
    }

    // finally ans = prefix * suffix
    for(int i = 0; i < n; i++){
        ans[i] = prefix[i] * suffix[i]; 
    }
    return ans;
}

vector <int> Product_of_array_except_self2(vector <int> &arr){ // TC := O(3N) => O(N) and SC O(1)
    int n = arr.size();
    vector <int> ans(n);
    // vector <int> prefix(n);
    // vector <int> suffix(n);

    ans [0] = 1; // imp

    // calculating prefix directly inside ans
   
    for(int i = 1; i < n; i++){
        ans[i] = ans[i-1] * arr[i-1];
    }

    // calculating suffix 
    int suffix = 1;
    for(int i = n-1; i >=0; i--){
        ans[i] = ans[i] * suffix;
        suffix = suffix * arr[i];
    }

    // // finally ans = prefix * suffix
    // for(int i = 0; i < n; i++){
    //     ans[i] = prefix[i] * suffix[i]; 
    // }
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

    vector <int> ans  = Product_of_array_except_self(arr);
    vector <int> ans1  = Product_of_array_except_self2(arr);


    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    for(auto it : ans1){
        cout << it << " ";
    }
    

    return 0;
}