# include <bits/stdc++.h>
using namespace std;

int Sum_of_Subarray_Minimums1(vector <int> arr, int n){
        int MOD = 1e9 + 7;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            int mini = arr[i];

            for(int j = i; j < n; j++) {
                mini = std::min(mini, arr[j]);
                sum = (sum + mini) % MOD;
            }
        }

    return sum;
}

// Next Smaller Element
    vector<int> findNSE(vector<int>& arr, int n) {
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }

    // Previous Smaller or Equal Element
    vector<int> findPSEE(vector<int>& arr, int n) {
        vector<int> psee(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return psee;
    } 

int Sum_of_Subarray_Minimums2(vector <int> arr, int n){
        int MOD = 1e9 + 7;

        vector<int> nse = findNSE(arr, n);
        vector<int> psee = findPSEE(arr, n);

        long long total = 0;

        for(int i = 0; i < n; i++) {

            long long left = i - psee[i];
            long long right = nse[i] - i;

            total = (total + (left * right * arr[i]) % MOD) % MOD;
        }

        return total;
}

int main(){
    int n;
    cin >> n;
    
    vector <int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i] ;
    }

    int sum1 = Sum_of_Subarray_Minimums1(arr, n);
    int sum2 = Sum_of_Subarray_Minimums2(arr, n);

    cout << sum1 <<" "<< sum2 << endl;

    return 0;
}