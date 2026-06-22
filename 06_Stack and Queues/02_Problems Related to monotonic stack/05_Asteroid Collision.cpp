# include <bits/stdc++.h>
using namespace std;

vector <int> asteroids_Collision(vector <int>& asteroids,int n){
    vector <int> st;

    for(int i = 0; i < n; i++){
        if(asteroids[i] > 0){
            st.push_back(asteroids[i]);
        }
        else{
            while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){
                st.pop_back();
            }

            if(!st.empty() && st.back() == abs(asteroids[i])){
                st.pop_back();
            }else if(st.empty() || st.back() < 0){
                st.push_back(asteroids[i]);
            }
        }
    }
    return st;
}

int main(){
    int n;
    cin >> n;
    vector <int> asteroids(n);

    for(int i = 0; i < n; i++){
        cin >> asteroids[i];
    }

    vector <int> ans = asteroids_Collision(asteroids, n);

    for(auto it : ans){
        cout << it << " ";
    }

    return 0;
}