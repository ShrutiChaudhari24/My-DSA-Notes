# include <bits/stdc++.h>
using namespace std;

int trap(vector <int>& heightArr, int n){
    int l_max = 0, r_max = 0 , total = 0;
    int l = 0; int r = n-1;

    while(l < r){
        if(heightArr[l] <= heightArr[r]){
            if(l_max  > heightArr[l]){
                total += l_max - heightArr[l];
            }else{
                l_max = heightArr[l];
            }
        l = l + 1;
        }
        else{
            if(r_max  > heightArr[r]){
                total += r_max - heightArr[r];
            }else{
                r_max = heightArr[r];
            }
        r = r - 1;
        }
    }
    return total;
}

int main(){
    int n;
    cin >> n;
    
    vector <int> heightArr(n);

    for(int i = 0; i < n; i++){
        cin >> heightArr[i] ;
    }

    int totalWater = trap(heightArr, n);

    cout << totalWater << endl;

    return 0;
}