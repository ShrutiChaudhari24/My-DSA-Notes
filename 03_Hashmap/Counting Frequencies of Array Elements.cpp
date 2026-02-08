# include <bits/stdc++.h>
using namespace std;

void countFrequencyOfArrayElement(int* arr, int n){
    unordered_map <int, int> freqmap;

    for (int i = 0; i < n; i++){
        int element = arr[i];   

        // ager vo element already mapmae present hai tho uss ka count badha doo
        if(freqmap.find(element) != freqmap.end()){
            freqmap[element]++;
        }
        else{  //else ager nahi hai tho uss ka count phele 0 raha hoga abb badha kae 1 kar doo 
            freqmap[element] = 1;
        }
    }

    // now printing the freq of each element
    cout << "Element" << "->" << "Frequency" << endl;

    for(auto it: freqmap){
        cout << it.first << "->" << it.second << endl;
    }


}


int main(){
    int arr[] ={1, 2, 3, 2, 1, 3, 2, 2, 1, 2};
    int n = 10; 

    countFrequencyOfArrayElement(arr, n);
    return 0; 
}