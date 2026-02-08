# include <bits/stdc++.h>
using namespace std;

vector <int> unionArr (vector <int>& a, vector <int>& b, int n1, int n2){
    vector <int> unionArr;
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2){
        if (a[i] <= b[j]){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
            else{
                if(unionArr.size() == 0 || unionArr.back() != b[j]){
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }

        // if 1st array gets exhusted and second is remaining
        while (j < n2){
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }

        // if 2nd array gets exhusted and first is remaining
        while (i < n1){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }

        return unionArr;
    }

int main(){
    vector <int> a = {1, 1, 2, 3, 4, 5, 8, 10};
    vector <int> b = {1, 2, 3, 4, 5, 6, 7, 9};

    int n1 = a.size();
    int n2 = b.size();

    vector <int> ans = unionArr(a, b, n1, n2);  

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}
