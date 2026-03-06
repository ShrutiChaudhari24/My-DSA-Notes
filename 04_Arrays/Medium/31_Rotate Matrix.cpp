# include <bits/stdc++.h>
using namespace std;
vector <vector <int>> rotateMatrix(vector <vector <int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    // step 1 :- transpose the matrix 
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // step 2 :- reverse the rows 
    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    
    return matrix;
}
int main(){
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector <vector <int>> matrix (n, vector <int> (m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j] ;
        }
    }

    rotateMatrix(matrix);

    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}