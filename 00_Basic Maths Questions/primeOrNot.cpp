# include <iostream>
using namespace std;

bool is_prime(int n){

    // edge case
    if(n == 1){
        cout << "It is neither a prime nor a composit number";
    }

    for (int i = 2; i*i <= n; i++){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){

    int n ;
    bool prime = is_prime(5);
    cout << "Is number prime := " << prime << endl;
    prime = is_prime(6);
    cout << "Is number prime := " << prime << endl;
    prime = is_prime(99);
    cout << "Is number prime := " << prime << endl;
    prime = is_prime(1);
    cout << "Is number prime := " << prime << endl;
    return 0;
}