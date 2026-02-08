# include <iostream>
using namespace std;

int sum_of_first_N_NUmbers(int n){

    // base case
    if(n == 0){
        return 0;
    }

    int sum = n + sum_of_first_N_NUmbers(n-1); 
    return sum;
}

int main(){
    int n ;
    cin >> n;
    int sum = sum_of_first_N_NUmbers(n);
    cout << "sum of first N NUmbers is := " << sum;
    return 0;
}