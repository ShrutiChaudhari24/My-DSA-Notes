# include <iostream>
using namespace std;

int main(){
    int n1 , n2 ;
    
    cout << "Enter n1 := ";
    cin >> n1;

    cout << "Enter n2 := ";
    cin >> n2;

    while (n1 != n2){
        if (n1 > n2){
            n1 = n1 - n2; // updation 
        }
        else{
            n2 = n2 - n1; // updation
        }
    }
    cout << "The gretest common divisor is : = " << n1; // or yaha n2 bhi likh sakte thae kyoki vo dono hi equal hai
    return 0;
}