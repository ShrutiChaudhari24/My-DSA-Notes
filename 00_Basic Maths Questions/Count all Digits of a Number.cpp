# include <iostream>
using namespace std;

int noOfDigits (int n){
    int count = 0;

    // edge case
    if(n == 0){
        count = 1;
    }

    while (n != 0){
        n = n / 10;
        count ++;  
    }
    return count; 
}

int main(){
    int n;
    cout << "Enter the value of n := " ;
    cin >> n;

    int count;
    count = noOfDigits (n) ;
    cout << "The number of digits in " << n << " is := " << count;

    return 0;
}