// You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.
// A number which completely divides another number is called it's divisor.
# include <iostream>
# include <vector>
using namespace std;
class Solutions{
    public:
    vector <int> divisor (int n){  // ye jo divisor hai ye function hai vector type ka tho ye return bhi vector hi karega
        vector <int> ans;
        for (int i = 1; i <= n; i++){
            if(n % i == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
    
};

int main(){
    int n ;

    cout << "Enter a number whose factors you want to calculate := ";
    cin >> n;

    Solutions sol; // create an object of class
    vector <int> ans = sol.divisor(n); // calling the member function

    cout << "Divisors of " << n << " are := " ;
    for (int x : ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;


}

