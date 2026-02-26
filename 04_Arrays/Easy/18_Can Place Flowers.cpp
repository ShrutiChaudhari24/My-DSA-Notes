#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int size, int have_to_plant){
    
    if(have_to_plant == 0) return true;

    for(int i = 0; i < size; i++){

        if(flowerbed[i] == 0){
            bool is_leftempty = (i == 0 || flowerbed[i-1] == 0);
            bool is_rightempty = (i == size-1 || flowerbed[i+1] == 0);

            if(is_leftempty && is_rightempty){
                flowerbed[i] = 1;   // plant
                have_to_plant--;    // decrease needed count
                i++;                // skip next index
            }
        }

        if(have_to_plant == 0) return true;
    }

    return false;
}

int main(){
    int size;
    cin >> size;

    vector<int> flowerbed(size);
    for(int i = 0; i < size; i++){
        cin >> flowerbed[i];
    }

    int have_to_plant;
    cin >> have_to_plant;

    bool ans = canPlaceFlowers(flowerbed, size, have_to_plant);

    cout << (ans ? "true" : "false");

    return 0;
}