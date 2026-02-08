# include <iostream>
using namespace std;

void printName (int n){

    // base case
    if (n == 0){
        return ;
    }

    // recursive case
    cout << "Shruti" << endl;
    printName(n-1);
} 

int main(){
    int n;

    cout << "Enter how many times you want to print your name := ";
    cin >> n;

    printName(n);

    return 0;
}