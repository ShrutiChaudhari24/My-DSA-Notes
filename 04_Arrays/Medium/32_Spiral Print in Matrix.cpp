# include <bits/stdc++.h>
using namespace std;
vector <int> SpiralPrint(vector <vector <int>>& matrix){
    vector <int> ans;
    int n = matrix.size();
    int m = matrix[0].size();

    int left = 0, right = m-1;
    int top = 0, bottom = n-1;

    while(left <= right && top <= bottom){
        // right to left
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        // top to bottom
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        // right to left
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // bottom to top
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    int m ;
    cin >> m;
    vector <vector <int>> matrix(n, vector <int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }cout << endl;

    vector <int> ans = SpiralPrint(matrix);

    for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
    }




    return 0;
}