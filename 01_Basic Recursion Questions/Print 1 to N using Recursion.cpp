# include <iostream>
using namespace std;

void print_numbers (int n, int i){
    

    if (i>n){
        return ;
    }

    cout << i << endl;
    print_numbers(n,++i);
}

int main(){
    print_numbers(5,1);
    return 0;
}