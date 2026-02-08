#include <bits/stdc++.h>
using namespace std;

int MaximumSubArraySum(vector<int>& arr, int n) {
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0, ansStart = 0, ansEnd = 0;

    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i;

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    cout << "Maximum Subarray Sum: " << maxi << endl;
    cout << "Subarray: ";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return maxi;
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = arr.size();

    MaximumSubArraySum(arr, n);
    return 0;
}
