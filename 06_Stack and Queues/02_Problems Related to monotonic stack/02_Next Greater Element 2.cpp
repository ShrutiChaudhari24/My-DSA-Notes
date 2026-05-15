// In this question only small twist ye hai ki 
// if you dont find nge on right,
// then continue searching circularly

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementII(vector<int>& arr, int n){

    vector<int> nge(n);

    stack<int> st;

    for(int i = 2 * n - 1; i >= 0; i--){

        while(!st.empty() && st.top() <= arr[i % n]){
            st.pop();
        }

        if(i < n){

            if(st.empty()){
                nge[i] = -1;
            }
            else{
                nge[i] = st.top();
            }
        }

        st.push(arr[i % n]);
    }

    return nge;
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> ans = nextGreaterElementII(arr, n);

    for(auto it : ans){
        cout << it << " ";
    }

    return 0;
}