# include <bits/stdc++.h>
using namespace std;

class abc{
    // if we want to change x even if it is marked as const we can do that using mutable keyword
    mutable int x; // but we will not use this keyword we will use it only when we are debugging the code
    int *y;
    const int z;


    public:
    // abc(){ // default ctor 
    //     x = 0;
    //     y = new int(0);
    // }

    int getX() const{
        return x;
    }

    void setX(int _val){
        x = _val;
    }

    int getY() const{
        return *y;
    }

    void setY(int _val){
        *y = _val;
    }

    // initialization -> it is just use to initialize the data members of the class ye vo hi kam karti hai jo kam ctor karta hai  
    abc(int _x, int _y, int _z = 0) : x(_x), y(new int (_y)), z(_z){
        cout << "in init list" << endl;
    }
};

void printABC(const abc&a){
    cout << a.getX() << " " << a.getY() << endl;
}

int main(){

    //1) const keyword
    //const int x = 10;
    // x = 4; // expression must be a modifiable lvalue // error: assignment of read-only variable 'x'
    // ivalue -> variables having memory location
    // rvalue -> variables don't have memory location

    // this is one way to change the const value but not applicable in mordern cpp
    /*
    int *p = &x;
    *p = 10;
    cout << x << endl;
    */

    //2) const with pointers 
   // const int *a = new int(2); // const data, non-const pointer
    //cout << *a << endl;
    // *a = 20; // can't change the content of pointer
    // cout << *a << endl;

    // int b = 5;
    // a = &b; // pointer itself can be reassigned
    // cout << *a << endl;

    // const pointer, but non const data
    /*
    int *const a = new int(2); 
    *a = 20; // chal jayega
    cout << *a << endl;
    int b = 50;
    a =  &b; // nahi chelega, const pointer
    */

    // const pointer, const data
    /*
    const int *const a = new int(10);
    cout << *a << endl;
    *a = 50;
    int b = 100;
    a = &b;
    */


    abc a(1,2);
    cout << a.getX() << endl;
    cout << a.getY() <<endl;

    return 0;
}