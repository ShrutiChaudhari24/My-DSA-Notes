# include <iostream>
using namespace std;

int main(){
    int n ;
    cout << "Enter a number you want to check weather it is palindrome or not :=  ";
    cin >> n;

    // edge case 
    if (n < 0){
        cout << "Number is not a palindrome ";
        return 0;
    }

    int temp = n;


    int rev_of_n = 0;

    while (n != 0){
        int digit = n % 10;
        rev_of_n = rev_of_n * 10 + digit ; 
        n = n / 10; // updation    
    }

    if (temp == rev_of_n){
        cout << "The number is palindrome ";
    }
    else {
        cout << "The number is not a palindrome";
    }

    return 0;
}