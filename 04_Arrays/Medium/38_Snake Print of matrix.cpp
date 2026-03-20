# include <bits/stdc++.h>
using namespace std;

void Row_Wise_SnakePrint(vector <vector <int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            for(int j = 0; j < m; j++){
                cout << matrix[i][j] << " ";
            }
        }else{
            for(int j = m-1; j >= 0; j--){
                cout << matrix[i][j] << " ";
            }
        }
    }
}

void Col_Wise_SnakePrint(vector <vector <int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int j = 0; j < m; j++){
        if(j % 2 == 0){
            for(int i = 0; i < n; i++){
                cout << matrix[i][j] << " ";
            }
        }else{
            for(int i = n-1; i >= 0; i--){
                cout << matrix[i][j] << " ";
            }
        }
    }
}

void Advance_Row_Wise_SnakePrint(vector <vector <int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            for(int j = 0; j < m; j++){
                cout << matrix[i][j] << " ";
            }
        }else{
            for(int j = m-1; j >= 0; j--){
                cout << -matrix[i][j] << " ";
            }
        }
    }
}

void Advance_Col_Wise_SnakePrint(vector <vector <int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int j = 0; j < m; j++){
        if(j % 2 == 0){
            for(int i = 0; i < n; i++){
                cout << matrix[i][j] << " ";
            }
        }else{
            for(int i = n-1; i >= 0; i--){
                cout << -matrix[i][j] << " ";
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector <vector <int>> matrix(n, vector <int> (m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    Row_Wise_SnakePrint(matrix);
    cout << endl;
    Col_Wise_SnakePrint (matrix);
    cout << endl;
    Advance_Row_Wise_SnakePrint(matrix);
    cout << endl;
    Advance_Col_Wise_SnakePrint (matrix);


    return 0;
}