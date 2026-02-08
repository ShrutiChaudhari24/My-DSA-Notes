# include <iostream>
using namespace std;


int factorial(int n){
    int fact = 1;
    if(n == 0){
        return 1;
    }

    fact = n * factorial(n-1);
    return fact;
}
int main(){

    int n ;
    cin >> n;
    int fact = factorial(n);
    cout << "Factorial of number is := " << fact << endl;

    return 0;
}