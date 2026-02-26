# include <bits/stdc++.h>
using namespace std;
int Longest_Consecutive_Sequence(vector <int>& arr){
    int n = arr.size();

    if(n == 0) return 0;

    sort(arr.begin(),arr.end());

    int maxCount = 1;
    int count = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i-1]){
            continue; // ignore the duplicates
        }
        else if(arr[i] == arr[i-1] + 1){
            count++;
        }
        else{
            count = 1;
        }
        maxCount = max (maxCount,count);
    }
    return maxCount;
}
int main(){
    string s;
    getline(cin,s);

    vector <int> arr;

    if(s.front() == '[' && s.back() == ']'){
        s = s.substr(1,s.length()-2);
    }

    string temp;
    stringstream ss(s);

    while(getline(ss,temp,',')){
        int num = stoi(temp);
        arr.push_back(num);
    }

    int ans = Longest_Consecutive_Sequence(arr);

    cout << ans;
    
    return 0;
}