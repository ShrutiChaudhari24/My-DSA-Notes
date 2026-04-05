// function overloading  occurs when a class contains multiple methods sharing same name but different in argument count or argument type

# include <bits/stdc++.h>
using namespace std;

class Add{
    public:
    
    int sum(int x, int y){
    return x+y;
    }

    int sum(int x, int y, int z){
        return x+y+z;
    }

    double sum (double x, double y){
        return x+y; 
    }
};


int main(){
    int a = 5, b = 6, c = 12;
    double x = 2.3, y = 1.2;
    
    Add add;
    cout << add.sum(x,y) << endl; // hum jo argument dae denge uss hisab sae vo apne aap hi decide karlega ki kis ko call karna hai
    cout << add.sum(a,b) << endl;
    cout << add.sum(a,b,c) << endl;
    return 0;
}