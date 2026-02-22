# include <bits/stdc++.h>
using namespace std;

vector <bool> kidsWithCandies(vector <int>& candies, int extraCandies){
    vector <bool> ans;
        int n = candies.size();

        int largest = candies[0];

        for(int i = 1; i < n; i++){
            if(largest <= candies[i]){
                largest = candies[i];
            }
        }

        int i = 0;
        while(i < n){
            if(candies[i] + extraCandies >= largest){
                ans.push_back(true);
                i++;
            }
            else{
                ans.push_back(false);
                i++;
            }
        }
        return ans;
    }

int main(){
    int size;
    cin >> size;

    int extraCandies;
    cin >> extraCandies;

    vector <int> candies(size);

    for(int i = 0; i < size; i++){
        cin >> candies[i];
    }

    vector <bool> ans = kidsWithCandies(candies, extraCandies);

    for(auto it : ans){
        if(it == true){
            cout << "true" << " ";
        }else{
            cout << "false" << " ";
        }
    }

    return 0;
}