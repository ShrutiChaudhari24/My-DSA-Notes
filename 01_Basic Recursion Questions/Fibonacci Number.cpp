# include <iostream>
using namespace std;

int Fibonacci_Number(int n){
    // base case 
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }

    int ans = Fibonacci_Number(n-1) + Fibonacci_Number(n-2);
    return ans;
}

int main(){

    int n;
    cout << "Enter the value of n you want which number of Fibonacci series := ";
    cin >> n;

    int ans = Fibonacci_Number(n);
    cout << ans;

    return 0;
}