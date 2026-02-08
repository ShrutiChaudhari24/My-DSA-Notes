# include <iostream>
using namespace std;

int revrese_Number (int n){
    int rev_no = 0;

    while (n != 0){
        int digit = n % 10;

        rev_no = rev_no * 10 + digit;
        
        n = n / 10;

    }
    return rev_no;

}
int main (){
    int n;

    cout << "Enter a number you want to reverse := " ;
    cin >> n;

    int reverse_no = revrese_Number (n);

    cout << "Reverse number of original number is := " << reverse_no ;
}