# include <bits/stdc++.h>
using namespace std;

int mostFrequentElement (vector <int> & arr, int n){
    unordered_map <int, int> count; 

    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    int maxFreq = INT_MIN;
    int maxAns = INT_MAX;
    for(auto it : count){
        if(it.second > maxFreq){
            maxFreq = it.second;
            maxAns = it.first;
        }
        else if (it.second == maxFreq  && it.first < maxAns){
            maxAns = it.first;
        }
    }
    return maxAns;

}

int main(){
    int n;
    cout << "Enter the size of array := " ;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
}

    int maxAns =  mostFrequentElement (arr, n);

    cout << "Highest Occurring Element in an array is := " << maxAns << endl;

    return 0; 
}