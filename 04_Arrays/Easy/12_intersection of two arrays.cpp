# include <bits/stdc++.h>
using namespace std;

vector <int> intersectionOfTwoSortedArrays (vector <int> &a, vector <int> &b, int n1, int n2){
    vector <int> ans;
    int i = 0;
    int j = 0;
    
    while (i < n1 && j < n2){
        if(a[i] < b[j]){
            i++;
        }
        else if(b[j] < a[i]){
            j++;
        }
        else {  // means they both are equal
            ans.push_back(a[i]); // we can push any of them int the ans because both are equal
            i++;
            j++;
        }
    }
    return ans;
}


int main(){
    vector <int> a = {1, 1, 2, 3, 3, 4, 5, 8, 10};
    vector <int> b = {1, 2, 3, 3, 4, 5, 6, 7, 9};

    int n1 = a.size();
    int n2 = b.size();

    vector <int> ans = intersectionOfTwoSortedArrays(a, b, n1, n2);  

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}
