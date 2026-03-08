# include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int sum = 0;
    int highestAltitude = 0;

    for(int i = 0; i < gain.size(); i++){
        sum = sum + gain[i];
        highestAltitude = max (highestAltitude,sum);
    }
    return highestAltitude;
}

int main(){
    int n;
    vector <int> gain(n);

    for(int i = 0; i < n; i++){
        cin >> gain[i];
    }

    int highestAlt = largestAltitude(gain);

    cout << highestAlt << endl;

    return 0;
}