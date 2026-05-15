# include <bits/stdc++.h>
using namespace std;

// brute force approch TC := O(N square) space complexity O(N)
vector <int> nextGreaterElement1(vector <int> &arr, int n){
    vector <int> ans;
    for(int i = 0; i < n; i++){
        bool found = false;

        for(int j = i+1; j < n; j++){
            if(arr[j] > arr[i]){
                ans.push_back(arr[j]);
                found =  true;
                break;
            }
        }
        if(!found){
            ans.push_back(-1);
        }
    }
    return ans;
}

// better approch using stack (monotonic stack ie stack storing the elements in particular order only in increasing or decreasing order)
// here we are storing the elements in stack only in decreasing order
vector <int> nextGreaterElement2(vector <int> &arr, int n){ // TC := O(2N) SC := O(2N)
    vector <int> nge(n); // this is our ans array ie the array storing the next greater elements
    stack <int> st;

    for(int i = n-1; i >= 0; i--){
        
        // this loop will only run if this condition meets else it won't run 
        while(!st.empty() && st.top() <= arr[i]){ // matlab stack empty nahi hai aur jo top wala element hai vo chota hai arr[i] sae tho hi pop karo
            st.pop();
        }

        // if the stack is empty or gets empty now because all the elements are smaller now
        if(st.empty()){
            nge[i] = -1;
        }else{
            nge[i] = st.top();
        }

        st.push(arr[i]);
        
    }
    
    return nge;
}

int main(){
    int n;
    cin >> n;

    vector <int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // vector <int> ans = nextGreaterElement1(arr, n);
    vector <int> ans = nextGreaterElement2(arr, n);

    for(auto it: ans){
        cout << it << " ";
    }

    return 0;
}