// In interviews there are basically three types problems
/*
1st type -> Given the row and col, tell the element at that place eg- R = 5, C=3  ans = 6 
2nd type -> Print any Nth row of pascal triangle eg- N = 5 O/p := 1 4 6 4 1
3rd type -> Given N, Print the entire triangle eg - N = 6 O/p : = 
                                                             1
                                                            1 1
                                                           1 2 1
                                                          1 3 3 1
                                                         1 4 6 4 1
                                                       1 5 10 10 5 1
*/

# include <bits/stdc++.h>
using namespace std;

// type 1 :- 
// TC := O(r) SC := O(1)
long long funNcR (int n, int r){
    long long res = 1;

    for(int i = 0;  i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
} 

// type 2 :-
// TC := O(N) N := no. of row  SC := O(1)
void printRow (int n){
    long long ans = 1;
    cout << ans << " ";
    for(int i = 1; i < n; i++){
        ans = ans * (n-i);
        ans = ans / i;
        cout << ans << " ";
    } 
}

// type 3 :=Given N Print entire pascal's triangle

// brute force approch using the formula nCr
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    for (int i = 1; i <= n; i++) {

        vector<int> tempList;

        for (int j = 1; j <= i; j++) {
            tempList.push_back(funNcR(i - 1, j - 1));
        }

        ans.push_back(tempList);
    }

    return ans;
}


int main(){
    int row, col;
    cin >> row >> col;

    // soln for first type of problem
    long long res = funNcR(row-1, col-1);
    cout << "The Element at Row " << row << " and col " << col << " is " << res << endl;  

    // soln for second type of problem
    cout << "The " << row << "th row is " ;
    printRow(row);
    cout << endl;

    // soln for third type problem
    int n;
    cin >> n;
    vector<vector<int>> ans = pascalTriangle(n);

    for(auto row : ans){
        for(auto it : row){
            cout << it << " ";
        }
        cout << endl;
    }
}