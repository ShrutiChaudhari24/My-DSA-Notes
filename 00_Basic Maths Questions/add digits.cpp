# include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Enter a number := ";
    int num;
    cin >> num;
    int sum;

    while(num >= 10){
        int sum = 0;

        while(num > 0){
            int digit = num % 10;
            sum = sum + digit;
            num = num / 10;
        }
        num = sum;
    }

    cout << "The sum is := " << num; 
    return 0;
}