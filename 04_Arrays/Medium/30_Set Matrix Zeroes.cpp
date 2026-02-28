# include <bits/stdc++.h>
using namespace std;

void markRow(vector <vector <int>>&arr, int i, int m){
    for(int j = 0; j < m; j++){
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
}
    void markCol(vector <vector <int>>&arr, int j, int n){
        for(int i = 0; i < n; i++){
            if(arr[i][j] != 0){
                arr[i][j] = -1;
            }
        }
}

void setMatrix(vector <vector <int>>&arr){
    int n = arr.size();
    int m = arr[0].size();

    for(int i = 0;  i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                markRow(arr, i, m);
                markCol(arr, j, n);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }

    
}

int main(){
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    setMatrix(arr);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}